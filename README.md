# ESP32-S3-WROOM-1-N8R2 Wireless USB Disk

This project implements a wireless USB disk functionality on the ESP32-S3-WROOM-1-N8R2 board. When connected to a computer via USB, the device appears as a standard USB mass storage device while simultaneously creating a WiFi access point that allows wireless access to the same files through a web interface.

## 🚀 Quick Start

1. **Configure WiFi** (optional but recommended):
   ```bash
   ./configure_wifi.sh
   ```
   Choose option 2 for home/office setup, enter your WiFi credentials.

2. **Build and Flash**:
   ```bash
   pio run -t upload
   ```

3. **Insert SD Card** and power on the device

4. **Access your files**:
   - **USB**: Device appears as removable drive
   - **WiFi**: Connect to `wireless-usb-disk` network (password: `12345678`) → http://192.168.4.1
   - **Home Network**: Check serial monitor for assigned IP address

That's it! Your wireless USB disk is ready to use.

## Features

- **USB Mass Storage Device**: Appears as a standard USB drive when connected to a computer
- **Wireless File Access**: Access the same files over WiFi through a web interface
- **Pre-configurable WiFi**: Set your WiFi credentials at compile time - no manual setup required
- **Multiple WiFi Modes**: Supports Access Point (AP), Station (STA), and AP+STA modes
- **SD Card Storage**: Uses SD card as the storage medium
- **Web-based File Management**: Upload, download, and delete files through a web interface
- **Real-time Status**: LED indicators show read/write activity
- **Automatic Network Discovery**: In AP+STA mode, accessible from both your home network and direct connection

## Hardware Requirements

- ESP32-S3-WROOM-1-N8R2 development board
- SD card (formatted as FAT32)
- Proper SD card wiring (see pin configuration below)

## Pin Configuration

The SD card should be connected using the following pins:

```
SD Card Pin | ESP32-S3 Pin
------------|-------------
CLK         | GPIO 36
CMD         | GPIO 35  
D0          | GPIO 37
D1          | GPIO 38
D2          | GPIO 33
D3          | GPIO 34
```

## Getting Started

### Prerequisites

1. PlatformIO IDE installed
2. ESP32-S3 platform support in PlatformIO

### Pre-configuring WiFi Settings

Before building, you can pre-configure WiFi settings by editing `include/wifi_config.h`:

```cpp
// For Access Point only (default)
#define DEFAULT_STA_SSID      ""                     // Leave empty for AP-only
#define DEFAULT_STA_PASSWORD  ""  
#define DEFAULT_WIFI_MODE     "AP"

// For connecting to your home WiFi + creating access point
#define DEFAULT_STA_SSID      "YourWiFiNetwork"      // Your WiFi name
#define DEFAULT_STA_PASSWORD  "YourWiFiPassword"     // Your WiFi password
#define DEFAULT_WIFI_MODE     "AP+STA"               // Both modes

// For connecting to WiFi only (no access point)  
#define DEFAULT_STA_SSID      "YourWiFiNetwork"
#define DEFAULT_STA_PASSWORD  "YourWiFiPassword"
#define DEFAULT_WIFI_MODE     "STA"                  // Station mode only
```

**WiFi Mode Options:**
- `"AP"` - Access Point only (creates wireless-usb-disk network)
- `"STA"` - Station only (connects to existing WiFi)  
- `"AP+STA"` - Both (recommended for maximum flexibility)

### Installation

1. Clone this repository
2. Open the project in PlatformIO
3. (Optional) Edit `include/wifi_config.h` to pre-configure WiFi
4. Connect your ESP32-S3-WROOM-1-N8R2 board
5. Insert a formatted SD card
6. Build and upload the firmware

### Building and Flashing

```bash
pio run -t upload
```

### Monitoring Serial Output

```bash
pio device monitor
```

## Usage

### USB Mass Storage Mode

1. Connect the ESP32-S3 to your computer via USB
2. The device will appear as a removable drive
3. Files can be read/written directly like any USB drive

### Wireless Access

1. When powered on, the device behavior depends on your WiFi configuration:
   - **AP Mode**: Creates WiFi access point named `wireless-usb-disk` (password: `12345678`)
   - **STA Mode**: Connects to your pre-configured WiFi network
   - **AP+STA Mode**: Does both - creates access point AND connects to your WiFi
2. Access the web interface:
   - **AP Mode**: Connect to `wireless-usb-disk` network, then browse to `http://192.168.4.1`
   - **STA Mode**: Find the device IP on your router, then browse to that IP
   - **AP+STA Mode**: Use either method above
3. Use the web interface to:
   - Browse files and folders
   - Upload new files  
   - Delete existing files
   - Access device settings

### Finding Device IP in STA Mode

If using STA or AP+STA mode, you can find the device IP by:
1. Checking your router's connected devices list
2. Using the serial monitor - the IP will be printed during startup  
3. Using network scanning tools like `nmap` or mobile apps

### WiFi Configuration

Access the settings page at `http://192.168.4.1/settings.html` to configure:

- **Mode**: Choose between AP, STA, or AP+STA
- **AP Settings**: Configure the access point SSID and password
- **STA Settings**: Configure connection to an existing WiFi network

## Technical Details

### Partition Scheme

The project uses a custom partition scheme (`min_spiffs.csv`) optimized for:
- OTA updates support
- SPIFFS for configuration storage
- Maximum application space

### Memory Layout

- **Flash**: 8MB total
- **PSRAM**: 2MB (QSPI)
- **Application**: ~3.2MB per OTA partition
- **SPIFFS**: ~1.7MB for configuration and web assets

### Libraries Used

- ArduinoJson (v7.1.0) - JSON handling for settings
- Built-in ESP32 libraries for USB, WiFi, and SD card functionality

## Development

### Project Structure

```
├── platformio.ini          # PlatformIO configuration
├── min_spiffs.csv          # Custom partition table
├── src/
│   ├── main.cpp            # Main application code
│   └── fileserver.h        # Web server and file handling
├── web/
│   ├── index.html          # Main web interface
│   ├── settings.html       # Settings configuration page
│   └── favicon.ico         # Web interface favicon
├── include/                # Header files
├── lib/                    # Project libraries
└── test/                   # Unit tests
```

### Customization

To modify the project for your needs:

1. **Pin Configuration**: Update the SD card pin definitions in `main.cpp`
2. **WiFi Settings**: Modify default SSID/password in `fileserver.h`
3. **Web Interface**: Customize HTML files in the `web/` directory
4. **Partition Scheme**: Adjust `min_spiffs.csv` for different memory requirements

## Troubleshooting

### Common Issues

1. **SD Card Not Detected**
   - Check wiring connections
   - Ensure SD card is formatted as FAT32
   - Verify card is properly inserted

2. **WiFi Not Working**
   - Check antenna connection
   - Verify power supply is adequate
   - Reset WiFi settings through web interface

3. **USB Not Recognized**
   - Ensure USB cable supports data transfer
   - Check device drivers on host computer
   - Verify proper power supply

### Serial Debug Output

Monitor the serial output at 115200 baud for detailed debugging information including:
- SD card mount status
- WiFi connection details
- HTTP request logs
- File operation results

## Contributing

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Test thoroughly
5. Submit a pull request

## License

This project is based on the ThingPulse Pendrive S3 example and is provided for educational and development purposes.

## Acknowledgments

- Original code by ThingPulse for the Pendrive S3
- ESP32 Arduino Core community
- PlatformIO development team
