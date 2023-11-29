#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>
#include "internet.h"

String username = "";
String password = "";

WiFiClientSecure wifi;
HTTPClient http;
InternetUGM inet(username, password);

void setup(){
	Serial.begin(115200);
	int responseCode = inet.begin(wifi, http);
	if (responseCode != 200) {
		Serial.println("Error Code: ");
		Serial.println(responseCode);
	}

	http.begin(wifi, "https://httpbin.org/get");
	http.GET();
	Serial.println(http.getString());
	http.end();
}

void loop(){
	// Put your loop code here

}