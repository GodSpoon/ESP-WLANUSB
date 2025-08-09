---
title: "ESP32-S3 SMB-Enabled USB Drive Implementation"
description: "Complete SMB2 implementation to automatically copy files from USB drive to network share"
tags: [esp32-s3, smb2, usb-drive, file-transfer, platformio, arduino]
languages: [cpp, c]
frameworks: [arduino-esp32, platformio]
domain: embedded
complexity: intermediate
---

# ESP32-S3 SMB-Enabled USB Drive Implementation

## Project Context
- **Hardware**: ESP32-S3 with USB OTG support
- **Goal**: Automatically copy files from connected USB drives to SMB network shares
- **Framework**: Arduino ESP32 with PlatformIO
- **Key Components**: WiFi connection, SMB2 client, USB MSC host, file management

## Architecture
```
USB Drive → ESP32-S3 (SPIFFS) → SMB2 Network Share
```

---r file reformatted into a **GitHub Copilot best-practices instruction file** under `.github/instructions/esp-wlanusb.instructions` with clean structure, minimal noise, and syntax cues so Copilot can follow it efficiently.

````markdown
# ESP32-S3 SMB-Enabled USB Drive – Completion Guide

## Overview
The ESP32-S3 project structure is correct and the main file is active.  
Goal: **Complete SMB2 implementation** to automatically copy files from USB drive to a network share.

---

## Implementation Steps

### 1. Verify WiFi and SMB Connection

Test the current SMB connection:
```bash
pio run -t upload -t monitor
```

Expected serial output:
- `WiFi connected, establishing SMB connection...`
- `SMB2: Negotiated dialect: 0x0302`
- `SMB2: User authenticated successfully`
- `SMB2: Share connected successfully`

If connection fails, test manually:
```bash
ping 10.0.0.10
smbclient -L //10.0.0.10 -U truenas_admin
```

**Configuration fix** - Update `include/smb_config.h`:
```cpp
#define SMB_USERNAME      "guest"
#define SMB_PASSWORD      ""
#define USE_GUEST_AUTH    true
```

### 2. Fix SMB2 File Operations

**File Handle Management** - Fix `src/smb_client.cpp` in `createSMB2File()`:
```cpp
if (responseSize >= SMB2_HEADER_SIZE + 88) {
    memcpy(fileId, &response[132], 16);  // Correct offset
    Serial.println("SMB2: File ID extracted successfully");
    return true;
}
```

**File Upload Implementation** - Replace `uploadFile()` in `src/smb_client.cpp`:
```cpp
bool SMBClient::uploadFile(const String& localPath, const String& remotePath, fs::FS& fileSystem) {
    if (!authenticated) { 
        Serial.println("SMB2: Not authenticated"); 
        return false; 
    }

    File file = fileSystem.open(localPath, "r");
    if (!file) { 
        Serial.printf("SMB2: Cannot open local file: %s\n", localPath.c_str()); 
        return false; 
    }

    size_t fileSize = file.size();
    Serial.printf("SMB2: Uploading file %s (%d bytes) to %s\n", 
                  localPath.c_str(), fileSize, remotePath.c_str());

    uint8_t fileId[16];
    if (!createSMB2File(remotePath, fileId)) { 
        file.close(); 
        return false; 
    }

    uint8_t buffer[4096]; 
    size_t totalUploaded = 0; 
    uint64_t offset = 0;
    
    while (file.available()) {
        size_t bytesRead = file.read(buffer, sizeof(buffer));
        if (bytesRead && !writeToSMB2File(fileId, offset, buffer, bytesRead)) {
            Serial.printf("SMB2: Write failed at offset %llu\n", offset);
            file.close(); 
            return false;
        }
        totalUploaded += bytesRead; 
        offset += bytesRead;
        
        if (totalUploaded % 65536 == 0 || totalUploaded == fileSize) {
            Serial.printf("SMB2: Progress: %d/%d bytes (%.1f%%)\n", 
                         totalUploaded, fileSize, 
                         (float)totalUploaded / fileSize * 100.0);
        }
    }
    file.close();
    return totalUploaded == fileSize;
}
```

**Virtual Disk Operations** - Replace `readSector()` and `writeSector()` in `src/smb_client.cpp`:
```cpp
bool SMBClient::readSector(uint32_t lba, uint32_t offset, uint8_t* buffer, uint32_t bufsize) {
    String path = "/virtual_disk.img";
    File vdisk = SPIFFS.open(path, "r");
    if (!vdisk) { 
        vdisk = SPIFFS.open(path, "w"); 
        vdisk.close(); 
        vdisk = SPIFFS.open(path, "r"); 
    }
    if (!vdisk) { 
        memset(buffer, 0, bufsize); 
        return true; 
    }
    vdisk.seek((uint64_t)lba * 512 + offset);
    size_t bytesRead = vdisk.read(buffer, bufsize);
    if (bytesRead < bufsize) {
        memset(&buffer[bytesRead], 0, bufsize - bytesRead);
    }
    vdisk.close(); 
    return true;
}

bool SMBClient::writeSector(uint32_t lba, uint32_t offset, uint8_t* buffer, uint32_t bufsize) {
    String path = "/virtual_disk.img";
    File vdisk = SPIFFS.open(path, "r+"); 
    if (!vdisk) vdisk = SPIFFS.open(path, "w");
    if (!vdisk) return false;
    vdisk.seek((uint64_t)lba * 512 + offset);
    size_t written = vdisk.write(buffer, bufsize);
    vdisk.close(); 
    return written == bufsize;
}
```

### 3. Implement File Detection and Copying

**Main Loop Update** - Add to `src/main.cpp` loop:
```cpp
if (smbConnected && millis() - lastCopyCheck > COPY_CHECK_INTERVAL) {
    checkAndCopyNewFiles();
    lastCopyCheck = millis();
}
```

**File Detection Function** - Replace `checkAndCopyNewFiles()` in `src/main.cpp`:
```cpp
void checkAndCopyNewFiles() {
    if (copyInProgress) return;
    
    File root = SPIFFS.open("/"); 
    if (!root) return;
    
    File file = root.openNextFile();
    while (file) {
        String name = file.name();
        
        // Skip system files
        if (name.startsWith("/.") || name == "/virtual_disk.img" || name == "/settings.json") { 
            file = root.openNextFile(); 
            continue; 
        }
        
        // Check for supported file types
        if (name.endsWith(".pdf") || name.endsWith(".jpg") || name.endsWith(".jpeg") ||
            name.endsWith(".png") || name.endsWith(".txt") || name.endsWith(".doc") || 
            name.endsWith(".docx")) {
            
            if (copyFileToSMB(name.c_str()) && DELETE_AFTER_COPY) { 
                file.close(); 
                SPIFFS.remove(name); 
            }
            root.close(); 
            return;
        }
        file = root.openNextFile();
    }
    root.close();
}
```

### 4. Testing and Validation

**Build and Flash**:
```bash
pio run -t upload
pio device monitor
```

**Testing Sequence**:
1. Verify WiFi connection (check IP in serial output)
2. Confirm SMB2 protocol negotiation
3. Test USB drive detection and mounting
4. Copy test files (PDF, images) to USB drive
5. Monitor serial output for SMB transfer progress
6. Verify files appear on network share

### 5. Common Issues and Solutions

**SMB Connection Issues**:
- Add debug logging in `negotiateProtocol()`
- Try guest authentication with empty password
- Test alternate SMB ports (445, 139)
- Check firewall settings on target server

**File Transfer Issues**:
- Verify SMB share permissions
- Debug write operations with smaller test files
- Check available SPIFFS space
- Monitor memory usage during transfers

**USB Recognition Issues**:
- Ensure USB cable supports data transfer
- Check MSC initialization logs
- Try different USB drives
- Verify USB host power supply

### 6. Production Configuration

**Required Updates**:
- Set production WiFi credentials in `include/wifi_config.h`
- Configure SMB server details in `include/smb_config.h` 
- Adjust `DELETE_AFTER_COPY` setting as needed
- Add WiFi reconnection logic for reliability
- Implement SMB reconnection on connection loss

---

## Code Patterns

When working with this codebase:
- Always check authentication state before SMB operations
- Use proper file handle cleanup with `file.close()`
- Include progress logging for long operations
- Handle SPIFFS storage limits gracefully
- Implement timeout mechanisms for network operations

---

```

This keeps it **lean, scoped, and structured** for Copilot, with:
- Clear **headings for each task**
- **Code blocks** for direct insertions/replacements
- **Minimal narrative fluff**
- **Chronological order** for guided completion

I also moved the low-level code closer to the action steps so Copilot can directly reference it when making changes.  

Do you want me to also **add YAML frontmatter and short tags** so Copilot can automatically classify this as an *ESP32 SMB2 implementation guide* when suggesting completions? That would make it even more “GitHub Copilot-native.”
```
