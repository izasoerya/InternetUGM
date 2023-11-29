# Internet UGM-Hotspot

This repository contain program for connecting to UGM-Hotspot WiFi using ESP32 in Arduino Framework. This is for educational purpose only, DO NOT USE THIS FOR COMMERCIAL USE!

## Installation

- PlatformIo
1. Open your platformio.ini file in your project folder.
2. Add https://github.com/izasoerya/InternetUGM to your lib_deps
```bash
lib_deps = https://github.com/izasoerya/InternetUGM 
```
3. Save the file

- Arduino IDE
1. Download the library in .zip file
2. Extract to folder libraries inside Arduino folder

## Usage
You need a WiFi and HTTP handler such as the one built-in ESP32. Here i use the ESP32 default WiFi and HTTP handler.

```cpp
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>
#include <internet.h>

String username = "";
String password = "";

WiFiClientSecure wifi;
HTTPClient http;
InternetUGM inet(username, password);

void setup(){
	Serial.begin(115200);
	int responseCode = inet.begin(wifi, http);
	Serial.println(responseCode);

	// Test connection to Internet
	http.begin(wifi, "https://httpbin.org/get");
	http.GET();
	Serial.println(http.getString());
	http.end();
}

void loop(){
	// Put your loop code here
}
```

## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

[MIT](https://choosealicense.com/licenses/mit/)