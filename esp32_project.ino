#include <HTTPClient.h>

#include <WiFi.h>
// #include <HTTPClient.h>

const char* ssid = "HUAWEI_E5783_AD9C";
const char* pass = "0561533776";
// 172.20.10.2
const char* serverUrl = "http://192.168.8.28/robot_control/retrieve1.php";
void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, pass);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
}

void loop() {
    // Make an HTTP GET request
    HTTPClient http;
    http.begin(serverUrl);

    int httpResponseCode = http.GET();
    if (httpResponseCode == 200) {
        String response = http.getString();
        Serial.print("Received data: ");
        Serial.println(response);
    } else {
        Serial.print("Error fetching data. HTTP response code: ");
        Serial.println(httpResponseCode);
    }

    http.end();

    delay(5000); // Fetch data every 5 seconds
}
