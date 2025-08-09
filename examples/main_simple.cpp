#include <Arduino.h>
#include <USB.h>
#include <USBMSC.h>

USBMSC msc;

// Virtual disk storage 
#define VIRTUAL_DISK_SIZE (8ULL * 1024 * 1024 * 1024)  // 8GB virtual disk
#define SECTOR_SIZE 512

uint8_t virtualDisk[512 * 16];  // Simple 8KB virtual disk for testing

static int32_t onWrite(uint32_t lba, uint32_t offset, uint8_t *buffer, uint32_t bufsize) {
  Serial.printf("Write LBA: %u, offset: %u, size: %u\n", lba, offset, bufsize);
  
  // Simple write to virtual disk buffer
  if ((lba * SECTOR_SIZE + offset + bufsize) <= sizeof(virtualDisk)) {
    memcpy(&virtualDisk[lba * SECTOR_SIZE + offset], buffer, bufsize);
  }
  
  yield();
  return bufsize;
}

static int32_t onRead(uint32_t lba, uint32_t offset, void *buffer, uint32_t bufsize) {
  Serial.printf("Read LBA: %u, offset: %u, size: %u\n", lba, offset, bufsize);
  
  // Simple read from virtual disk buffer
  if ((lba * SECTOR_SIZE + offset + bufsize) <= sizeof(virtualDisk)) {
    memcpy(buffer, &virtualDisk[lba * SECTOR_SIZE + offset], bufsize);
  } else {
    memset(buffer, 0, bufsize);
  }
  
  yield();
  return bufsize;
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
  Serial.println("Starting Simple USB Drive Test");
  while(!Serial && millis() < 5000);

  // Initialize simple virtual disk
  memset(virtualDisk, 0, sizeof(virtualDisk));
  
  Serial.println("Initializing MSC (simple virtual disk)");
  msc.vendorID("ESP32");
  msc.productID("SimpleUSB");
  msc.productRevision("1.0");
  msc.onRead(onRead);
  msc.onWrite(onWrite);
  msc.onStartStop(onStartStop);
  msc.mediaPresent(true);
  msc.begin(VIRTUAL_DISK_SIZE / SECTOR_SIZE, SECTOR_SIZE);

  Serial.println("Initializing USB");
  USB.begin();
  USB.onEvent(usbEventCallback);

  Serial.printf("Virtual disk size: %llu sectors of %d bytes = %llu MB\n", 
                VIRTUAL_DISK_SIZE / SECTOR_SIZE, SECTOR_SIZE, VIRTUAL_DISK_SIZE / (1024*1024));

  Serial.println("Simple USB Drive ready!");
}

void loop() {
  delay(100);
  yield();
}
