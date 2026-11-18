#include <Arduino.h>
#include "internet.h"

InternetUGM::InternetUGM(const char *username, const char *password)
    : _username(username), _password(password) {}

InternetUGM::~InternetUGM() {}

int InternetUGM::begin(WiFiClientSecure &client, HTTPClient &http)
{
    bool init = false;
    while (WiFi.status() != WL_CONNECTED)
        if (!init)
        {
            WiFi.mode(WIFI_STA);
            WiFi.begin(_ssid);
            init = true;
        }

    char jsonString[128];
    snprintf(jsonString, sizeof(jsonString),
             "{\"username\":\"%s\",\"password\":\"%s\",\"_eventId\":\"submit\",\"submit\":\"login\"}",
             _username, _password);

    http.begin(client, _url);
    int httpResponseCode = http.POST(jsonString);
    http.end();
    return httpResponseCode;
}
