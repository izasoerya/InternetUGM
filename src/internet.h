#ifndef INTERNET_H
#define INTERNET_H

#include <WiFiClientSecure.h>
#include <HTTPClient.h>

class InternetUGM
{
private:
    const char *_username;
    const char *_password;
    const char *_ssid = "UGM-Hotspot";
    const char *_url = "https://sso.ugm.ac.id/cas/login?service=https://internet.ugm.ac.id/sso/login";

public:
    InternetUGM(const char *username, const char *password);
    ~InternetUGM();
    int begin(WiFiClientSecure &client, HTTPClient &http);
};

#endif