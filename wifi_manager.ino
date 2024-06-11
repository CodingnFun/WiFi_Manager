#include <WiFiManager.h>

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

  // Initialize WiFiManager
  WiFiManager wm;

  // Optionally, reset settings for testing
  wm.resetSettings();

  // Set timeout for connection attempt
  wm.setConfigPortalTimeout(180);  // Timeout in seconds for the config portal
  wm.setConnectTimeout(30);  // Timeout in seconds for connecting to WiFi

  bool res;

  // Attempt to auto-connect to WiFi
  res = wm.autoConnect("MyWiFi", "iot123456");

  if (!res) {
    Serial.println("Failed to Connect to WiFi");
  } else {
    Serial.println("Connected..");
    // Print ESP Local IP Address
    Serial.println(WiFi.localIP());
  }
}

void loop() {
  // Your loop code here
}
