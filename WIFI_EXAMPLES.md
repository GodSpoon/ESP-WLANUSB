# WiFi Configuration Examples

This file contains practical examples of how to configure your ESP32-S3 Wireless USB Disk for different scenarios.

## Example 1: Home/Office Setup (Recommended)

**Scenario**: You want the device to connect to your home WiFi but also provide a backup access point.

**Configuration** (`include/wifi_config.h`):
```cpp
#define DEFAULT_AP_SSID       "wireless-usb-disk"    
#define DEFAULT_AP_PASSWORD   "12345678"             

#define DEFAULT_STA_SSID      "MyHomeWiFi"           // Replace with your WiFi name
#define DEFAULT_STA_PASSWORD  "MyWiFiPassword"       // Replace with your WiFi password
#define DEFAULT_WIFI_MODE     "AP+STA"
```

**Result**: 
- Device connects to "MyHomeWiFi" and gets an IP (e.g., 192.168.1.100)
- Also creates "wireless-usb-disk" access point 
- Accessible from both your home network devices and direct connection
- No manual configuration needed - works immediately after flashing

---

## Example 2: Portable/Travel Setup

**Scenario**: You frequently move the device between locations and want easy access anywhere.

**Configuration** (`include/wifi_config.h`):
```cpp
#define DEFAULT_AP_SSID       "MyPortableUSB"        // Custom name
#define DEFAULT_AP_PASSWORD   "MySecurePass123"      // Custom password

#define DEFAULT_STA_SSID      ""                     // No station mode
#define DEFAULT_STA_PASSWORD  ""  
#define DEFAULT_WIFI_MODE     "AP"
```

**Result**: 
- Always creates "MyPortableUSB" access point with your custom password
- Works anywhere without needing existing WiFi
- Connect any device directly to access files

---

## Example 3: Office/Corporate Environment

**Scenario**: Connect to company WiFi only, no access point for security reasons.

**Configuration** (`include/wifi_config.h`):
```cpp
#define DEFAULT_AP_SSID       "wireless-usb-disk"    // Not used in STA mode
#define DEFAULT_AP_PASSWORD   "12345678"             // Not used in STA mode

#define DEFAULT_STA_SSID      "CorpWiFi_Guest"       // Company guest network
#define DEFAULT_STA_PASSWORD  "GuestPassword123"     
#define DEFAULT_WIFI_MODE     "STA"
```

**Result**: 
- Only connects to company WiFi
- No access point created (follows security policy)
- Access via company network IP address

---

## Example 4: Dynamic Setup

**Scenario**: Start with access point, configure WiFi later through web interface.

**Configuration** (`include/wifi_config.h`):
```cpp
#define DEFAULT_AP_SSID       "Setup-USB-Disk"       
#define DEFAULT_AP_PASSWORD   "SetupMode123"         

#define DEFAULT_STA_SSID      ""                     // Will configure later
#define DEFAULT_STA_PASSWORD  ""  
#define DEFAULT_WIFI_MODE     "AP"
```

**Setup Process**:
1. Device creates "Setup-USB-Disk" network
2. Connect to it and go to http://192.168.4.1/settings.html
3. Configure your home WiFi and change mode to "AP+STA"
4. Settings are saved permanently

---

## How to Apply Configuration

1. Edit `include/wifi_config.h` with your desired settings
2. Build and flash the firmware: `pio run -t upload`
3. The device will use your pre-configured settings immediately
4. Settings can still be changed later via the web interface

## Security Notes

- Use strong passwords (8+ characters)
- For corporate environments, consider "STA" mode only
- Default settings are stored in firmware, not on SD card
- Web-configured settings override defaults and are stored on device

## Troubleshooting

- **Can't connect to pre-configured WiFi**: Device will fall back to AP mode
- **Forgot web interface password**: Re-flash firmware to reset to defaults  
- **Need to change settings quickly**: Connect via USB and check serial monitor for current IP addresses
