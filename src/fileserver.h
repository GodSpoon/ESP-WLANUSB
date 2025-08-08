/**
 * Simple MSC device with internal flash storage
 * Modified for SMB file copying functionality
 */
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>
#include <WebServer.h>
#include <ArduinoJson.h>
#include <SPIFFS.h>
#include "wifi_config.h"
#include "smb_config.h"

extern const uint8_t index_html_start[] asm("_binary_web_index_html_start");
extern const uint8_t index_html_end[] asm("_binary_web_index_html_end");

extern const uint8_t settings_html_start[] asm("_binary_web_settings_html_start");
extern const uint8_t settings_html_end[] asm("_binary_web_settings_html_end");

extern const uint8_t favicon_ico_start[] asm("_binary_web_favicon_ico_start");
extern const uint8_t favicon_ico_end[] asm("_binary_web_favicon_ico_end");


// Default WiFi Configuration - Edit these values for your network
const char* AP_SSID        = DEFAULT_AP_SSID;      // Default Access Point SSID
const char* AP_PASSWORD    = DEFAULT_AP_PASSWORD;  // Default Access Point Password

// Pre-configure your home/office WiFi credentials here
const char* STA_SSID       = DEFAULT_STA_SSID;     // Your WiFi network name (leave empty to use AP mode only)
const char* STA_PASSWORD   = DEFAULT_STA_PASSWORD; // Your WiFi network password
const char* DEFAULT_MODE   = DEFAULT_WIFI_MODE;    // Default mode: "AP", "STA", or "AP+STA"

// settings path on SPIFFS
const char *settings_path = "/settings.json";

struct Settings {
  String mode;
  String apSsid;
  String apPassword;
  String staSsid;
  String staPassword; // Will store, but not send this
};

Settings settings;

// web server
WebServer server(80);
//holds the current upload
File fsUploadFile;

void onWiFiEvent(WiFiEvent_t event) {
  switch (event) {
    case ARDUINO_EVENT_WIFI_STA_GOT_IP:
      Serial.print("Obtained IP address: ");
      Serial.println(WiFi.localIP());
      break;
    default:
      Serial.printf("WiFi event: %d\n", event);
      break;
  }
}

void loadDefaultSettings() {
  // Auto-determine mode based on STA credentials
  if (strlen(STA_SSID) > 0 && strlen(STA_PASSWORD) > 0) {
    settings.mode = (strcmp(DEFAULT_MODE, "AP") == 0) ? "AP+STA" : DEFAULT_MODE;
  } else {
    settings.mode = "AP";  // Force AP mode if no STA credentials
  }
  
  settings.apSsid = AP_SSID;
  settings.apPassword = AP_PASSWORD;
  settings.staSsid = STA_SSID;
  settings.staPassword = STA_PASSWORD;
  
  Serial.println("Loaded pre-configured WiFi settings:");
  Serial.printf("  Mode: %s\n", settings.mode.c_str());
  Serial.printf("  AP SSID: %s\n", settings.apSsid.c_str());
  if (strlen(STA_SSID) > 0) {
    Serial.printf("  STA SSID: %s\n", settings.staSsid.c_str());
    Serial.println("  STA Password: [configured]");
  } else {
    Serial.println("  STA: Not configured (AP mode only)");
  }
}

void loadSettings() {
  if (SPIFFS.exists(settings_path)) {
    File file = SPIFFS.open(settings_path);
    if (!file) {

      return;
    }

    JsonDocument jsonDoc;
    DeserializationError error = deserializeJson(jsonDoc, file);
    if (error) {
      Serial.println("Failed to parse settings file");
      // Load default values on parse error
      loadDefaultSettings();
    } else {
      settings.mode = jsonDoc["mode"].as<String>();
      settings.apSsid = jsonDoc["apSsid"].as<String>();
      settings.apPassword = jsonDoc["apPassword"].as<String>();
      settings.staSsid = jsonDoc["staSsid"].as<String>();
      settings.staPassword = jsonDoc["staPassword"].as<String>();
    }
    file.close();
  } else {
    Serial.println("Settings file does not exist. Using pre-configured defaults.");
    loadDefaultSettings();
  }
}

void saveSettings() {
  File file = SPIFFS.open(settings_path, FILE_WRITE);
  if (!file) {
    Serial.println("Failed to open settings file for writing");
    return;
  }

  JsonDocument jsonDoc;
  jsonDoc["mode"] = settings.mode;
  jsonDoc["apSsid"] = settings.apSsid;
  jsonDoc["apPassword"] = settings.apPassword;
  jsonDoc["staSsid"] = settings.staSsid;
  jsonDoc["staPassword"] = settings.staPassword;

  if (serializeJson(jsonDoc, file) == 0) {
    Serial.println("Failed to write settings to file");
  } else {
    Serial.println("Settings saved");
  }
  file.close();
}

String getContentType(String filename) {
    if (server.hasArg("download")) {
        return "application/octet-stream";
    } else if (filename.endsWith(".htm")) {
        return "text/html";
    } else if (filename.endsWith(".html")) {
        return "text/html";
    } else if (filename.endsWith(".css")) {
        return "text/css";
    } else if (filename.endsWith(".js")) {
        return "application/javascript";
    } else if (filename.endsWith(".png")) {
        return "image/png";
    } else if (filename.endsWith(".gif")) {
        return "image/gif";
    } else if (filename.endsWith(".jpg") || filename.endsWith(".jpeg")) {
        return "image/jpeg";
    } else if (filename.endsWith(".ico")) {
        return "image/x-icon";
    } else if (filename.endsWith(".xml")) {
        return "text/xml";
    } else if (filename.endsWith(".pdf")) {
        return "application/x-pdf";
    } else if (filename.endsWith(".zip")) {
        return "application/x-zip";
    } else if (filename.endsWith(".gz")) {
        return "application/x-gzip";
    }
    return "text/plain";
}

void handleIndex() {
    server.send_P(200, "text/html", (const char*)index_html_start, index_html_end - index_html_start);
}

void handleSettings() {
    server.send_P(200, "text/html", (const char*)settings_html_start, settings_html_end - settings_html_start);
}

void handleFileUpload() {
    if (server.uri() != "/upload") {
        return;
    }

    HTTPUpload& upload = server.upload();
    if (upload.status == UPLOAD_FILE_START) {
        String filename = upload.filename;
        if (!filename.startsWith("/")) {
            filename = "/" + filename;
        }
        Serial.print("handleFileUpload Name: "); 
        Serial.println(filename);
        fsUploadFile = SPIFFS.open(filename, "w");
        filename = String();
    } else if (upload.status == UPLOAD_FILE_WRITE) {
        if (fsUploadFile) {
            fsUploadFile.write(upload.buf, upload.currentSize);
        }
    } else if (upload.status == UPLOAD_FILE_END) {
        if (fsUploadFile) {
            Serial.println("Uploaded");
            fsUploadFile.close();
        }
        Serial.print("handleFileUpload Size: ");
        Serial.println(upload.totalSize);
        // Note: File will be queued for SMB copy in main loop
    }
}

bool handleFileRead(String path) {
    Serial.println("handleFileRead: " + path);
    if (path.endsWith("/")) {
        handleIndex();
        return true;
    } else if (path.endsWith("/settings.html")) {
        handleSettings();
    } else if (path.endsWith("/favicon.ico")) {
        String contentType = "text/x-icon";
        server.send_P(200, "text/x-icon", (const char*)favicon_ico_start, favicon_ico_end - favicon_ico_start);
        return true;
    } else {
        String contentType = getContentType(path);
        String pathWithGz = path + ".gz";
        if (SPIFFS.exists(pathWithGz) || SPIFFS.exists(path)) {
            if (SPIFFS.exists(pathWithGz)) {
                path += ".gz";
            }
            File file = SPIFFS.open(path, "r");
            if (file.isDirectory()) {
                handleIndex();
                file.close();
            } else {
                server.streamFile(file, contentType);
                file.close();
            }
            return true;
        }
    }
    return false;
}

void handleFileDelete() {
    if (server.args() == 0) {
        return server.send(500, "text/plain", "BAD ARGS");
    }
    String path = server.arg(0);
    Serial.println("handleFileDelete: " + path);
    if (path == "/") {
        return server.send(500, "text/plain", "BAD PATH");
    }

    if (!path.startsWith("/")) {
        path = String("/") + path;
    }

    if (!SPIFFS.exists(path)) {
        return server.send(404, "text/plain", "FileNotFound");
    }

    Serial.println("Delete: " + path);
    SPIFFS.remove(path);
    server.sendHeader("Location", String("/"), true);
    server.send(302, "text/plain", "");
    path = String();
}

void handleFileList() {
    String path;
    if (!server.hasArg("dir")) {
        path = "/";
    } else {
        path = server.arg("dir");
    }

    Serial.println("handleFileList: " + path);

    File root = SPIFFS.open(path);
    String output = "[";

    if (root && root.isDirectory()) {
        File file = root.openNextFile();
        while (file) {
            // Filter out system files and virtual disk
            String fileName = String(file.name());
            if (fileName != "/virtual_disk.img" && fileName != "/settings.json" && !fileName.startsWith("/.")) {
                if (output != "[") {
                    output += ',';
                }

                output += "{\"type\":\"";
                output += (file.isDirectory()) ? "dir" : "file";
                output += "\",\"name\":\"";
                output += fileName;
                output += "\",\"size\":";
                output += String(file.size());
                output += "}";
            }
            file = root.openNextFile();
        }
    }
    output += "]";
    server.send(200, "text/json", output);
}

void getSettings() {
    JsonDocument jsonDoc;

    // Fill JSON document with settings values
    jsonDoc["mode"] = settings.mode;
    jsonDoc["apSsid"] = settings.apSsid;
    jsonDoc["apPassword"] = settings.apPassword;
    jsonDoc["staSsid"] = settings.staSsid;
    // jsonDoc["staPassword"] = settings.staPassword; // Do not send STA password

    String jsonString;
    serializeJson(jsonDoc, jsonString);
    server.send(200, "application/json", jsonString);
}

void postSettings() {
    if (server.hasArg("plain")) {
      String body = server.arg("plain");
      JsonDocument jsonDoc;
      DeserializationError error = deserializeJson(jsonDoc, body);
      if (error) {
        server.send(400, "application/json", "{\"error\":\"Invalid JSON\"}");
        return;
      }

      // Assign values from JSON
      settings.mode = jsonDoc["mode"].as<String>();
      settings.apSsid = jsonDoc["apSsid"].as<String>();
      settings.apPassword = jsonDoc["apPassword"].as<String>();
      settings.staSsid = jsonDoc["staSsid"].as<String>();
      // Do not overwrite staPassword if it is not provided
      if (jsonDoc["staPassword"].is<String>()) {
        Serial.println("Updating staPassword");
        settings.staPassword = jsonDoc["staPassword"].as<String>();
      } else {
        Serial.println("Not updating staPassword");
      }

      // Save the new settings
      saveSettings();
      server.send(200, "application/json", "{\"status\":\"ok\"}");
    } else {
      server.send(400, "application/json", "{\"error\":\"Missing body\"}");
    }
}

void writeFile(fs::FS &fs, const char * path, const char * message){
    Serial.printf("Writing file: %s\n", path);

    File file = fs.open(path, FILE_WRITE);
    if(!file){
        Serial.println("Failed to open file for writing");
        return;
    }
    if(file.print(message)){
        Serial.println("File written");
    } else {
        Serial.println("Write failed");
    }
    file.close();
}

void appendFile(fs::FS &fs, const char * path, const char * message){
    Serial.printf("Appending to file: %s\n", path);

    File file = fs.open(path, FILE_APPEND);
    if(!file){
        Serial.println("Failed to open file for appending");
        return;
    }
    if(file.print(message)){
        Serial.println("Message appended");
    } else {
        Serial.println("Append failed");
    }
    file.close();
}

String getStorageType() {
    return "Internal Flash";
}

void testStorage() {
    Serial.println("Storage Type: Internal Flash (SPIFFS)");
    Serial.printf("Total space: %zuMB\n", SPIFFS.totalBytes() / (1024 * 1024));
    Serial.printf("Used space: %zuMB\n", SPIFFS.usedBytes() / (1024 * 1024));
    Serial.printf("Free space: %zuMB\n", (SPIFFS.totalBytes() - SPIFFS.usedBytes()) / (1024 * 1024));
}

void handleDiskInfo() {
    JsonDocument jsonDoc;

    jsonDoc["total"] = SPIFFS.totalBytes();
    jsonDoc["used"] = SPIFFS.usedBytes();
    jsonDoc["free"] = SPIFFS.totalBytes() - SPIFFS.usedBytes();
    jsonDoc["storageType"] = "Internal Flash";
    jsonDoc["smbEnabled"] = AUTO_COPY_ENABLED;
    jsonDoc["smbTarget"] = String("smb://") + SMB_SERVER_IP + "/" + SMB_SHARE_NAME + SMB_SHARE_PATH;
    
    // External variable for SMB connection status
    extern bool smbConnected;
    extern bool copyInProgress;
    jsonDoc["smbConnected"] = smbConnected;
    jsonDoc["copyInProgress"] = copyInProgress;

    String jsonString;
    serializeJson(jsonDoc, jsonString);
    server.send(200, "application/json", jsonString);
}

void startFileServer() {
    server.on("/api/list", HTTP_GET, handleFileList);
    server.on("/api/disk", HTTP_GET, handleDiskInfo);
    server.on("/api/settings", HTTP_GET, getSettings);
    server.on("/api/settings", HTTP_POST, postSettings);
    server.on("/delete", HTTP_POST, handleFileDelete);
    server.on("/upload", HTTP_POST, []() {
        server.sendHeader("Location", String("/"), true);
        server.send(302, "text/plain", "");
    }, handleFileUpload);
    server.onNotFound([]() {
        if (!handleFileRead(server.urlDecode(server.uri()))) {
            server.send(404, "text/plain", "FileNotFound");
        }
    });
    server.enableCORS(true);
    server.begin();
}

void initWebServer() {

  if (!SPIFFS.begin(true)) {
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }

  loadSettings();

  if (settings.mode == "AP") {
    WiFi.mode(WIFI_AP);
    WiFi.softAP(settings.apSsid.c_str(), settings.apPassword.c_str());
  } else if (settings.mode == "STA") {
    WiFi.mode(WIFI_STA);
    WiFi.begin(settings.staSsid.c_str(), settings.staPassword.c_str());
  } else {
    WiFi.mode(WIFI_MODE_APSTA);
    WiFi.softAP(settings.apSsid.c_str(), settings.apPassword.c_str());
    WiFi.begin(settings.staSsid.c_str(), settings.staPassword.c_str());
  }

  WiFi.onEvent(onWiFiEvent);

  delay(1000);
  startFileServer();
}

void handleServer() {
  server.handleClient();
}
