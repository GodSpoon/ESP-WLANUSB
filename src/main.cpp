#include <Arduino.h>
#include <USB.h>
#include <USBMSC.h>
#include "smb_client.h"
#include <WiFi.h>
#include <WiFiClient.h>
#include "fileserver.h"
#include "smb_config.h"
#include "smb_client.h"

// USB Mass Storage Class (MSC) object
USBMSC msc;

// SMB Client instance
SMBClient smbClient;

// Virtual disk storage (streamed to SMB)
#define VIRTUAL_DISK_SIZE (8ULL * 1024 * 1024 * 1024)  // 8GB virtual disk
#define SECTOR_SIZE 512

// File tracking for SMB copy
unsigned long lastCopyCheck = 0;
bool copyInProgress = false;
bool smbConnected = false;

uint32_t lastRead = 0;
uint32_t lastWrite = 0;

// SMB copy function declaration
void checkAndCopyNewFiles();
bool copyFileToSMB(const char* filename);
void updateStatusLED(int status); // 0=idle, 1=copying, 2=success, 3=error

// Write callback: stream sector data directly to SMB share
static int32_t onWrite(uint32_t lba, uint32_t offset, uint8_t *buffer, uint32_t bufsize) {
  if (!smbConnected || !smbClient.isConnected()) {
    Serial.println("SMB not connected, cannot write");
    return -1;
  }
  // Write buffer to SMB share at the correct offset
  bool success = smbClient.writeSector(lba, offset, buffer, bufsize);
  lastWrite = millis();
  yield();
  return success ? bufsize : -1;
}

// Read callback: stream sector data directly from SMB share
static int32_t onRead(uint32_t lba, uint32_t offset, void *buffer, uint32_t bufsize) {
  if (!smbConnected || !smbClient.isConnected()) {
    Serial.println("SMB not connected, cannot read");
    memset(buffer, 0, bufsize);
    return bufsize;
  }
  bool success = smbClient.readSector(lba, offset, (uint8_t*)buffer, bufsize);
  lastRead = millis();
  yield();
  return success ? bufsize : 0;
}

static bool onStartStop(uint8_t power_condition, bool start, bool load_eject) {
  Serial.printf("Start/Stop power: %u, start: %d, eject: %d\n", power_condition, start, load_eject);
  return true;
}

static void usbEventCallback(void *arg, esp_event_base_t event_base, int32_t event_id, void *event_data) {
  if (event_base == ARDUINO_USB_EVENTS) {
    arduino_usb_event_data_t *data = (arduino_usb_event_data_t *)event_data;
    switch (event_id) {
      case ARDUINO_USB_STARTED_EVENT: 
        Serial.println("USB PLUGGED"); 
        break;
      case ARDUINO_USB_STOPPED_EVENT: 
        Serial.println("USB UNPLUGGED"); 
        break;
      case ARDUINO_USB_SUSPEND_EVENT: 
        Serial.printf("USB SUSPENDED: remote_wakeup_en: %u\n", data->suspend.remote_wakeup_en); 
        break;
      case ARDUINO_USB_RESUME_EVENT:  
        Serial.println("USB RESUMED");
        break;
      default: break;
    }
  }
}

void setup() {
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  Serial.println("Starting SMB-enabled USB Drive");
  while(!Serial && millis() < 5000);

  // Initialize status LED
  pinMode(COPY_STATUS_LED, OUTPUT);
  updateStatusLED(0); // Idle

  // No local storage initialization needed
  Serial.println("Initializing MSC (streaming to SMB)");
  // Initialize USB metadata and callbacks for MSC (Mass Storage Class)
  msc.vendorID("ESP32");
  msc.productID("SMB_USB");
  msc.productRevision("1.0");
  msc.onRead(onRead);
  msc.onWrite(onWrite);
  msc.onStartStop(onStartStop);
  msc.mediaPresent(true);
  msc.begin(VIRTUAL_DISK_SIZE / SECTOR_SIZE, SECTOR_SIZE);

  Serial.println("Initializing USB");
  USB.begin();
  USB.onEvent(usbEventCallback);

  Serial.printf("Virtual disk size: %llu sectors of %d bytes = %llu GB\n", 
                VIRTUAL_DISK_SIZE / SECTOR_SIZE, SECTOR_SIZE, VIRTUAL_DISK_SIZE / (1024*1024*1024));

  // Initialize WiFi and web server
  initWebServer();
  
  Serial.println("SMB USB Drive ready!");
  Serial.printf("SMB Target: smb://%s/%s%s\n", SMB_SERVER_IP, SMB_SHARE_NAME, SMB_SHARE_PATH);
  Serial.println("All USB drive operations are streamed directly to SMB share");
}

void loop() {
  // Update status LED based on recent activity
  neopixelWrite(COPY_STATUS_LED,
                millis() - lastRead < 250 ? 50 : 0,
                millis() - lastWrite < 250 ? 50 : 0,
                smbConnected ? 50 : 0);

  // Handle web server
  handleServer();
  yield();

  // Check and establish SMB connection if WiFi is connected
  if (WiFi.status() == WL_CONNECTED && !smbConnected) {
    Serial.println("WiFi connected, establishing SMB connection...");
    if (smbClient.begin(SMB_SERVER_IP, SMB_SHARE_NAME, SMB_SHARE_PATH, SMB_USERNAME, SMB_PASSWORD)) {
      smbConnected = true;
      Serial.println("SMB connection established successfully");
    } else {
      Serial.println("Failed to establish SMB connection, will retry...");
      delay(5000);
    }
  }

  // Reset SMB connection status if WiFi disconnected
  if (WiFi.status() != WL_CONNECTED && smbConnected) {
    Serial.println("WiFi disconnected, closing SMB connection");
    smbClient.end();
    smbConnected = false;
  }

  delay(10);
  yield();
}

void updateStatusLED(int status) {
  switch(status) {
    case 0: // Idle
      neopixelWrite(COPY_STATUS_LED, 0, 0, 0);
      break;
    case 1: // Copying
      neopixelWrite(COPY_STATUS_LED, 255, 0, 0); // Red
      break;
    case 2: // Success
      neopixelWrite(COPY_STATUS_LED, 0, 255, 0); // Green
      delay(1000);
      neopixelWrite(COPY_STATUS_LED, 0, 0, 0);
      break;
    case 3: // Error
      neopixelWrite(COPY_STATUS_LED, 0, 0, 255); // Blue
      delay(2000);
      neopixelWrite(COPY_STATUS_LED, 0, 0, 0);
      break;
  }
}

void checkAndCopyNewFiles() {
  Serial.println("Checking for new files to copy to SMB...");
  
  // List all files in SPIFFS and check for files that should be copied
  File root = SPIFFS.open("/");
  if (!root) {
    Serial.println("Failed to open SPIFFS root directory");
    return;
  }
  
  File file = root.openNextFile();
  while (file) {
    String fileName = String(file.name());
    
    // Skip system files and the virtual disk
    if (!fileName.startsWith("/.") && fileName != "/virtual_disk.img") {
      // Check if this file should be copied
      if (fileName.endsWith(".pdf") || fileName.endsWith(".jpg") || 
          fileName.endsWith(".jpeg") || fileName.endsWith(".png") ||
          fileName.endsWith(".txt") || fileName.endsWith(".doc") ||
          fileName.endsWith(".docx")) {
        
        Serial.printf("Found file to copy: %s (%d bytes)\n", fileName.c_str(), file.size());
        
        if (copyFileToSMB(fileName.c_str())) {
          Serial.printf("Successfully copied %s to SMB share\n", fileName.c_str());
          
          // Optionally delete the file after successful copy
          if (DELETE_AFTER_COPY) {
            SPIFFS.remove(fileName);
            Serial.printf("Deleted local file: %s\n", fileName.c_str());
          }
        } else {
          Serial.printf("Failed to copy %s to SMB share\n", fileName.c_str());
        }
        
        // Only process one file at a time to avoid blocking
        file.close();
        root.close();
        return;
      }
    }
    
    file = root.openNextFile();
  }
  
  root.close();
}

bool copyFileToSMB(const char* filename) {
  if (!smbConnected || !smbClient.isConnected()) {
    Serial.println("SMB not connected, cannot copy file");
    updateStatusLED(3); // Error
    return false;
  }
  
  Serial.printf("Copying file: %s to SMB share\n", filename);
  updateStatusLED(1); // Copying
  
  copyInProgress = true;
  
  // Generate remote file path (remove leading slash and add timestamp if needed)
  String remotePath = String(filename);
  if (remotePath.startsWith("/")) {
    remotePath = remotePath.substring(1);
  }
  
  // Add timestamp to avoid overwriting files
  int dotIndex = remotePath.lastIndexOf('.');
  if (dotIndex > 0) {
    String baseName = remotePath.substring(0, dotIndex);
    String extension = remotePath.substring(dotIndex);
    remotePath = baseName + "_" + String(millis()) + extension;
  }
  
  Serial.printf("Remote path: %s\n", remotePath.c_str());
  
  bool success = smbClient.uploadFile(String(filename), remotePath, SPIFFS);
  
  copyInProgress = false;
  
  if (success) {
    updateStatusLED(2); // Success
  } else {
    updateStatusLED(3); // Error
  }
  
  return success;
}
