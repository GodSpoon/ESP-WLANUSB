# Main Files Overview

This project contains three different main files for different functionality levels:

## Current Active Main File

**`src/main.cpp`** - Currently active main file for building
- **Purpose**: Simple USB Mass Storage Device
- **Features**:
  - Basic USB MSC (Mass Storage Class) functionality
  - 8KB virtual disk in RAM
  - Simple read/write operations
  - USB event handling
  - Serial debug output

## Alternative Main Files (in examples/ directory)

**`examples/main_simple.cpp`** - Simple version (identical to current main.cpp)
- **Purpose**: Basic USB drive functionality
- **Features**: Same as current main.cpp
- **Use case**: Testing basic USB MSC functionality

**`examples/main_complex.cpp`** - Advanced version with WiFi and SMB support
- **Purpose**: WiFi-enabled USB drive with SMB network storage
- **Features**:
  - WiFi connectivity (AP/STA/AP+STA modes)
  - Web interface for file management
  - SMB client for network storage
  - Automatic file copying to SMB share
  - Status LED indicators
  - SPIFFS integration
  - File upload via web interface
- **Use case**: Production deployment with network features

## How to Switch Between Main Files

To use a different main file:

1. **Backup current main.cpp**:
   ```bash
   mv src/main.cpp src/main_backup.cpp
   ```

2. **Copy desired main file**:
   ```bash
   # For simple version:
   cp examples/main_simple.cpp src/main.cpp
   
   # For complex version:
   cp examples/main_complex.cpp src/main.cpp
   ```

3. **Build the project**:
   ```bash
   platformio run
   ```

## Configuration Files

- **`include/wifi_config.h`** - WiFi network credentials and settings
- **`include/smb_config.h`** - SMB server configuration for network storage
- **`include/smb_client.h`** - SMB client interface definitions

## Web Interface Files

- **`web/index.html`** - Main web interface for file management
- **`web/settings.html`** - WiFi and system settings page
- **`web/favicon.ico`** - Website icon

## Error Resolution

The multiple definition errors were caused by having all three main files in the `src/` directory simultaneously. PlatformIO compiles all `.cpp` files in `src/`, leading to conflicts with:
- Multiple `setup()` function definitions
- Multiple `loop()` function definitions  
- Multiple global variable definitions (`msc`, `virtualDisk`)

**Solution**: Moved alternative main files to `examples/` directory to prevent compilation conflicts.
