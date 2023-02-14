#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <SD.h>

class ESP8266RestAPI {
  public:
    ESP8266RestAPI();
    void begin();
    void handleClient();
    
  private:
    ESP8266WebServer server;
    void handleRoot();
    void handleNotFound();
    void handleGetFile();
    void handlePutFile();
};

ESP8266RestAPI::ESP8266RestAPI() {
  server = ESP8266WebServer(80);
}

void ESP8266RestAPI::begin() {
  server.on("/", HTTP_GET, handleRoot);
  server.on("/file", HTTP_GET, handleGetFile);
  server.on("/file", HTTP_PUT, handlePutFile);
  server.onNotFound(handleNotFound);
  
  server.begin();
}

void ESP8266RestAPI::handleClient() {
  server.handleClient();
}

void ESP8266RestAPI::handleRoot() {
  server.send(200, "text/html", "<h1>Welcome to the ESP8266 REST API</h1><p>This API allows you to read and write files on the connected microSD card.</p><p>To get a file, make a GET request to /file?filename=<i>filename</i></p><p>To put a file, make a PUT request to /file?filename=<i>filename</i> with the file contents in the request body.</p>");
}

void ESP8266RestAPI::handleNotFound() {
  server.send(404, "text/plain", "404: Not Found");
}

void ESP8266RestAPI::handleGetFile() {
  String filename = server.arg("filename");
  if (!SD.exists(filename)) {
    server.send(404, "text/plain", "404: File Not Found");
    return;
  }
  
  File file = SD.open(filename, FILE_READ);
  server.streamFile(file, "application/octet-stream");
  file.close();
}

void ESP8266RestAPI::handlePutFile() {
  String filename = server.arg("filename");
  File file = SD.open(filename, FILE_WRITE);
  file.write((uint8_t)server.arg(0).c_str(), server.arg(0).length());
  file.close();
  server.send(200, "text/plain", "200: OK");
}
