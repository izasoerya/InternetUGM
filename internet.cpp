#include <Arduino.h>
#include "internet.h"

InternetUGM::InternetUGM(String username, String password){
    this -> username = username;
    this -> password = password;
}

InternetUGM::~InternetUGM(){}

int InternetUGM::begin(WiFiClientSecure &client, HTTPClient &http){
    WiFi.mode(WIFI_STA); 
    WiFi.begin(ssid);
    
    while (WiFi.status() != WL_CONNECTED);
    Serial.println(WiFi.localIP());

    char jsonString[255];
    snprintf(jsonString, sizeof(jsonString),
             "{\"username\":\"%s\",\"password\":\"%s\",\"_eventId\":\"submit\",\"submit\":\"login\"}",
             username, password);

    client.setInsecure();

    http.begin(client, url);
    int httpResponseCode = http.POST(jsonString);
    http.end();
    return httpResponseCode;
}
