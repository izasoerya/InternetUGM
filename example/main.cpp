#include <Arduino.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>

#include "internet.h"

const char *username = "<your_email>"; // without @mail.ugm.ac.id
const char *password = "<your_password>";

WiFiClientSecure wifi;
HTTPClient http;
InternetUGM inet(username, password);

void setup()
{
	Serial.begin(115200);

	// Connect to WiFi
	wifi.setInsecure(); // It's fine for testing
	int responseCode = inet.begin(wifi, http);
	if (responseCode == 200 || responseCode == 201)
		Serial.println("Success connected to WiFi\n");
	else
		Serial.printf("Failed to connect to WiFi: %d\n", responseCode);
}

void loop()
{
	// Test connection to Internet
	http.begin(wifi, "https://tester-ugm.free.beeceptor.com");
	int responseCode = http.GET();
	Serial.printf("Res Code: %d | Body: %s\n", responseCode, http.getString().c_str());
	http.end();

	delay(15000);
}