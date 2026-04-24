#ifndef WEB_PAGES_H
#define WEB_PAGES_H

#include <Arduino.h>

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <title>ESP32 Async Web Server</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    html {font-family: Arial; display: inline-block; text-align: center;}
    h2 {font-size: 3.0rem;}
    p {font-size: 3.0rem;}
    .units {font-size: 1.2rem;}
    .labels{font-size: 1.5rem; vertical-align:middle; padding-bottom: 15px;}
  </style>
</head>
<body>
  <h2>ESP32 Web Server</h2>
  <p>
    <i class="fas fa-thermometer-half" style="color:#059e8a;"></i> 
    <span class="labels">Uptime:</span> 
    <span id="uptime">%UPTIME%</span>
    <span class="units">ms</span>
  </p>
  <p>
    <i class="fas fa-bolt" style="color:#00add8;"></i>
    <span class="labels">Status:</span>
    <span id="status">%STATUS%</span>
  </p>
</body>
</html>)rawliteral";

#endif
