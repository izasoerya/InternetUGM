#include <Arduino.h>
#include "internet.h"

InternetUGM::InternetUGM(WiFiClientSecure &client, char* username, char* password){
    this -> username = username;
    this -> password = password;
    this -> client = client;
}

InternetUGM::~InternetUGM(){}

int InternetUGM::begin(HTTPClient &http){
    WiFi.mode(WIFI_STA); 
    WiFi.begin(ssid);
    
    char jsonString[72];
    snprintf(jsonString, sizeof(jsonString),
             "{\"username\":\"%s\",\"password\":\"%s\",\"_eventId\":\"submit\",\"submit\":\"login\"}",
             username, password);

    client.setInsecure();

    http.begin(client, url);
    int httpResponseCode = http.POST(jsonString);
    http.end();
    return httpResponseCode;
}
