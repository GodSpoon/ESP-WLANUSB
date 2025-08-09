#ifndef SMB_CLIENT_H
#define SMB_CLIENT_H

#include <WiFi.h>
#include <WiFiClient.h>
#include "FS.h"

// SMB Protocol constants
#define SMB_PORT 445
#define NETBIOS_PORT 139
#define SMB2_HEADER_SIZE 64
#define MAX_BUFFER_SIZE 8192

// SMB2 Commands
#define SMB2_NEGOTIATE 0x0000
#define SMB2_SESSION_SETUP 0x0001
#define SMB2_TREE_CONNECT 0x0003
#define SMB2_CREATE 0x0005
#define SMB2_WRITE 0x0009
#define SMB2_READ 0x0008
#define SMB2_CLOSE 0x0006

// SMB2 Dialects
#define SMB2_DIALECT_202 0x0202
#define SMB2_DIALECT_210 0x0210
#define SMB2_DIALECT_300 0x0300
#define SMB2_DIALECT_302 0x0302
#define SMB2_DIALECT_311 0x0311

// SMB Status codes
#define NT_STATUS_SUCCESS 0x00000000
#define NT_STATUS_LOGON_FAILURE 0xC000006D
#define NT_STATUS_MORE_PROCESSING_REQUIRED 0xC0000016

class SMBClient {
private:
    WiFiClient client;
    String server_ip;
    String share_name;
    String username;
    String password;
    String share_path;
    bool authenticated;
    uint64_t messageID;
    uint64_t sessionID;
    uint32_t treeID;
    uint16_t negotiatedDialect;
    uint8_t virtualDiskFileId[16];  // File ID for the virtual disk file on SMB share
    bool virtualDiskOpen;
    
    // Helper functions
    bool connectToServer();
    bool negotiateProtocol();
    bool authenticateUser();
    bool connectToShare();
    bool sendSMB2Packet(uint8_t* packet, size_t size);
    bool receiveSMB2Response(uint8_t* buffer, size_t& size);
    void buildSMB2Header(uint8_t* packet, uint16_t command, uint64_t messageId, uint64_t sessionId, uint32_t treeId);
    uint64_t getNextMessageID();
    bool parseNTLMType2Message(uint8_t* buffer, size_t size, uint8_t* challenge);
    void buildNTLMType3Response(uint8_t* response, size_t& responseSize, const uint8_t* challenge);
    bool openVirtualDiskFile();
    bool createSMB2File(const String& filePath, uint8_t* fileId);
    bool readFromSMB2File(uint8_t* fileId, uint64_t offset, uint8_t* buffer, uint32_t length);
    bool writeToSMB2File(uint8_t* fileId, uint64_t offset, uint8_t* buffer, uint32_t length);
    
public:
    SMBClient();
    ~SMBClient();
    
    bool begin(const String& server, const String& share, const String& path, 
               const String& user, const String& pass);
    bool uploadFile(const String& localPath, const String& remotePath, fs::FS& fileSystem);
    bool readSector(uint32_t lba, uint32_t offset, uint8_t* buffer, uint32_t bufsize);
    bool writeSector(uint32_t lba, uint32_t offset, uint8_t* buffer, uint32_t bufsize);
    void end();
    bool isConnected();
};

#endif // SMB_CLIENT_H
