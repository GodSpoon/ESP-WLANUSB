/**
 * SMB Configuration for ESP32-S3 Wireless USB Disk
 * Configure your SMB share details here
 */

#ifndef SMB_CONFIG_H
#define SMB_CONFIG_H

// SMB Server Configuration
#define SMB_SERVER_IP     "10.0.0.10"           // SMB server IP address
#define SMB_SERVER_PORT   445                    // SMB port (usually 445)
#define SMB_SHARE_NAME    "media"                // Share name (without leading \\)
#define SMB_SHARE_PATH    "/scans/"              // Path within share (with leading and trailing /)

// SMB Credentials
#define SMB_USERNAME      "truenas_admin"                  // SMB username
#define SMB_PASSWORD      "Shadrach1998*"        // SMB password
#define SMB_WORKGROUP     "WORKGROUP"            // SMB workgroup/domain

// File Copy Settings
#define AUTO_COPY_ENABLED      true              // Enable automatic copying to SMB
#define DELETE_AFTER_COPY      true              // Delete files after successful copy
#define COPY_CHECK_INTERVAL    5000              // Check for new files every 5 seconds (ms)
#define MAX_FILE_SIZE         50*1024*1024       // Maximum file size to copy (50MB)
#define RETRY_ATTEMPTS         3                 // Number of retry attempts for failed operations
#define CONNECTION_TIMEOUT     10000             // SMB connection timeout in ms

// SMB Protocol Settings (SMB 2.0+ support)
#define ENABLE_SMB_SIGNING     true              // Enable SMB packet signing for security
#define USE_GUEST_AUTH         false             // Set to true for guest authentication (less secure)
#define SMB_BUFFER_SIZE        4096              // Buffer size for SMB operations (bytes)

// Status LED Configuration
#define COPY_STATUS_LED       5                  // GPIO pin for copy status LED
#define LED_COPYING_COLOR     0xFF0000           // Red while copying
#define LED_SUCCESS_COLOR     0x00FF00           // Green on success
#define LED_ERROR_COLOR       0x0000FF           // Blue on error

#endif // SMB_CONFIG_H
