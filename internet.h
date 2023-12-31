#ifndef INTERNET_H
#define INTERNET_H

#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>

class InternetUGM {
    private:
    const char* ssid = "UGM-Hotspot";
    const char* url  = "https://sso.ugm.ac.id/cas/login?service=https://internet.ugm.ac.id/sso/login";
    String username;
    String password;
    WiFiClientSecure client;

    public:
    InternetUGM(String username, String password);
    ~InternetUGM();
    int begin(WiFiClientSecure &client, HTTPClient &http);
};

#endif