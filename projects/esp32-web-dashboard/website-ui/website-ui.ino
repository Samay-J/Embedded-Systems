#include <WiFi.h>

// Replace with your network credentials
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

// Set up a web server on port 80
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi");
  Serial.print("ESP32 IP Address: ");
  Serial.println(WiFi.localIP());
  
  // Start the server
  server.begin();
}

void loop() {
  WiFiClient client = server.available(); // Listen for incoming clients
  
  if (client) {
    Serial.println("New client connected");
    String request = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        request += c;
        if (c == '\n') break; // End of the request
      }
    }
    
    // Send a simple web page
    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/html");
    client.println();
    client.println("<!DOCTYPE html>");
    client.println("<html>");
    client.println("<head><title>ESP32 Web Server</title></head>");
    client.println("<body>");
    client.println("<h1>Welcome to ESP32 Web Server</h1>");
    client.println("<p>This is a simple website hosted on ESP32.</p>");
    client.println("</body>");
    client.println("</html>");
    client.println();
    client.stop();
    Serial.println("Client disconnected");
  }
}
