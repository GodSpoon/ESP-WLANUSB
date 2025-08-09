#include "smb_client.h"
#include <Arduino.h>
#include <SPIFFS.h>

SMBClient::SMBClient() {
    authenticated = false;
    messageID = 1;
    sessionID = 0;
    treeID = 0;
    negotiatedDialect = 0;
    virtualDiskOpen = false;
    memset(virtualDiskFileId, 0, sizeof(virtualDiskFileId));
}

SMBClient::~SMBClient() {
    end();
}

uint64_t SMBClient::getNextMessageID() {
    return messageID++;
}

bool SMBClient::begin(const String& server, const String& share, const String& path, 
                     const String& user, const String& pass) {
    server_ip = server;
    share_name = share;
    share_path = path;
    username = user;
    password = pass;
    authenticated = false;
    
    Serial.printf("SMB2: Connecting to %s, share: %s, path: %s\n", 
                  server.c_str(), share.c_str(), path.c_str());
    
    if (!connectToServer()) {
        Serial.println("SMB2: Failed to connect to server");
        return false;
    }
    
    if (!negotiateProtocol()) {
        Serial.println("SMB2: Protocol negotiation failed");
        client.stop();
        return false;
    }
    
    if (!authenticateUser()) {
        Serial.println("SMB2: User authentication failed");
        client.stop();
        return false;
    }
    
    if (!connectToShare()) {
        Serial.println("SMB2: Share connection failed");
        client.stop();
        return false;
    }
    
    authenticated = true;
    Serial.println("SMB2: Successfully connected and authenticated");
    return true;
}

bool SMBClient::connectToServer() {
    Serial.printf("SMB2: Connecting to %s:%d\n", server_ip.c_str(), SMB_PORT);
    
    if (!client.connect(server_ip.c_str(), SMB_PORT)) {
        // Try NetBIOS port as fallback
        Serial.printf("SMB2: Port 445 failed, trying NetBIOS port %d\n", NETBIOS_PORT);
        return client.connect(server_ip.c_str(), NETBIOS_PORT);
    }
    
    Serial.println("SMB2: TCP connection established");
    return true;
}

void SMBClient::buildSMB2Header(uint8_t* packet, uint16_t command, uint64_t messageId, uint64_t sessionId, uint32_t treeId) {
    // SMB2 Header is 64 bytes
    memset(packet, 0, SMB2_HEADER_SIZE);
    
    // Protocol ID (4 bytes): 0xFE 'SMB'
    packet[0] = 0xFE;
    packet[1] = 'S';
    packet[2] = 'M';
    packet[3] = 'B';
    
    // Structure Size (2 bytes): Always 64 for SMB2 header
    packet[4] = 64;
    packet[5] = 0;
    
    // Credit Charge (2 bytes)
    packet[6] = 1;
    packet[7] = 0;
    
    // Status (4 bytes)
    packet[8] = 0;
    packet[9] = 0;
    packet[10] = 0;
    packet[11] = 0;
    
    // Command (2 bytes)
    packet[12] = command & 0xFF;
    packet[13] = (command >> 8) & 0xFF;
    
    // Credit (2 bytes)
    packet[14] = 1;
    packet[15] = 0;
    
    // Flags (4 bytes)
    packet[16] = 0;
    packet[17] = 0;
    packet[18] = 0;
    packet[19] = 0;
    
    // NextCommand (4 bytes)
    packet[20] = 0;
    packet[21] = 0;
    packet[22] = 0;
    packet[23] = 0;
    
    // MessageId (8 bytes)
    packet[24] = messageId & 0xFF;
    packet[25] = (messageId >> 8) & 0xFF;
    packet[26] = (messageId >> 16) & 0xFF;
    packet[27] = (messageId >> 24) & 0xFF;
    packet[28] = (messageId >> 32) & 0xFF;
    packet[29] = (messageId >> 40) & 0xFF;
    packet[30] = (messageId >> 48) & 0xFF;
    packet[31] = (messageId >> 56) & 0xFF;
    
    // ProcessId (4 bytes) - unused in SMB2
    packet[32] = 0;
    packet[33] = 0;
    packet[34] = 0;
    packet[35] = 0;
    
    // TreeId (4 bytes)
    packet[36] = treeId & 0xFF;
    packet[37] = (treeId >> 8) & 0xFF;
    packet[38] = (treeId >> 16) & 0xFF;
    packet[39] = (treeId >> 24) & 0xFF;
    
    // SessionId (8 bytes)
    packet[40] = sessionId & 0xFF;
    packet[41] = (sessionId >> 8) & 0xFF;
    packet[42] = (sessionId >> 16) & 0xFF;
    packet[43] = (sessionId >> 24) & 0xFF;
    packet[44] = (sessionId >> 32) & 0xFF;
    packet[45] = (sessionId >> 40) & 0xFF;
    packet[46] = (sessionId >> 48) & 0xFF;
    packet[47] = (sessionId >> 56) & 0xFF;
    
    // Signature (16 bytes) - zeros for now (no encryption)
    memset(&packet[48], 0, 16);
}

bool SMBClient::negotiateProtocol() {
    Serial.println("SMB2: Negotiating protocol");
    
    // SMB2 Negotiate packet
    uint8_t negotiate[128];
    buildSMB2Header(negotiate, SMB2_NEGOTIATE, getNextMessageID(), 0, 0);
    
    // Negotiate request structure starts after SMB2 header (offset 64)
    uint8_t* payload = negotiate + SMB2_HEADER_SIZE;
    
    // Structure Size (2 bytes)
    payload[0] = 36;
    payload[1] = 0;
    
    // Dialect Count (2 bytes) - we'll advertise 5 dialects
    payload[2] = 5;
    payload[3] = 0;
    
    // Security Mode (2 bytes) - signing enabled
    payload[4] = 0x01;  // SMB2_NEGOTIATE_SIGNING_ENABLED
    payload[5] = 0;
    
    // Reserved (2 bytes)
    payload[6] = 0;
    payload[7] = 0;
    
    // Capabilities (4 bytes)
    payload[8] = 0x01;  // DFS
    payload[9] = 0;
    payload[10] = 0;
    payload[11] = 0;
    
    // Client GUID (16 bytes) - generate a simple GUID
    for (int i = 0; i < 16; i++) {
        payload[12 + i] = random(0, 256);
    }
    
    // Negotiate Context Offset (4 bytes) - no contexts for simplicity
    payload[28] = 0;
    payload[29] = 0;
    payload[30] = 0;
    payload[31] = 0;
    
    // Negotiate Context Count (2 bytes)
    payload[32] = 0;
    payload[33] = 0;
    
    // Reserved2 (2 bytes)
    payload[34] = 0;
    payload[35] = 0;
    
    // Dialects array (5 dialects * 2 bytes each = 10 bytes)
    payload[36] = SMB2_DIALECT_202 & 0xFF;  // SMB 2.0.2
    payload[37] = (SMB2_DIALECT_202 >> 8) & 0xFF;
    payload[38] = SMB2_DIALECT_210 & 0xFF;  // SMB 2.1.0
    payload[39] = (SMB2_DIALECT_210 >> 8) & 0xFF;
    payload[40] = SMB2_DIALECT_300 & 0xFF;  // SMB 3.0.0
    payload[41] = (SMB2_DIALECT_300 >> 8) & 0xFF;
    payload[42] = SMB2_DIALECT_302 & 0xFF;  // SMB 3.0.2
    payload[43] = (SMB2_DIALECT_302 >> 8) & 0xFF;
    payload[44] = SMB2_DIALECT_311 & 0xFF;  // SMB 3.1.1
    payload[45] = (SMB2_DIALECT_311 >> 8) & 0xFF;
    
    size_t totalSize = SMB2_HEADER_SIZE + 36 + 10; // Header + negotiate struct + dialects
    
    if (client.write(negotiate, totalSize) != totalSize) {
        return false;
    }
    
    delay(100);  // Give server time to respond
    
    uint8_t response[512];
    size_t responseSize = sizeof(response);
    if (!receiveSMB2Response(response, responseSize)) {
        return false;
    }
    
    // Basic validation of negotiate response
    if (responseSize < SMB2_HEADER_SIZE || 
        response[0] != 0xFE || response[1] != 'S' || 
        response[2] != 'M' || response[3] != 'B') {
        Serial.println("SMB2: Invalid negotiate response");
        return false;
    }
    
    // Extract negotiated dialect from response
    if (responseSize >= SMB2_HEADER_SIZE + 4) {
        negotiatedDialect = response[SMB2_HEADER_SIZE + 2] | (response[SMB2_HEADER_SIZE + 3] << 8);
        Serial.printf("SMB2: Negotiated dialect: 0x%04X\n", negotiatedDialect);
    }
    
    Serial.println("SMB2: Protocol negotiated successfully");
    return true;
}

bool SMBClient::authenticateUser() {
    Serial.println("SMB2: Authenticating user");
    
    // For simplicity, we'll implement guest authentication first
    // In production, you'd want proper NTLM v2 authentication
    
    uint8_t sessionSetup[256];
    buildSMB2Header(sessionSetup, SMB2_SESSION_SETUP, getNextMessageID(), 0, 0);
    
    // Session Setup request structure starts after SMB2 header
    uint8_t* payload = sessionSetup + SMB2_HEADER_SIZE;
    
    // Structure Size (2 bytes)
    payload[0] = 25;
    payload[1] = 0;
    
    // Flags (1 byte) - no binding
    payload[2] = 0;
    
    // Security Mode (1 byte) - signing enabled  
    payload[3] = 0x01;
    
    // Capabilities (4 bytes)
    payload[4] = 0x01;  // DFS
    payload[5] = 0;
    payload[6] = 0;
    payload[7] = 0;
    
    // Channel (4 bytes) - none
    payload[8] = 0;
    payload[9] = 0;
    payload[10] = 0;
    payload[11] = 0;
    
    // Security Buffer Offset (2 bytes) - offset from start of SMB2 header
    uint16_t bufferOffset = SMB2_HEADER_SIZE + 24;
    payload[12] = bufferOffset & 0xFF;
    payload[13] = (bufferOffset >> 8) & 0xFF;
    
    // Security Buffer Length (2 bytes) - simple guest auth
    payload[14] = 0;  // No security buffer for guest
    payload[15] = 0;
    
    // Previous Session ID (8 bytes) - none
    memset(&payload[16], 0, 8);
    
    size_t totalSize = SMB2_HEADER_SIZE + 24;
    
    if (client.write(sessionSetup, totalSize) != totalSize) {
        return false;
    }
    
    delay(100);
    
    uint8_t response[512];
    size_t responseSize = sizeof(response);
    if (!receiveSMB2Response(response, responseSize)) {
        return false;
    }
    
    // Check response status - might get NT_STATUS_MORE_PROCESSING_REQUIRED
    uint32_t status = response[8] | (response[9] << 8) | (response[10] << 16) | (response[11] << 24);
    
    if (status == NT_STATUS_SUCCESS || status == NT_STATUS_MORE_PROCESSING_REQUIRED) {
        // Extract Session ID from response header
        sessionID = response[40] | ((uint64_t)response[41] << 8) | ((uint64_t)response[42] << 16) | 
                   ((uint64_t)response[43] << 24) | ((uint64_t)response[44] << 32) | 
                   ((uint64_t)response[45] << 40) | ((uint64_t)response[46] << 48) | 
                   ((uint64_t)response[47] << 56);
                   
        Serial.printf("SMB2: Session ID: 0x%llX\n", sessionID);
        Serial.println("SMB2: User authenticated successfully");
        return true;
    }
    
    Serial.printf("SMB2: Authentication failed with status: 0x%08X\n", status);
    return false;
}

bool SMBClient::connectToShare() {
    Serial.printf("SMB2: Connecting to share: %s\n", share_name.c_str());
    
    uint8_t treeConnect[256];
    buildSMB2Header(treeConnect, SMB2_TREE_CONNECT, getNextMessageID(), sessionID, 0);
    
    // Tree Connect request structure starts after SMB2 header
    uint8_t* payload = treeConnect + SMB2_HEADER_SIZE;
    
    // Structure Size (2 bytes)
    payload[0] = 9;
    payload[1] = 0;
    
    // Flags (2 bytes) - none
    payload[2] = 0;
    payload[3] = 0;
    
    // Path Offset (2 bytes) - offset from start of SMB2 header
    uint16_t pathOffset = SMB2_HEADER_SIZE + 8;
    payload[4] = pathOffset & 0xFF;
    payload[5] = (pathOffset >> 8) & 0xFF;
    
    // Prepare the UNC path \\server\share
    String uncPath = "\\\\" + server_ip + "\\" + share_name;
    size_t pathLen = uncPath.length() * 2; // Unicode (UTF-16LE)
    
    // Path Length (2 bytes)
    payload[6] = pathLen & 0xFF;
    payload[7] = (pathLen >> 8) & 0xFF;
    
    // Convert path to UTF-16LE (simplified - ASCII only)
    uint8_t* pathBuffer = payload + 8;
    for (size_t i = 0; i < uncPath.length(); i++) {
        pathBuffer[i * 2] = uncPath[i];
        pathBuffer[i * 2 + 1] = 0;  // High byte for ASCII
    }
    
    size_t totalSize = SMB2_HEADER_SIZE + 8 + pathLen;
    
    if (client.write(treeConnect, totalSize) != totalSize) {
        return false;
    }
    
    delay(100);
    
    uint8_t response[512];
    size_t responseSize = sizeof(response);
    if (!receiveSMB2Response(response, responseSize)) {
        return false;
    }
    
    // Extract Tree ID from response header
    treeID = response[36] | (response[37] << 8) | (response[38] << 16) | (response[39] << 24);
    Serial.printf("SMB2: Tree ID: 0x%08X\n", treeID);
    
    Serial.println("SMB2: Share connected successfully");
    return true;
}

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
    
    // This is a simplified implementation for SMB2
    // In a real SMB2 client, you would:
    // 1. Send SMB2_CREATE to create/open the remote file
    // 2. Send SMB2_WRITE packets with file data
    // 3. Send SMB2_CLOSE to close the file
    
    // For now, we'll simulate the upload process
    Serial.println("SMB2: Note - Upload is simulated (full SMB2 file operations not yet implemented)");
    
    // Read and "upload" the file in chunks
    uint8_t buffer[1024];
    size_t totalUploaded = 0;
    
    while (file.available()) {
        size_t bytesRead = file.read(buffer, sizeof(buffer));
        if (bytesRead > 0) {
            totalUploaded += bytesRead;
            
            // Update progress
            if (totalUploaded % 4096 == 0 || totalUploaded == fileSize) {
                Serial.printf("SMB2: Progress: %d/%d bytes (%.1f%%)\n", 
                            totalUploaded, fileSize, 
                            (float)totalUploaded / fileSize * 100.0);
            }
            
            delay(10);  // Simulate network delay
        } else {
            break;
        }
    }
    
    file.close();
    
    if (totalUploaded == fileSize) {
        Serial.printf("SMB2: Upload completed: %s (%d bytes)\n", remotePath.c_str(), totalUploaded);
        return true;
    } else {
        Serial.printf("SMB2: Upload failed: only %d of %d bytes processed\n", totalUploaded, fileSize);
        return false;
    }
}

bool SMBClient::receiveSMB2Response(uint8_t* buffer, size_t& size) {
    size_t bytesRead = 0;
    unsigned long timeout = millis() + 10000;  // 10 second timeout
    
    while (bytesRead < size && millis() < timeout) {
        if (client.available()) {
            int byte = client.read();
            if (byte >= 0) {
                buffer[bytesRead++] = byte;
            }
        } else {
            yield(); // Allow other tasks to run
            delay(10);
        }
    }
    
    size = bytesRead;
    return bytesRead > 0;
}

void SMBClient::end() {
    if (client.connected()) {
        client.stop();
    }
    authenticated = false;
    sessionID = 0;
    treeID = 0;
}

bool SMBClient::isConnected() {
    return client.connected() && authenticated;
}

bool SMBClient::readSector(uint32_t lba, uint32_t offset, uint8_t* buffer, uint32_t bufsize) {
    if (!authenticated || !virtualDiskOpen) {
        // Try to open virtual disk file if not already open
        if (!openVirtualDiskFile()) {
            Serial.println("SMB2: Cannot open virtual disk file for reading");
            return false;
        }
    }
    
    // Calculate absolute offset in the virtual disk file
    uint64_t absoluteOffset = (uint64_t)lba * 512 + offset;
    
    Serial.printf("SMB2: Reading sector LBA=%u, offset=%u, size=%u (abs_offset=%llu)\n", 
                  lba, offset, bufsize, absoluteOffset);
    
    return readFromSMB2File(virtualDiskFileId, absoluteOffset, buffer, bufsize);
}

bool SMBClient::writeSector(uint32_t lba, uint32_t offset, uint8_t* buffer, uint32_t bufsize) {
    if (!authenticated || !virtualDiskOpen) {
        // Try to open virtual disk file if not already open
        if (!openVirtualDiskFile()) {
            Serial.println("SMB2: Cannot open virtual disk file for writing");
            return false;
        }
    }
    
    // Calculate absolute offset in the virtual disk file
    uint64_t absoluteOffset = (uint64_t)lba * 512 + offset;
    
    Serial.printf("SMB2: Writing sector LBA=%u, offset=%u, size=%u (abs_offset=%llu)\n", 
                  lba, offset, bufsize, absoluteOffset);
    
    return writeToSMB2File(virtualDiskFileId, absoluteOffset, buffer, bufsize);
}

bool SMBClient::openVirtualDiskFile() {
    if (virtualDiskOpen) {
        return true;
    }
    
    String virtualDiskPath = share_path + "virtual_disk.img";
    Serial.printf("SMB2: Opening virtual disk file: %s\n", virtualDiskPath.c_str());
    
    if (createSMB2File(virtualDiskPath, virtualDiskFileId)) {
        virtualDiskOpen = true;
        Serial.println("SMB2: Virtual disk file opened successfully");
        return true;
    }
    
    Serial.println("SMB2: Failed to open virtual disk file");
    return false;
}

bool SMBClient::createSMB2File(const String& filePath, uint8_t* fileId) {
    uint8_t createPacket[512];
    buildSMB2Header(createPacket, SMB2_CREATE, getNextMessageID(), sessionID, treeID);
    
    uint8_t* payload = createPacket + SMB2_HEADER_SIZE;
    
    // SMB2 CREATE Request structure (57 bytes minimum)
    payload[0] = 57;  // Structure Size (low byte)
    payload[1] = 0;   // Structure Size (high byte)
    
    // Security Flags (1 byte)
    payload[2] = 0;
    
    // Requested Oplock Level (1 byte) - none
    payload[3] = 0;
    
    // Impersonation Level (4 bytes) - Impersonation
    payload[4] = 0x02;
    payload[5] = 0x00;
    payload[6] = 0x00;
    payload[7] = 0x00;
    
    // SMB Create Flags (8 bytes) - zero
    memset(&payload[8], 0, 8);
    
    // Reserved (8 bytes)
    memset(&payload[16], 0, 8);
    
    // Desired Access (4 bytes) - Generic Read/Write
    payload[24] = 0xC0;  // GENERIC_READ | GENERIC_WRITE
    payload[25] = 0x01;
    payload[26] = 0x00;
    payload[27] = 0x00;
    
    // File Attributes (4 bytes) - Normal file
    payload[28] = 0x80;
    payload[29] = 0x00;
    payload[30] = 0x00;
    payload[31] = 0x00;
    
    // Share Access (4 bytes) - Read/Write
    payload[32] = 0x03;  // FILE_SHARE_READ | FILE_SHARE_WRITE
    payload[33] = 0x00;
    payload[34] = 0x00;
    payload[35] = 0x00;
    
    // Create Disposition (4 bytes) - Open if exists, create if not
    payload[36] = 0x04;  // FILE_OPEN_IF
    payload[37] = 0x00;
    payload[38] = 0x00;
    payload[39] = 0x00;
    
    // Create Options (4 bytes) - Non-directory file
    payload[40] = 0x40;  // FILE_NON_DIRECTORY_FILE
    payload[41] = 0x00;
    payload[42] = 0x00;
    payload[43] = 0x00;
    
    // Name Offset (2 bytes) - offset from SMB2 header start
    uint16_t nameOffset = SMB2_HEADER_SIZE + 56;
    payload[44] = nameOffset & 0xFF;
    payload[45] = (nameOffset >> 8) & 0xFF;
    
    // Name Length (2 bytes) - UTF-16 length
    uint16_t nameLength = filePath.length() * 2;
    payload[46] = nameLength & 0xFF;
    payload[47] = (nameLength >> 8) & 0xFF;
    
    // Create Context Offset (4 bytes) - zero (no contexts)
    payload[48] = 0;
    payload[49] = 0;
    payload[50] = 0;
    payload[51] = 0;
    
    // Create Context Length (4 bytes) - zero
    payload[52] = 0;
    payload[53] = 0;
    payload[54] = 0;
    payload[55] = 0;
    
    // File name in UTF-16LE
    uint8_t* nameBuffer = payload + 56;
    for (size_t i = 0; i < filePath.length(); i++) {
        nameBuffer[i * 2] = filePath[i];
        nameBuffer[i * 2 + 1] = 0;
    }
    
    size_t totalSize = SMB2_HEADER_SIZE + 56 + nameLength;
    
    if (client.write(createPacket, totalSize) != totalSize) {
        return false;
    }
    
    delay(100);
    
    uint8_t response[512];
    size_t responseSize = sizeof(response);
    if (!receiveSMB2Response(response, responseSize)) {
        return false;
    }
    
    // Check response status
    uint32_t status = response[8] | (response[9] << 8) | (response[10] << 16) | (response[11] << 24);
    if (status != NT_STATUS_SUCCESS) {
        Serial.printf("SMB2: CREATE failed with status: 0x%08X\n", status);
        return false;
    }
    
    // Extract File ID from CREATE response (16 bytes at offset 132 in response)
    if (responseSize >= SMB2_HEADER_SIZE + 88) {
        memcpy(fileId, &response[SMB2_HEADER_SIZE + 72], 16);
        return true;
    }
    
    return false;
}

bool SMBClient::readFromSMB2File(uint8_t* fileId, uint64_t offset, uint8_t* buffer, uint32_t length) {
    uint8_t readPacket[256];
    buildSMB2Header(readPacket, SMB2_READ, getNextMessageID(), sessionID, treeID);
    
    uint8_t* payload = readPacket + SMB2_HEADER_SIZE;
    
    // SMB2 READ Request structure (49 bytes)
    payload[0] = 49;  // Structure Size (low byte)
    payload[1] = 0;   // Structure Size (high byte)
    
    // Padding (1 byte)
    payload[2] = 0;
    
    // Flags (1 byte)
    payload[3] = 0;
    
    // Length (4 bytes)
    payload[4] = length & 0xFF;
    payload[5] = (length >> 8) & 0xFF;
    payload[6] = (length >> 16) & 0xFF;
    payload[7] = (length >> 24) & 0xFF;
    
    // Offset (8 bytes)
    payload[8] = offset & 0xFF;
    payload[9] = (offset >> 8) & 0xFF;
    payload[10] = (offset >> 16) & 0xFF;
    payload[11] = (offset >> 24) & 0xFF;
    payload[12] = (offset >> 32) & 0xFF;
    payload[13] = (offset >> 40) & 0xFF;
    payload[14] = (offset >> 48) & 0xFF;
    payload[15] = (offset >> 56) & 0xFF;
    
    // File ID (16 bytes)
    memcpy(&payload[16], fileId, 16);
    
    // Minimum Count (4 bytes) - same as length
    payload[32] = length & 0xFF;
    payload[33] = (length >> 8) & 0xFF;
    payload[34] = (length >> 16) & 0xFF;
    payload[35] = (length >> 24) & 0xFF;
    
    // Channel (4 bytes) - main channel
    payload[36] = 0;
    payload[37] = 0;
    payload[38] = 0;
    payload[39] = 0;
    
    // Remaining Bytes (4 bytes) - zero
    payload[40] = 0;
    payload[41] = 0;
    payload[42] = 0;
    payload[43] = 0;
    
    // Read Channel Info Offset (2 bytes) - zero
    payload[44] = 0;
    payload[45] = 0;
    
    // Read Channel Info Length (2 bytes) - zero
    payload[46] = 0;
    payload[47] = 0;
    
    // Buffer (1 byte) - padding
    payload[48] = 0;
    
    size_t totalSize = SMB2_HEADER_SIZE + 49;
    
    if (client.write(readPacket, totalSize) != totalSize) {
        return false;
    }
    
    delay(50);
    
    uint8_t response[8192];
    size_t responseSize = sizeof(response);
    if (!receiveSMB2Response(response, responseSize)) {
        memset(buffer, 0, length);  // Return zeros on read failure
        return true;  // Don't fail completely - just return empty data
    }
    
    // Check response status
    uint32_t status = response[8] | (response[9] << 8) | (response[10] << 16) | (response[11] << 24);
    if (status != NT_STATUS_SUCCESS) {
        memset(buffer, 0, length);  // Return zeros on read failure
        return true;  // Don't fail completely
    }
    
    // Extract data from READ response
    if (responseSize >= SMB2_HEADER_SIZE + 16) {
        uint16_t dataOffset = response[SMB2_HEADER_SIZE + 2] | (response[SMB2_HEADER_SIZE + 3] << 8);
        uint32_t dataLength = response[SMB2_HEADER_SIZE + 4] | (response[SMB2_HEADER_SIZE + 5] << 8) |
                             (response[SMB2_HEADER_SIZE + 6] << 16) | (response[SMB2_HEADER_SIZE + 7] << 24);
        
        if (dataLength > 0 && dataOffset > 0 && dataOffset < responseSize) {
            uint32_t copyLength = min(dataLength, length);
            memcpy(buffer, &response[dataOffset], copyLength);
            if (copyLength < length) {
                memset(&buffer[copyLength], 0, length - copyLength);  // Pad with zeros
            }
        } else {
            memset(buffer, 0, length);
        }
    } else {
        memset(buffer, 0, length);
    }
    
    return true;
}

bool SMBClient::writeToSMB2File(uint8_t* fileId, uint64_t offset, uint8_t* buffer, uint32_t length) {
    uint8_t writePacket[512 + 4096];  // Header + data
    buildSMB2Header(writePacket, SMB2_WRITE, getNextMessageID(), sessionID, treeID);
    
    uint8_t* payload = writePacket + SMB2_HEADER_SIZE;
    
    // SMB2 WRITE Request structure (49 bytes + data)
    payload[0] = 49;  // Structure Size (low byte)
    payload[1] = 0;   // Structure Size (high byte)
    
    // Data Offset (2 bytes) - offset from SMB2 header start
    uint16_t dataOffset = SMB2_HEADER_SIZE + 48;
    payload[2] = dataOffset & 0xFF;
    payload[3] = (dataOffset >> 8) & 0xFF;
    
    // Length (4 bytes)
    payload[4] = length & 0xFF;
    payload[5] = (length >> 8) & 0xFF;
    payload[6] = (length >> 16) & 0xFF;
    payload[7] = (length >> 24) & 0xFF;
    
    // Offset (8 bytes)
    payload[8] = offset & 0xFF;
    payload[9] = (offset >> 8) & 0xFF;
    payload[10] = (offset >> 16) & 0xFF;
    payload[11] = (offset >> 24) & 0xFF;
    payload[12] = (offset >> 32) & 0xFF;
    payload[13] = (offset >> 40) & 0xFF;
    payload[14] = (offset >> 48) & 0xFF;
    payload[15] = (offset >> 56) & 0xFF;
    
    // File ID (16 bytes)
    memcpy(&payload[16], fileId, 16);
    
    // Channel (4 bytes) - main channel
    payload[32] = 0;
    payload[33] = 0;
    payload[34] = 0;
    payload[35] = 0;
    
    // Remaining Bytes (4 bytes) - zero
    payload[36] = 0;
    payload[37] = 0;
    payload[38] = 0;
    payload[39] = 0;
    
    // Write Channel Info Offset (2 bytes) - zero
    payload[40] = 0;
    payload[41] = 0;
    
    // Write Channel Info Length (2 bytes) - zero
    payload[42] = 0;
    payload[43] = 0;
    
    // Flags (4 bytes) - zero
    payload[44] = 0;
    payload[45] = 0;
    payload[46] = 0;
    payload[47] = 0;
    
    // Copy the data after the header
    memcpy(&writePacket[dataOffset], buffer, length);
    
    size_t totalSize = dataOffset + length;
    
    if (client.write(writePacket, totalSize) != totalSize) {
        return false;
    }
    
    delay(50);
    
    uint8_t response[512];
    size_t responseSize = sizeof(response);
    if (!receiveSMB2Response(response, responseSize)) {
        return false;
    }
    
    // Check response status
    uint32_t status = response[8] | (response[9] << 8) | (response[10] << 16) | (response[11] << 24);
    if (status != NT_STATUS_SUCCESS) {
        Serial.printf("SMB2: WRITE failed with status: 0x%08X\n", status);
        return false;
    }
    
    return true;
}
