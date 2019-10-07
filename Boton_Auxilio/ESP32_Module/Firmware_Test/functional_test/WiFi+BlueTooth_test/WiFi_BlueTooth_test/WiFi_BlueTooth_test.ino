/**************************************************************************
 * Programa de prueba para el uso del ESP32  con la conexión WIFI y BlueTooth. 
 * Se basa en los test WiFi_test y BlueTooth_test y en conjunto con los   
 * ejemplos que posee el  IDE para el modulo ESP32
 * Por Gustavo Rodríguez - INTI CMNB
 *************************************************************************/

#include "MyDefines.h"            // Include the header file with my definitions


BluetoothSerial Esp32;            // Create a Bluetooth class object
WiFiServer      server(80);       // Set WebServer Port


/*************************************************************************
 * Aqui se debe colocar el Nombre y la contraseña de la red WiFi a la 
 * cual se desea conectar
 *************************************************************************/
 // Network credentials
 const char *ssid;
 const char *pass;


char info;
int incoming;

void setup() {

  PORTS_SETUP; 
  LedsOff;
/***********************************  
 *  Start BlueTooth communication  *   
 ***********************************/
 Serial.begin(115200);
 Esp32.begin("ESP32_BT");   // Name of the BlueTooth Signal
 Serial.println("The BlueTooth device is ready to link");
  
}

void loop() {
  

}
