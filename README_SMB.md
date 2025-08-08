# ESP32-S3 SMB-Enabled Wireless USB Drive

## Overview

This project transforms an ESP32-S3-WROOM-1-N8R2 into a wireless USB mass storage device that automatically copies files to an SMB network share. It's perfect for scan-to-network workflows where documents placed on the USB drive are automatically transferred to a file server.

## Features

- **USB Mass Storage Device**: Appears as a regular USB drive on any computer
- **WiFi Connectivity**: Pre-configured to connect to your network
- **Automatic SMB Copying**: Files placed on the drive are automatically copied to network share
- **Web Interface**: Monitor status and manage files through a built-in web server
- **Internal Storage**: Uses ESP32 internal flash (no SD card required)
- **Status LED**: Visual feedback for copy operations
- **Multiple File Types**: Supports PDF, images (JPG, PNG), documents (TXT, DOC, DOCX)

## Hardware Requirements

- ESP32-S3-WROOM-1-N8R2 development board
- USB-C cable for programming and power
- Status LED connected to GPIO pin 5 (configurable)

## Pre-configured Settings

### WiFi Configuration
- **Access Point**: "brother-usb" (password: "123456789")
- **Station Mode**: "Hail Satan" (password: "stopeatingmyface")

### SMB Target Configuration
- **Server**: 10.0.0.10
- **Share**: media/scans/
- **Username**: sam
- **Password**: Shadrach1998*
- **Full Path**: smb://10.0.0.10/media/scans/

## How It Works

1. **Connect**: Plug the ESP32 into any computer - it appears as a USB drive
2. **Place Files**: Copy/scan files to the USB drive
3. **Auto-Copy**: When WiFi is connected, files are automatically copied to the SMB share
4. **Status LED**: 
   - Green: Successful copy
   - Red: Copy in progress
   - Blue: Error occurred
5. **Cleanup**: Files are automatically deleted from USB drive after successful copy (configurable)

## Web Interface

Access the web interface at: http://192.168.4.1 (AP mode) or the assigned IP (Station mode)

- View and manage files
- Monitor SMB connection status
- Check storage usage
- Upload files directly
- Configure settings

## File Types Supported

The system automatically detects and copies these file types:
- PDF documents (`.pdf`)
- Images (`.jpg`, `.jpeg`, `.png`)
- Text files (`.txt`)
- Word documents (`.doc`, `.docx`)

## Configuration Files

### Main Configuration (`include/smb_config.h`)
```cpp
#define SMB_SERVER_IP     "10.0.0.10"
#define SMB_SHARE_NAME    "media"
#define SMB_SHARE_PATH    "/scans/"
#define SMB_USERNAME      "sam"
#define SMB_PASSWORD      "Shadrach1998*"
#define AUTO_COPY_ENABLED true
#define DELETE_AFTER_COPY true
#define COPY_CHECK_INTERVAL 5000  // 5 seconds
```

### WiFi Configuration (`include/wifi_config.h`)
```cpp
#define AP_SSID      "brother-usb"
#define AP_PASSWORD  "123456789"
#define STA_SSID     "Hail Satan"
#define STA_PASSWORD "stopeatingmyface"
```

## Building and Flashing

1. **Install PlatformIO**: Install PlatformIO IDE or CLI
2. **Clone/Download**: Get this project
3. **Build**: `pio run`
4. **Flash**: `pio run --target upload`
5. **Monitor**: `pio device monitor` (optional)

## Partition Table

The project uses a custom partition table (`min_spiffs.csv`) optimized for internal storage:
- **App**: ~1.9MB for firmware
- **SPIFFS**: ~2MB for file storage
- **System**: Standard ESP32 partitions

## Usage Examples

### Scanning Documents
1. Connect ESP32 to computer
2. Scan document directly to the USB drive
3. File automatically appears on network share at `\\10.0.0.10\media\scans\`

### File Transfer
1. Copy files to the USB drive
2. Wait for green LED (successful copy)
3. Files are now available on the network share
4. Original files are deleted from USB drive (if configured)

## API Endpoints

The device exposes a REST API:

- `GET /api/list` - List files on device
- `GET /api/disk` - Get storage info and SMB status
- `GET /api/settings` - Get current settings
- `POST /api/settings` - Update settings
- `POST /upload` - Upload files via web
- `POST /delete` - Delete files

Example `/api/disk` response:
```json
{
  "total": 2097152,
  "used": 245760,
  "free": 1851392,
  "storageType": "Internal Flash",
  "smbEnabled": true,
  "smbTarget": "smb://10.0.0.10/media/scans/",
  "smbConnected": true,
  "copyInProgress": false
}
```

## Troubleshooting

### WiFi Connection Issues
- Check WiFi credentials in `include/wifi_config.h`
- Use web interface to configure different networks
- Reset device to restore AP mode

### SMB Connection Problems
- Verify SMB server is accessible at 10.0.0.10
- Check username/password in `include/smb_config.h`
- Ensure share `media` exists with `scans` subdirectory
- Check firewall settings on SMB server

### File Copy Issues
- Verify supported file types
- Check available space on network share
- Monitor serial output for error messages
- Check SMB server logs

### USB Drive Not Recognized
- Try different USB cable
- Check computer's USB drivers
- Restart both computer and ESP32

## Serial Monitor Output

Connect at 115200 baud to see detailed logging:
```
Starting SMB-enabled USB Drive
Mounting SPIFFS...
SPIFFS Total: 2097152 bytes
SPIFFS Used: 245760 bytes
SMB USB Drive ready!
SMB Target: smb://10.0.0.10/media/scans/
WiFi connected, establishing SMB connection...
SMB connection established successfully
Found file to copy: /document.pdf (245760 bytes)
SMB: Uploading file /document.pdf (245760 bytes) to document_12345.pdf
SMB: Upload completed: document_12345.pdf (245760 bytes)
Successfully copied /document.pdf to SMB share
```

## Customization

### Change SMB Settings
Edit `include/smb_config.h` and rebuild:
```cpp
#define SMB_SERVER_IP     "your.server.ip"
#define SMB_SHARE_NAME    "your-share"
#define SMB_USERNAME      "your-username"
#define SMB_PASSWORD      "your-password"
```

### Modify File Types
Update `checkAndCopyNewFiles()` function in `src/main.cpp`:
```cpp
if (fileName.endsWith(".your-extension")) {
    // Your custom file handling
}
```

### Adjust Copy Behavior
Modify settings in `include/smb_config.h`:
```cpp
#define DELETE_AFTER_COPY      false  // Keep files after copy
#define COPY_CHECK_INTERVAL    2000   // Check every 2 seconds
#define MAX_FILE_SIZE         100*1024*1024  // 100MB limit
```

## Technical Details

### SMB Protocol
- Supports SMB 1.0/2.0 protocol
- NetBIOS session establishment
- Basic authentication
- File upload via SMB write operations

### USB MSC Implementation
- USB 2.0 Mass Storage Class (MSC)
- 512-byte sector size
- 2MB virtual disk backed by SPIFFS
- FAT filesystem emulation

### Memory Usage
- **RAM**: ~55KB (16.8% of 327KB)
- **Flash**: ~1MB (53.7% of ~2MB app partition)
- **Storage**: Up to 2MB for files (SPIFFS)

## License

This project is open source. See individual component licenses for details.

## Support

For issues or questions:
1. Check serial monitor output
2. Verify network connectivity
3. Test SMB server access manually
4. Check file permissions on network share

## Version History

- **v1.0**: Initial SMB-enabled USB drive implementation
- **v1.1**: Added web interface and status monitoring
- **v1.2**: Improved file detection and error handling
