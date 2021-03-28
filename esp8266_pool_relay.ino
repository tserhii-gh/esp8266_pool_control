#include <ESP8266WiFi.h>

#define LED_BUILTIN 2
const char* ssid     = "POOL_ROC"; // The SSID (name) of the Wi-Fi network you want to connect to
const char* password = "";

void setup()
{
    Serial.begin(115200); // Start the Serial communication to send messages to the computer
    delay(10);
    Serial.println('\n');

    WiFi.begin(ssid, password); // Connect to the network
    Serial.print("Connecting to ");
    Serial.print(ssid);
    Serial.println(" ...");
    pinMode(LED_BUILTIN, OUTPUT); // Initialize the LED_BUILTIN pin as an output
    int i = 0;
    while (WiFi.status() != WL_CONNECTED)
    { // Wait for the Wi-Fi to connect
        delay(1000);
        Serial.print(++i);
        Serial.print(' ');
    }

    Serial.println('\n');
    Serial.println("Connection established!");
    Serial.print("IP address:\t");
    Serial.println(WiFi.localIP());
}

void loop()
{
    digitalWrite(LED_BUILTIN, LOW); // Turn the LED on by making the voltage LOW
    delay(1000);                    // Wait for a second
    digitalWrite(LED_BUILTIN,
        HIGH);   // Turn the LED off by making the voltage HIGH
    delay(2000); // Wait for two seconds
}
