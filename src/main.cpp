#include <Arduino.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include "web_pages.h"

// Replace with your network credentials
const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

AsyncWebServer server(80);

const int ledPin = 2; // Onboard LED

// Processor function to handle dynamic content
String processor(const String& var) {
    if (var == "UPTIME") {
        return String(millis());
    } else if (var == "STATUS") {
        return "Connected";
    }
    return String();
}

void setup() {
    Serial.begin(115200);
    pinMode(ledPin, OUTPUT);

    // Connect to Wi-Fi
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());

    // Route for root / web page
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send_P(200, "text/html", index_html, processor);
    });

    // Task 2: Interactive Control Lab - /set_led?value=128
    server.on("/set_led", HTTP_GET, [](AsyncWebServerRequest *request){
        String message;
        if (request->hasParam("value")) {
            String val = request->getParam("value")->value();
            int intVal = val.toInt();
            
            // Security Boundary Check (Task 2)
            if (intVal >= 0 && intVal <= 255) {
                analogWrite(ledPin, intVal);
                message = "LED value set to " + val;
                request->send(200, "text/plain", message);
            } else {
                request->send(400, "text/plain", "400 Bad Request: Value must be between 0 and 255");
            }
        } else {
            request->send(400, "text/plain", "400 Bad Request: Missing 'value' parameter");
        }
    });

    // Start server
    server.begin();
}

void loop() {
    // Empty loop! The server is asynchronous.
}
