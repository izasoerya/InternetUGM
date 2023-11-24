#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>
#include "internet.h"

// Put your email (without ugm.ac.id) and passwords in here
char* username = "";
char* password = "";

WiFiClientSecure wifi;
HTTPClient http;
InternetUGM inet(wifi, username, password);

void setup(){
	Serial.begin(115200);
	int responseCode = inet.begin(http);
	if (responseCode != 200) {
		Serial.println("Error Code: ");
		Serial.println(responseCode);
	}
}

void loop(){
	// Put your loop code here

}