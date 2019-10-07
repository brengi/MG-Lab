/*
 *  This sketch demonstrates how to scan WiFi networks.
 *  The API is almost the same as with the WiFi Shield library,
 *  the most obvious difference being the different file you need to include:
 */
#include "WiFi.h"

String ssid;

void setup()
{
    Serial.begin(115200);

    // Set WiFi to station mode and disconnect from an AP if it was previously connected
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(500);

    Serial.println("Setup done");
}

void loop()
{
    Serial.println("scan start");

    // WiFi.scanNetworks will return the number of networks found
    int n = WiFi.scanNetworks();
    String ssid[n];
    Serial.println("scan done");
    if (n == 0) {
        Serial.println("no networks found");
    } else {
        Serial.print(n);
        Serial.println(" networks found");
        for (int i = 0; i < n; ++i) {
            // Print SSID and RSSI for each network found
            Serial.print(i + 1);
            Serial.print(": ");
            Serial.print(WiFi.SSID(i));
            Serial.print(" (");
            Serial.print(WiFi.RSSI(i));
            Serial.print(")");
            Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
            Serial.print(" ");
            Serial.println();
            ssid[i] = WiFi.SSID(i);   // Store the ID of the Network
          //  Serial.println(ssid);
            delay(1000);
        }
        Serial.println("El SSID Almacenado en el vector es");
        for(char j = 0; j < n; j++)
          {
            Serial.print(j+1,DEC);
            Serial.print(" ");
            Serial.println(ssid[j]);
            delay(2000);
          }
       Serial.println("Fin de la lista almacenada");   
    }
    Serial.println("");

    // Wait a bit before scanning again
    delay(5000);
}
