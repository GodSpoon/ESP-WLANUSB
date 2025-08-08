├── .gitignore
├── .vscode
    ├── extensions.json
    └── settings.json
├── README.md
├── assets
    └── images
    │   ├── MemoryStick.png
    │   ├── Settings.png
    │   └── WebInterface.png
├── include
    └── README
├── lib
    └── README
├── platformio.ini
├── src
    ├── fileserver.h
    └── main.cpp
├── test
    └── README
└── web
    ├── favicon.ico
    ├── index.html
    └── settings.html


/.gitignore:
--------------------------------------------------------------------------------
1 | .pio
2 | .vscode/.browse.c_cpp.db*
3 | .vscode/c_cpp_properties.json
4 | .vscode/launch.json
5 | .vscode/ipch
6 | .DS_Store
7 | 


--------------------------------------------------------------------------------
/.vscode/extensions.json:
--------------------------------------------------------------------------------
 1 | {
 2 |     // See http://go.microsoft.com/fwlink/?LinkId=827846
 3 |     // for the documentation about the extensions.json format
 4 |     "recommendations": [
 5 |         "platformio.platformio-ide"
 6 |     ],
 7 |     "unwantedRecommendations": [
 8 |         "ms-vscode.cpptools-extension-pack"
 9 |     ]
10 | }
11 | 


--------------------------------------------------------------------------------
/.vscode/settings.json:
--------------------------------------------------------------------------------
1 | {
2 |     "files.associations": {
3 |         "functional": "cpp",
4 |         "tuple": "cpp",
5 |         "*._h": "cpp",
6 |         "*._xcpp": "c"
7 |     }
8 | }


--------------------------------------------------------------------------------
/README.md:
--------------------------------------------------------------------------------
 1 | ThingPulse Pendrive S3 - Wireless USB Disk
 2 | ==========================================
 3 | 
 4 | This code is made for the Pendrive S3: https://thingpulse.com/product/esp32-s3-pendrive-s3-128mb/
 5 | 
 6 | # What Does It Do?
 7 | 
 8 | After plugin the device into a computer it will mount like a regular
 9 | memory stick. At the same time it starts a WiFi Access Point
10 | with a webserver. A user can then access the files stored on the 
11 | memory stick over this web interface.
12 | 
13 | 
14 | 
15 | # How To Build & Flash
16 | 
17 | 1. Checkout this repository with git
18 | 2. Open with VS Code
19 | 3. Setup Platformio for VS Code
20 | 4. Build and upload the sample
21 | 
22 | 
23 | # How To Use
24 | 
25 | ## Accessing Files Over the Web Interface
26 | 
27 | When the device is plugged in it will mount a mass storage device with
28 | about 120MB of space. At the same time it starts a WiFi Access Point
29 | `wireless-usb-disk` with password `12345678`. By connecting to this access
30 | point the files on the memory stick can be accessed in the browser: http://192.168.4.1
31 | 
32 | The Web View:
33 | ![Web Interface](assets/images/WebInterface.png)
34 | 
35 | The Data On the Memory Stick:
36 | ![Memory Stick](assets/images/MemoryStick.png)
37 | 
38 | ## Uploading & Deleting Files
39 | 
40 | You can delete and upload files over the web interface as well. Please note that changing 
41 | files over the web interface will restart the device to make the changes visible on the host
42 | computer.
43 | 
44 | ## Settings
45 | 
46 | By clicking on the `Settings` link you can change the WiFi settings of the device.
47 | ![Settings](assets/images/Settings.png)
48 | 
49 |  * Mode: AP (Access Point), STA (Device connects to access point), AP + STA (both)
50 |  * AP SSID/ Password: credentials of the access point the device will start in AP mode
51 |  * STA SSID/ Password: credentials of the WiFi network where the device will connect to in STA mode
52 | 
53 | ## LED
54 | 
55 | The color of the LED changes when the host computer reads or writes to the device:
56 |  * Red (50, 0, 0) when the host computer writes
57 |  * Green (0, 50, 0) when the host reads
58 |  * Brown (50, 50, 0) when there were read and write operations in the last 0.5s
59 | 


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/ThingPulse/esp32-s3-pendrive-wireless-usb-disk/2212c2a00efa1b2ec2d2c8676d8918237fe1afe6/assets/images/MemoryStick.png


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/ThingPulse/esp32-s3-pendrive-wireless-usb-disk/2212c2a00efa1b2ec2d2c8676d8918237fe1afe6/assets/images/Settings.png


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/ThingPulse/esp32-s3-pendrive-wireless-usb-disk/2212c2a00efa1b2ec2d2c8676d8918237fe1afe6/assets/images/WebInterface.png


--------------------------------------------------------------------------------
/include/README:
--------------------------------------------------------------------------------
 1 | 
 2 | This directory is intended for project header files.
 3 | 
 4 | A header file is a file containing C declarations and macro definitions
 5 | to be shared between several project source files. You request the use of a
 6 | header file in your project source file (C, C++, etc) located in `src` folder
 7 | by including it, with the C preprocessing directive `#include'.
 8 | 
 9 | ```src/main.c
10 | 
11 | #include "header.h"
12 | 
13 | int main (void)
14 | {
15 |  ...
16 | }
17 | ```
18 | 
19 | Including a header file produces the same results as copying the header file
20 | into each source file that needs it. Such copying would be time-consuming
21 | and error-prone. With a header file, the related declarations appear
22 | in only one place. If they need to be changed, they can be changed in one
23 | place, and programs that include the header file will automatically use the
24 | new version when next recompiled. The header file eliminates the labor of
25 | finding and changing all the copies as well as the risk that a failure to
26 | find one copy will result in inconsistencies within a program.
27 | 
28 | In C, the usual convention is to give header files names that end with `.h'.
29 | It is most portable to use only letters, digits, dashes, and underscores in
30 | header file names, and at most one dot.
31 | 
32 | Read more about using header files in official GCC documentation:
33 | 
34 | * Include Syntax
35 | * Include Operation
36 | * Once-Only Headers
37 | * Computed Includes
38 | 
39 | https://gcc.gnu.org/onlinedocs/cpp/Header-Files.html
40 | 


--------------------------------------------------------------------------------
/lib/README:
--------------------------------------------------------------------------------
 1 | 
 2 | This directory is intended for project specific (private) libraries.
 3 | PlatformIO will compile them to static libraries and link into executable file.
 4 | 
 5 | The source code of each library should be placed in a an own separate directory
 6 | ("lib/your_library_name/[here are source files]").
 7 | 
 8 | For example, see a structure of the following two libraries `Foo` and `Bar`:
 9 | 
10 | |--lib
11 | |  |
12 | |  |--Bar
13 | |  |  |--docs
14 | |  |  |--examples
15 | |  |  |--src
16 | |  |     |- Bar.c
17 | |  |     |- Bar.h
18 | |  |  |- library.json (optional, custom build options, etc) https://docs.platformio.org/page/librarymanager/config.html
19 | |  |
20 | |  |--Foo
21 | |  |  |- Foo.c
22 | |  |  |- Foo.h
23 | |  |
24 | |  |- README --> THIS FILE
25 | |
26 | |- platformio.ini
27 | |--src
28 |    |- main.c
29 | 
30 | and a contents of `src/main.c`:
31 | ```
32 | #include <Foo.h>
33 | #include <Bar.h>
34 | 
35 | int main (void)
36 | {
37 |   ...
38 | }
39 | 
40 | ```
41 | 
42 | PlatformIO Library Dependency Finder will find automatically dependent
43 | libraries scanning project source files.
44 | 
45 | More information about PlatformIO Library Dependency Finder
46 | - https://docs.platformio.org/page/librarymanager/ldf.html
47 | 


--------------------------------------------------------------------------------
/platformio.ini:
--------------------------------------------------------------------------------
 1 | ; PlatformIO Project Configuration File
 2 | ;
 3 | ;   Build options: build flags, source filter
 4 | ;   Upload options: custom upload port, speed and extra flags
 5 | ;   Library options: dependencies, extra library storages
 6 | ;   Advanced options: extra scripting
 7 | ;
 8 | ; Please visit documentation for the other options and examples
 9 | ; https://docs.platformio.org/page/projectconf.html
10 | 
11 | 
12 | [env:esp32s3]
13 | ;platform = espressif32@^6.7.0
14 | platform = https://github.com/cziter15/platform-espressif32.git
15 | board = esp32-s3-devkitc-1
16 | framework = arduino
17 | board_upload.use_1200bps_touch = yes
18 | board_upload.wait_for_upload_port = yes
19 | board_upload.require_upload_port = yes
20 | monitor_speed = 115200
21 | upload_speed = 921600
22 | monitor_filters = esp32_exception_decoder, time
23 | ;board_build.partitions = default.csv
24 | board_build.partitions = min_spiffs.csv
25 | board_upload.flash_size = 4MB
26 | lib_deps = bblanchon/ArduinoJson@^7.1.0
27 | 
28 | build_flags = -DCORE_DEBUG_LEVEL=1
29 |               -DARDUINO_USB_CDC_ON_BOOT=1
30 |               -DARDUINO_USB_MODE=0
31 | 
32 | board_build.embed_files = web/index.html
33 |                           web/settings.html
34 |                           web/favicon.ico
35 | 
36 | 
37 | 


--------------------------------------------------------------------------------
/src/fileserver.h:
--------------------------------------------------------------------------------
  1 | /**
  2 |  * Simple MSC device with SD card
  3 |  * author: chegewara
  4 |  */
  5 | #include <WiFi.h>
  6 | #include <WiFiClient.h>
  7 | #include <WiFiAP.h>
  8 | #include <WebServer.h>
  9 | #include <ArduinoJson.h>
 10 | //#include <LittleFS.h>
 11 | #include <SD_MMC.h>
 12 | #include <SPIFFS.h>
 13 | 
 14 | #define SD_MISO  37
 15 | #define SD_MOSI  35
 16 | #define SD_SCK   36
 17 | #define SD_CS    34
 18 | 
 19 | extern const uint8_t index_html_start[] asm("_binary_web_index_html_start");
 20 | extern const uint8_t index_html_end[] asm("_binary_web_index_html_end");
 21 | 
 22 | extern const uint8_t settings_html_start[] asm("_binary_web_settings_html_start");
 23 | extern const uint8_t settings_html_end[] asm("_binary_web_settings_html_end");
 24 | 
 25 | extern const uint8_t favicon_ico_start[] asm("_binary_web_favicon_ico_start");
 26 | extern const uint8_t favicon_ico_end[] asm("_binary_web_favicon_ico_end");
 27 | 
 28 | 
 29 | // Config SSID and password
 30 | const char* AP_SSID        = "wireless-usb-disk";  // Enter your SSID here
 31 | const char* AP_PASSWORD    = "12345678";           // Enter your Password here
 32 | 
 33 | // settings path on SPIFFS
 34 | const char *settings_path = "/settings.json";
 35 | 
 36 | struct Settings {
 37 |   String mode;
 38 |   String apSsid;
 39 |   String apPassword;
 40 |   String staSsid;
 41 |   String staPassword; // Will store, but not send this
 42 | };
 43 | 
 44 | Settings settings;
 45 | 
 46 | // web server
 47 | WebServer server(80);
 48 | //holds the current upload
 49 | File fsUploadFile;
 50 | 
 51 | void onWiFiEvent(WiFiEvent_t event) {
 52 |   switch (event) {
 53 |     case ARDUINO_EVENT_WIFI_STA_GOT_IP:
 54 |       Serial.print("Obtained IP address: ");
 55 |       Serial.println(WiFi.localIP());
 56 |       break;
 57 |     default:
 58 |       Serial.printf("WiFi event: %d\n", event);
 59 |       break;
 60 |   }
 61 | }
 62 | 
 63 | void loadSettings() {
 64 |   if (SPIFFS.exists(settings_path)) {
 65 |     File file = SPIFFS.open(settings_path);
 66 |     if (!file) {
 67 | 
 68 |       return;
 69 |     }
 70 | 
 71 |     DynamicJsonDocument jsonDoc(1024);
 72 |     DeserializationError error = deserializeJson(jsonDoc, file);
 73 |     if (error) {
 74 |       Serial.println("Failed to parse settings file");
 75 |     } else {
 76 |       settings.mode = jsonDoc["mode"].as<String>();
 77 |       settings.apSsid = jsonDoc["apSsid"].as<String>();
 78 |       settings.apPassword = jsonDoc["apPassword"].as<String>();
 79 |       settings.staSsid = jsonDoc["staSsid"].as<String>();
 80 |       settings.staPassword = jsonDoc["staPassword"].as<String>();
 81 |     }
 82 |     file.close();
 83 |   } else {
 84 |     Serial.println("Settings file does not exist. Using defaults.");
 85 |     settings.mode = "AP";
 86 |     settings.apSsid = AP_SSID;
 87 |     settings.apPassword = AP_PASSWORD;
 88 |     settings.staSsid = "";
 89 |     settings.staPassword = "";
 90 |   }
 91 | }
 92 | 
 93 | void saveSettings() {
 94 |   File file = SPIFFS.open(settings_path, FILE_WRITE);
 95 |   if (!file) {
 96 |     Serial.println("Failed to open settings file for writing");
 97 |     return;
 98 |   }
 99 | 
100 |   DynamicJsonDocument jsonDoc(1024);
101 |   jsonDoc["mode"] = settings.mode;
102 |   jsonDoc["apSsid"] = settings.apSsid;
103 |   jsonDoc["apPassword"] = settings.apPassword;
104 |   jsonDoc["staSsid"] = settings.staSsid;
105 |   jsonDoc["staPassword"] = settings.staPassword;
106 | 
107 |   if (serializeJson(jsonDoc, file) == 0) {
108 |     Serial.println("Failed to write settings to file");
109 |   } else {
110 |     Serial.println("Settings saved");
111 |   }
112 |   file.close();
113 | }
114 | 
115 | String getContentType(String filename) {
116 |     if (server.hasArg("download")) {
117 |         return "application/octet-stream";
118 |     } else if (filename.endsWith(".htm")) {
119 |         return "text/html";
120 |     } else if (filename.endsWith(".html")) {
121 |         return "text/html";
122 |     } else if (filename.endsWith(".css")) {
123 |         return "text/css";
124 |     } else if (filename.endsWith(".js")) {
125 |         return "application/javascript";
126 |     } else if (filename.endsWith(".png")) {
127 |         return "image/png";
128 |     } else if (filename.endsWith(".gif")) {
129 |         return "image/gif";
130 |     } else if (filename.endsWith(".jpg") || filename.endsWith(".jpeg")) {
131 |         return "image/jpeg";
132 |     } else if (filename.endsWith(".ico")) {
133 |         return "image/x-icon";
134 |     } else if (filename.endsWith(".xml")) {
135 |         return "text/xml";
136 |     } else if (filename.endsWith(".pdf")) {
137 |         return "application/x-pdf";
138 |     } else if (filename.endsWith(".zip")) {
139 |         return "application/x-zip";
140 |     } else if (filename.endsWith(".gz")) {
141 |         return "application/x-gzip";
142 |     }
143 |     return "text/plain";
144 | }
145 | 
146 | void handleIndex() {
147 |     server.send_P(200, "text/html", (const char*)index_html_start, index_html_end - index_html_start);
148 | }
149 | 
150 | void handleSettings() {
151 |     server.send_P(200, "text/html", (const char*)settings_html_start, settings_html_end - settings_html_start);
152 | }
153 | 
154 | void handleFileUpload() {
155 |     if (server.uri() != "/upload") {
156 |         return;
157 |     }
158 | 
159 |     HTTPUpload& upload = server.upload();
160 |     if (upload.status == UPLOAD_FILE_START) {
161 |         String filename = upload.filename;
162 |         if (!filename.startsWith("/")) {
163 |             filename = "/" + filename;
164 |         }
165 |         Serial.print("handleFileUpload Name: "); 
166 |         Serial.println(filename);
167 |         fsUploadFile = SD_MMC.open(filename, "w");
168 |         filename = String();
169 |     } else if (upload.status == UPLOAD_FILE_WRITE) {
170 |         if (fsUploadFile) {
171 |             fsUploadFile.write(upload.buf, upload.currentSize);
172 |         }
173 |     } else if (upload.status == UPLOAD_FILE_END) {
174 |         if (fsUploadFile) {
175 |             Serial.println("Uploaded");
176 |             fsUploadFile.close();
177 |         }
178 |         Serial.print("handleFileUpload Size: ");
179 |         Serial.println(upload.totalSize);
180 |         ESP.restart();
181 |     }
182 | }
183 | 
184 | bool handleFileRead(String path) {
185 |     Serial.println("handleFileRead: " + path);
186 |     if (path.endsWith("/")) {
187 |         handleIndex();
188 |         return true;
189 |     } else if (path.endsWith("/settings.html")) {
190 |         handleSettings();
191 |     } else if (path.endsWith("/favicon.ico")) {
192 |         String contentType = "text/x-icon";
193 |         server.send_P(200, "text/x-icon", (const char*)favicon_ico_start, favicon_ico_end - favicon_ico_start);
194 |         return true;
195 |     } else {
196 |         String contentType = getContentType(path);
197 |         String pathWithGz = path + ".gz";
198 |         if (SD_MMC.exists(pathWithGz) || SD_MMC.exists(path)) {
199 |             if (SD_MMC.exists(pathWithGz)) {
200 |                 path += ".gz";
201 |             }
202 |             File file = SD_MMC.open(path, "r");
203 |             if (file.isDirectory()) {
204 |                 handleIndex();
205 |                 file.close();
206 |             } else {
207 |                 server.streamFile(file, contentType);
208 |                 file.close();
209 |             }
210 |             return true;
211 |         }
212 |     }
213 |     return false;
214 | }
215 | 
216 | void handleFileDelete() {
217 |     if (server.args() == 0) {
218 |         return server.send(500, "text/plain", "BAD ARGS");
219 |     }
220 |     String path = server.arg(0);
221 |     Serial.println("handleFileDelete: " + path);
222 |     if (path == "/") {
223 |         return server.send(500, "text/plain", "BAD PATH");
224 |     }
225 | 
226 |     if (!path.startsWith("/")) {
227 |         path = String("/") + path;
228 |     }
229 | 
230 |     if (!SD_MMC.exists(path)) {
231 |         return server.send(404, "text/plain", "FileNotFound");
232 |     }
233 | 
234 |     Serial.println("Delete: " + path);
235 |     SD_MMC.remove(path);
236 |     server.sendHeader("Location", String("/"), true);
237 |     server.send(302, "text/plain", "");
238 |     path = String();
239 | }
240 | 
241 | void handleFileList() {
242 |     String path;
243 |     if (!server.hasArg("dir")) {
244 |         path = "/";
245 |     } else {
246 |         path = server.arg("dir");
247 |     }
248 | 
249 |     Serial.println("handleFileList: " + path);
250 | 
251 |     File root = SD_MMC.open(path);
252 |     String output = "[";
253 | 
254 |     if (root && root.isDirectory()) {
255 |         File file = root.openNextFile();
256 |         while (file) {
257 |             // Filter out files starting with '.'
258 |             if (file.name()[0] != '.') {
259 |                 if (output != "[") {
260 |                     output += ',';
261 |                 }
262 | 
263 |                 output += "{\"type\":\"";
264 |                 output += (file.isDirectory()) ? "dir" : "file";
265 |                 output += "\",\"name\":\"";
266 |                 output += String(file.name());
267 |                 output += "\",\"size\":";
268 |                 output += String(file.size());
269 |                 output += "}";
270 |                 
271 |             } else {
272 |                 Serial.printf("Skipping file %s\n", file.name());
273 |             }
274 |             file = root.openNextFile();
275 |         }
276 |     }
277 |     output += "]";
278 |     server.send(200, "text/json", output);
279 | }
280 | 
281 | void getSettings() {
282 |     DynamicJsonDocument jsonDoc(1024);
283 | 
284 |     // Fill JSON document with settings values
285 |     jsonDoc["mode"] = settings.mode;
286 |     jsonDoc["apSsid"] = settings.apSsid;
287 |     jsonDoc["apPassword"] = settings.apPassword;
288 |     jsonDoc["staSsid"] = settings.staSsid;
289 |     // jsonDoc["staPassword"] = settings.staPassword; // Do not send STA password
290 | 
291 |     String jsonString;
292 |     serializeJson(jsonDoc, jsonString);
293 |     server.send(200, "application/json", jsonString);
294 | }
295 | 
296 | void postSettings() {
297 |     if (server.hasArg("plain")) {
298 |       String body = server.arg("plain");
299 |       DynamicJsonDocument jsonDoc(1024);
300 |       DeserializationError error = deserializeJson(jsonDoc, body);
301 |       if (error) {
302 |         server.send(400, "application/json", "{\"error\":\"Invalid JSON\"}");
303 |         return;
304 |       }
305 | 
306 |       // Assign values from JSON
307 |       settings.mode = jsonDoc["mode"].as<String>();
308 |       settings.apSsid = jsonDoc["apSsid"].as<String>();
309 |       settings.apPassword = jsonDoc["apPassword"].as<String>();
310 |       settings.staSsid = jsonDoc["staSsid"].as<String>();
311 |       // Do not overwrite staPassword if it is not provided
312 |       if (jsonDoc.containsKey("staPassword")) {
313 |         Serial.println("Updating staPassword");
314 |         settings.staPassword = jsonDoc["staPassword"].as<String>();
315 |       } else {
316 |         Serial.println("Not updating staPassword");
317 |       }
318 | 
319 |       // Save the new settings
320 |       saveSettings();
321 |       server.send(200, "application/json", "{\"status\":\"ok\"}");
322 |     } else {
323 |       server.send(400, "application/json", "{\"error\":\"Missing body\"}");
324 |     }
325 | }
326 | 
327 | void writeFile(fs::FS &fs, const char * path, const char * message){
328 |     Serial.printf("Writing file: %s\n", path);
329 | 
330 |     File file = fs.open(path, FILE_WRITE);
331 |     if(!file){
332 |         Serial.println("Failed to open file for writing");
333 |         return;
334 |     }
335 |     if(file.print(message)){
336 |         Serial.println("File written");
337 |     } else {
338 |         Serial.println("Write failed");
339 |     }
340 |     file.close();
341 | }
342 | 
343 | void appendFile(fs::FS &fs, const char * path, const char * message){
344 |     Serial.printf("Appending to file: %s\n", path);
345 | 
346 |     File file = fs.open(path, FILE_APPEND);
347 |     if(!file){
348 |         Serial.println("Failed to open file for appending");
349 |         return;
350 |     }
351 |     if(file.print(message)){
352 |         Serial.println("Message appended");
353 |     } else {
354 |         Serial.println("Append failed");
355 |     }
356 |     file.close();
357 | }
358 | 
359 | String getCardType() {
360 |     uint8_t cardType = SD_MMC.cardType();
361 |     if(cardType == CARD_MMC){
362 |         return "MMC";
363 |     } else if(cardType == CARD_SD){
364 |         return "SDSC";
365 |     } else if(cardType == CARD_SDHC){
366 |         return "SDHC";
367 |     } else {
368 |         return "UNKNOWN";
369 |     }
370 | }
371 | 
372 | void testSD()
373 | {
374 | 
375 |     uint8_t cardType = SD_MMC.cardType();
376 |     Serial.print("SD Card Type: ");
377 |     if(cardType == CARD_MMC){
378 |         Serial.println("MMC");
379 |     } else if(cardType == CARD_SD){
380 |         Serial.println("SDSC");
381 |     } else if(cardType == CARD_SDHC){
382 |         Serial.println("SDHC");
383 |     } else {
384 |         Serial.println("UNKNOWN");
385 |     }
386 | 
387 |     uint64_t cardSize = SD_MMC.cardSize() / (1024 * 1024);
388 |     Serial.printf("SD Card Size: %lluMB\n", cardSize);
389 |     Serial.printf("Total space: %lluMB\n", SD_MMC.totalBytes() / (1024 * 1024));
390 |     Serial.printf("Used space: %lluMB\n", SD_MMC.usedBytes() / (1024 * 1024));
391 | }
392 | 
393 | void handleDiskInfo() {
394 |     DynamicJsonDocument jsonDoc(1024);
395 | 
396 |     jsonDoc["total"] = SD_MMC.totalBytes();
397 |     jsonDoc["used"] = SD_MMC.usedBytes();
398 |     jsonDoc["free"] = SD_MMC.totalBytes() - SD_MMC.usedBytes();
399 |     jsonDoc["cardType"] = getCardType();
400 |     jsonDoc["cardSize"] = SD_MMC.cardSize();
401 | 
402 |     String jsonString;
403 |     serializeJson(jsonDoc, jsonString);
404 |     server.send(200, "application/json", jsonString);
405 | 
406 | }
407 | 
408 | void startFileServer() {
409 |     server.on("/api/list", HTTP_GET, handleFileList);
410 |     server.on("/api/disk", HTTP_GET, handleDiskInfo);
411 |     server.on("/api/settings", HTTP_GET, getSettings);
412 |     server.on("/api/settings", HTTP_POST, postSettings);
413 |     server.on("/delete", HTTP_POST, handleFileDelete);
414 |     server.on("/upload", HTTP_POST, []() {
415 |         server.sendHeader("Location", String("/"), true);
416 |         server.send(302, "text/plain", "");
417 |     }, handleFileUpload);
418 |     server.onNotFound([]() {
419 |         if (!handleFileRead(server.urlDecode(server.uri()))) {
420 |             server.send(404, "text/plain", "FileNotFound");
421 |         }
422 |     });
423 |     server.enableCORS(true);
424 |     server.begin();
425 | }
426 | 
427 | void initWebServer() {
428 | 
429 |   if (!SPIFFS.begin(true)) {
430 |     Serial.println("An Error has occurred while mounting SPIFFS");
431 |     return;
432 |   }
433 | 
434 |   loadSettings();
435 | 
436 |   if (settings.mode == "AP") {
437 |     WiFi.mode(WIFI_AP);
438 |     WiFi.softAP(settings.apSsid.c_str(), settings.apPassword.c_str());
439 |   } else if (settings.mode == "STA") {
440 |     WiFi.mode(WIFI_STA);
441 |     WiFi.begin(settings.staSsid.c_str(), settings.staPassword.c_str());
442 |   } else {
443 |     WiFi.mode(WIFI_MODE_APSTA);
444 |     WiFi.softAP(settings.apSsid.c_str(), settings.apPassword.c_str());
445 |     WiFi.begin(settings.staSsid.c_str(), settings.staPassword.c_str());
446 |   }
447 | 
448 |   WiFi.onEvent(onWiFiEvent);
449 | 
450 |   delay(1000);
451 |   startFileServer();
452 | }
453 | 
454 | void handleServer() {
455 |   server.handleClient();
456 | }


--------------------------------------------------------------------------------
/src/main.cpp:
--------------------------------------------------------------------------------
  1 | 
  2 | #include <Arduino.h>
  3 | #include <USB.h>
  4 | #include <USBMSC.h>
  5 | #include <SD_MMC.h>
  6 | #include "fileserver.h"
  7 | 
  8 | // USB Mass Storage Class (MSC) object
  9 | USBMSC msc;
 10 | 
 11 | int clk = 36;
 12 | int cmd = 35;
 13 | int d0 = 37;
 14 | int d1 = 38;
 15 | int d2 = 33;
 16 | int d3 = 34;
 17 | bool onebit = false;  // set to false for 4-bit. 1-bit will ignore the d1-d3 pins (but d3 must be pulled high)
 18 | 
 19 | #define LED_PIN 5
 20 | 
 21 | bool light_state = true;
 22 | 
 23 | uint32_t lastRead = 0;
 24 | uint32_t lastWrite = 0;
 25 | 
 26 | static int32_t onWrite(uint32_t lba, uint32_t offset, uint8_t *buffer, uint32_t bufsize) {
 27 |   uint32_t secSize = SD_MMC.sectorSize();
 28 |   
 29 |   if (!secSize) {
 30 |     return false;  // disk error
 31 |   }
 32 |   
 33 |   log_v("Write lba: %ld\toffset: %ld\tbufsize: %ld", lba, offset, bufsize);
 34 |   for (int x = 0; x < bufsize / secSize; x++) {
 35 |     uint8_t blkbuffer[secSize];
 36 |     memcpy(blkbuffer, (uint8_t *)buffer + secSize * x, secSize);
 37 |     if (!SD_MMC.writeRAW(blkbuffer, lba + x)) {
 38 |       return false;
 39 |     }
 40 |   }
 41 |   lastRead = millis();
 42 |   return bufsize;
 43 | }
 44 | 
 45 | static int32_t onRead(uint32_t lba, uint32_t offset, void *buffer, uint32_t bufsize) {
 46 |   uint32_t secSize = SD_MMC.sectorSize();
 47 |   if (!secSize) {
 48 |     return false;  // disk error
 49 |   }
 50 |   
 51 |   log_v("Read lba: %ld\toffset: %ld\tbufsize: %ld\tsector: %lu", lba, offset, bufsize, secSize);
 52 |   for (int x = 0; x < bufsize / secSize; x++) {
 53 |     if (!SD_MMC.readRAW((uint8_t *)buffer + (x * secSize), lba + x)) {
 54 |       return false;  // outside of volume boundary
 55 |     }
 56 |   }
 57 |   lastWrite = millis();
 58 |   return bufsize;
 59 | }
 60 | 
 61 | static bool onStartStop(uint8_t power_condition, bool start, bool load_eject) {
 62 |   log_i("Start/Stop power: %u\tstart: %d\teject: %d", power_condition, start, load_eject);
 63 |   return true;
 64 | }
 65 | 
 66 | static void usbEventCallback(void *arg, esp_event_base_t event_base, int32_t event_id, void *event_data) {
 67 |   if (event_base == ARDUINO_USB_EVENTS) {
 68 |     arduino_usb_event_data_t *data = (arduino_usb_event_data_t *)event_data;
 69 |     switch (event_id) {
 70 |       case ARDUINO_USB_STARTED_EVENT: 
 71 |         Serial.println("USB PLUGGED"); 
 72 | 
 73 |         break;
 74 |       case ARDUINO_USB_STOPPED_EVENT: 
 75 |         Serial.println("USB UNPLUGGED"); 
 76 | 
 77 |         break;
 78 |       case ARDUINO_USB_SUSPEND_EVENT: 
 79 |         Serial.printf("USB SUSPENDED: remote_wakeup_en: %u\n", data->suspend.remote_wakeup_en); 
 80 | 
 81 |         break;
 82 |       case ARDUINO_USB_RESUME_EVENT:  
 83 |         Serial.println("USB RESUMED");
 84 | 
 85 |         break;
 86 | 
 87 |       default: break;
 88 |     }
 89 |   }
 90 | }
 91 | 
 92 | void setup() {
 93 |   Serial.begin(115200);
 94 |   Serial.setDebugOutput(true);
 95 |   Serial.println("Starting Serial");
 96 |   while(!Serial);
 97 | 
 98 |   Serial.println("Mounting SDcard");
 99 |   SD_MMC.setPins(clk, cmd, d0, d1, d2, d3);
100 |   if (!SD_MMC.begin("/sdcard", onebit)) {
101 |     Serial.println("Mount Failed");
102 |     return;
103 |   }
104 | 
105 |   Serial.println("Initializing MSC");
106 |   // Initialize USB metadata and callbacks for MSC (Mass Storage Class)
107 |   msc.vendorID("ESP32");
108 |   msc.productID("USB_MSC");
109 |   msc.productRevision("1.0");
110 |   msc.onRead(onRead);
111 |   msc.onWrite(onWrite);
112 |   msc.onStartStop(onStartStop);
113 |   msc.mediaPresent(true);
114 |   msc.begin(SD_MMC.numSectors(), SD_MMC.sectorSize());
115 | 
116 |   Serial.println("Initializing USB");
117 | 
118 |   USB.begin();
119 |   USB.onEvent(usbEventCallback);
120 | 
121 |   Serial.printf("Card Size: %lluMB\n", SD_MMC.totalBytes() / 1024 / 1024);
122 |   Serial.printf("Sector: %d\tCount: %d\n", SD_MMC.sectorSize(), SD_MMC.numSectors());
123 |   initWebServer();
124 | }
125 | 
126 | void loop() {
127 |   //delay(-1);
128 |   neopixelWrite(LED_PIN, millis() - lastRead < 250 ? 50 : 0, millis() - lastWrite < 250 ? 50 : 0, 0);
129 |   handleServer();
130 | }


--------------------------------------------------------------------------------
/test/README:
--------------------------------------------------------------------------------
 1 | 
 2 | This directory is intended for PlatformIO Unit Testing and project tests.
 3 | 
 4 | Unit Testing is a software testing method by which individual units of
 5 | source code, sets of one or more MCU program modules together with associated
 6 | control data, usage procedures, and operating procedures, are tested to
 7 | determine whether they are fit for use. Unit testing finds problems early
 8 | in the development cycle.
 9 | 
10 | More information about PlatformIO Unit Testing:
11 | - https://docs.platformio.org/page/plus/unit-testing.html
12 | 


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/ThingPulse/esp32-s3-pendrive-wireless-usb-disk/2212c2a00efa1b2ec2d2c8676d8918237fe1afe6/web/favicon.ico


--------------------------------------------------------------------------------
/web/index.html:
--------------------------------------------------------------------------------
  1 | <!DOCTYPE html>
  2 | <html lang="en">
  3 | <head>
  4 |   <meta charset="UTF-8">
  5 |   <meta name="viewport" content="width=device-width, initial-scale=1.0">
  6 |   <title>File Table</title>
  7 |   <style>
  8 |     table {
  9 |       width: 100%;
 10 |       border-collapse: collapse;
 11 |     }
 12 |     th, td {
 13 |       padding: 8px 12px;
 14 |       border: 1px solid #ccc;
 15 |       text-align: left;
 16 |     }
 17 |     th {
 18 |       background-color: #f4f4f4;
 19 |     }
 20 |     tfoot {
 21 |       background-color: #f4f4f4;
 22 |     }
 23 |     .icon {
 24 |       text-align: center;
 25 |     }
 26 |     .trash-btn {
 27 |       background: none;
 28 |       border: none;
 29 |       cursor: pointer;
 30 |       color: red;
 31 |     }
 32 |     a:link, a:visited, a:hover, a:active {
 33 |         text-decoration: none;
 34 |         color: #0000BB; /* Example: color: black; */
 35 |     }
 36 |     body {
 37 |     font-family: sans-serif;
 38 | }
 39 |   </style>
 40 | </head>
 41 | <body>
 42 |   <h1>ThingPulse Pendrive S3 File Server</h1>
 43 | 
 44 |   <table border="0">
 45 |     <tr>
 46 |         <td>
 47 |             <label for="newfile">Upload a file</label>
 48 |         </td>
 49 |         <td>
 50 |             <input id="filepath" type="hidden">
 51 |             <input id="newfile" type="file" onchange="setpath()" style="width:100%;">
 52 |         </td>
 53 |     </tr>
 54 |     <tr>
 55 |         <td><a href="/settings.html">Settings</a></td>
 56 |         <td>
 57 |             <button id="upload" type="button" onclick="upload()">Upload</button>
 58 |         </td>
 59 |     </tr>
 60 |   </table>
 61 |   <table>
 62 |     <thead>
 63 |       <tr>
 64 |         <th>Name</th>
 65 |         <th>Size</th>
 66 |         <th>Action</th>
 67 |       </tr>
 68 |     </thead>
 69 |     <tbody id="cont-files">
 70 |     </tbody>
 71 |     <tfoot id="disk-info">
 72 |     </tbfoot>
 73 |   </table>
 74 | 
 75 |   <script>
 76 |     function setpath() {
 77 |         var default_path = document.getElementById("newfile").files[0].name;
 78 |         document.getElementById("filepath").value = default_path;
 79 |     }
 80 |     
 81 |     function upload() {
 82 |         var filePath = document.getElementById("filepath").value;
 83 |         var upload_path = "/upload";
 84 |         var fileInput = document.getElementById("newfile").files;
 85 |     
 86 |         /* Max size of an individual file. Make sure this
 87 |          * value is same as that set in file_server.c */
 88 |         var MAX_FILE_SIZE = 20*1024*1024;
 89 |         var MAX_FILE_SIZE_STR = "20MB";
 90 |     
 91 |         if (fileInput.length == 0) {
 92 |             alert("No file selected!");
 93 |         } else if (filePath.length == 0) {
 94 |             alert("File path on server is not set!");
 95 |         } else if (filePath.indexOf(' ') >= 0) {
 96 |             alert("File path on server cannot have spaces!");
 97 |         } else if (filePath[filePath.length-1] == '/') {
 98 |             alert("File name not specified after path!");
 99 |         } else if (fileInput[0].size > MAX_FILE_SIZE) {
100 |             alert("File size must be less than " + MAX_FILE_SIZE_STR);
101 |         } else {
102 |             document.getElementById("newfile").disabled = true;
103 |             document.getElementById("filepath").disabled = true;
104 |             document.getElementById("upload").disabled = true;
105 |     
106 |             var file = fileInput[0];
107 |             var xh = new XMLHttpRequest();
108 |             xh.onreadystatechange = function() {
109 |                 if (xh.readyState == 4) {
110 |                     if (xh.status == 200) {
111 |                         document.open();
112 |                         document.write(xh.responseText);
113 |                         document.close();
114 |                     } else if (xh.status == 0) {
115 |                         alert("Server closed the connection abruptly!");
116 |                         location.reload()
117 |                     } else {
118 |                         alert(xh.status + " Error!\n" + xh.responseText);
119 |                         location.reload()
120 |                     }
121 |                 }
122 |             };
123 |             var formData = new FormData();
124 |             formData.append("filename", file);
125 |             xh.open("POST", upload_path);
126 |             xh.send(formData);
127 |         }
128 |     }
129 |     
130 |     (function() {
131 |         var loadFiles = dir => {
132 |             var xh = new XMLHttpRequest();
133 |             xh.onreadystatechange = () => {
134 |                 if (xh.readyState == 4 && xh.status == 200) {
135 |                     var res = JSON.parse(xh.responseText);
136 |                     var cont = document.querySelector('#cont-files');
137 |                     cont.innerHTML = '';
138 |                     res.forEach(i => {
139 |                         var name = i.name.charAt(0) == '/' ? i.name.substring(1) : i.name
140 |                         var typeIcon = i.type == 'dir' ? '📁' : '📄';
141 |                         var size = formatBytes(i.size);
142 |                         cont.innerHTML +=
143 |                         `<tr>
144 |                           <td>${typeIcon} <a href="${i.name}">${name}</a></td>
145 |                           <td>${size}</td>
146 |                           
147 |                           <td>
148 |                                  <form method="post" action="/delete">
149 |                                  <input type="hidden" name="dir" value="${i.name}">
150 |                                  <button type="submit">🗑️</button>
151 |                                  </form>
152 |                           </td>
153 |                         </tr>`;
154 | 
155 |                     });
156 |                 };
157 |             };
158 |             xh.open("GET", "/api/list?dir=" + dir, true);
159 |             xh.send(null);
160 |             loadDiskInfo();
161 |         };
162 |     
163 |         loadFiles(window.location.pathname);
164 |     })();
165 | 
166 |     async function loadDiskInfo() {
167 | 
168 |       try {
169 |         const response = await fetch('/api/disk');
170 |         if (!response.ok) {
171 |           throw new Error('Network response was not ok ' + response.statusText);
172 |         }
173 |         const data = await response.json();
174 |         const diskInfoElement = document.getElementById('disk-info');
175 |         
176 |         // Construct the table row with the disk information
177 |         diskInfoElement.innerHTML = `
178 |           <tr>
179 |             <td>SD Card Total: ${formatBytes(data.total)}, Used: ${formatBytes(data.used)}, Free: ${formatBytes(data.free)}, Card-Type: ${data.cardType}, Card-Size: ${formatBytes(data.cardSize)}</td>
180 |             <td></td>
181 |             <td></td>
182 |           </tr>
183 |         `;
184 |       } catch (error) {
185 |         console.error('Error loading disk info:', error);
186 |       }
187 |     }
188 | 
189 |     // Helper function to format bytes into a more readable format
190 |     function formatBytes(bytes, decimals = 2) {
191 |       if (bytes === 0) return '0 Bytes';
192 |       const k = 1024;
193 |       const dm = decimals < 0 ? 0 : decimals;
194 |       const sizes = ['Bytes', 'KB', 'MB', 'GB', 'TB'];
195 |       const i = Math.floor(Math.log(bytes) / Math.log(k));
196 |       return parseFloat((bytes / Math.pow(k, i)).toFixed(dm)) + ' ' + sizes[i];
197 |     }
198 | 
199 |     // Load disk info when the page is loaded
200 |     //document.addEventListener('DOMContentLoaded', loadDiskInfo);
201 |     </script>
202 | </body>
203 | </html>


--------------------------------------------------------------------------------
/web/settings.html:
--------------------------------------------------------------------------------
  1 | <!DOCTYPE html>
  2 | <html lang="en">
  3 | <head>
  4 |   <meta charset="UTF-8">
  5 |   <meta name="viewport" content="width=device-width, initial-scale=1.0">
  6 |   <title>Settings</title>
  7 |   <style>
  8 |     body {
  9 |       font-family: Arial, sans-serif;
 10 |       margin: 20px;
 11 |     }
 12 |     form {
 13 |       max-width: 500px;
 14 |       margin: auto;
 15 |       padding: 20px;
 16 |       border: 1px solid #ccc;
 17 |       border-radius: 5px;
 18 |       background-color: #f9f9f9;
 19 |     }
 20 |     .form-group {
 21 |       margin-bottom: 15px;
 22 |     }
 23 |     label {
 24 |       display: block;
 25 |       margin-bottom: 5px;
 26 |     }
 27 |     input[type="text"],
 28 |     input[type="password"],
 29 |     select {
 30 |       width: 95%;
 31 |       padding: 10px;
 32 |       margin: 5px 0;
 33 |     }
 34 |     button {
 35 |       width: 100%;
 36 |       padding: 10px;
 37 |       background-color: #28a745;
 38 |       color: white;
 39 |       border: none;
 40 |       border-radius: 5px;
 41 |       cursor: pointer;
 42 |     }
 43 |     button:hover {
 44 |       background-color: #218838;
 45 |     }
 46 |   </style>
 47 | </head>
 48 | <body>
 49 |   
 50 |   <form id="settingsForm">
 51 |     <h1>Device Settings</h1>
 52 |     <div class="form-group">
 53 |       
 54 |       <label for="mode">Mode</label>
 55 |       <select id="mode">
 56 |         <option value="AP">AP</option>
 57 |         <option value="STA">STA</option>
 58 |         <option value="AP+STA">AP+STA</option>
 59 |       </select>
 60 |     </div>
 61 |     <div class="form-group">
 62 |       <label for="apSsid">AP SSID</label>
 63 |       <input type="text" id="apSsid">
 64 |     </div>
 65 |     <div class="form-group">
 66 |       <label for="apPassword">AP Password</label>
 67 |       <input type="text" id="apPassword">
 68 |     </div>
 69 |     <div class="form-group">
 70 |       <label for="staSsid">STA SSID</label>
 71 |       <input type="text" id="staSsid">
 72 |     </div>
 73 |     <div class="form-group">
 74 |       <label for="staPassword">STA Password</label>
 75 |       <input type="password" id="staPassword">
 76 |     </div>
 77 |     <button type="button" onclick="saveSettings()">Save Settings</button>
 78 |   </form>
 79 | 
 80 |   <script>
 81 |     document.addEventListener("DOMContentLoaded", () => {
 82 |       loadSettings();
 83 |     });
 84 | 
 85 |     async function loadSettings() {
 86 |       try {
 87 |         const response = await fetch('/api/settings');
 88 |         if (!response.ok) {
 89 |           throw new Error('Network response was not ok ' + response.statusText);
 90 |         }
 91 |         const data = await response.json();
 92 |         document.getElementById('mode').value = data.mode;
 93 |         document.getElementById('apSsid').value = data.apSsid;
 94 |         document.getElementById('apPassword').value = data.apPassword;
 95 |         document.getElementById('staSsid').value = data.staSsid;
 96 |         document.getElementById('staPassword').value = data.staPassword;
 97 |       } catch (error) {
 98 |         console.error('Error loading settings:', error);
 99 |       }
100 |     }
101 | 
102 |     async function saveSettings() {
103 |       const staPassword = document.getElementById('staPassword').value;
104 |       const settings = {
105 |         mode: document.getElementById('mode').value,
106 |         apSsid: document.getElementById('apSsid').value,
107 |         apPassword: document.getElementById('apPassword').value,
108 |         staSsid: document.getElementById('staSsid').value,
109 |         staPassword: document.getElementById('staPassword').value,
110 |       };
111 |       if (staPassword === '' || staPassword === 'undefined') {
112 |         delete settings.staPassword;
113 |       }
114 | 
115 |       try {
116 |         const response = await fetch('/api/settings', {
117 |           method: 'POST',
118 |           headers: {
119 |             'Content-Type': 'application/json'
120 |           },
121 |           body: JSON.stringify(settings)
122 |         });
123 | 
124 |         if (!response.ok) {
125 |           throw new Error('Network response was not ok ' + response.statusText);
126 |         }
127 | 
128 |         // If you need to restart the device after settings are saved, you can handle that here
129 |         alert('Settings saved successfully');
130 |         // Optionally restart logic here, e.g., await fetch('/api/restart', { method: 'POST' });
131 | 
132 |       } catch (error) {
133 |         console.error('Error saving settings:', error);
134 |       }
135 |     }
136 |   </script>
137 | </body>
138 | </html>


---------------------------------------------------------