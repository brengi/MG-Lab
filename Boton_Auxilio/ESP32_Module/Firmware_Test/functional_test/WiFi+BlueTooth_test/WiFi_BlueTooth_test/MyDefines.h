#ifndef MyDefines.h_
#define MyDefines.h_

#include <WiFi.h>                 // WiFi library arduino's for ESP32
#include <Ticker.h>               // Blinking led library arduino's for ESP32
#include <BluetoothSerial.h>      // BlueTooth library arduino's for ESP32


#define LED_ONBOARD   2       // Port P2  --> led on board ESP32 DEVKIT V1
#define GREEN_LED     25      // Port P25 --> Green led
#define YELLOW_LED    26      // Port P26 --> Yellow led
#define RED_LED       27      // Port P27 --> Red led

// Set-Up the ports as outputs
#define PORTS_SETUP  (pinMode(LED_ONBOARD,OUTPUT),pinMode(GREEN_LED,OUTPUT),\
                      pinMode(YELLOW_LED,OUTPUT),pinMode(RED_LED,OUTPUT))
// Turn-On the leds
#define GreenOn      (digitalWrite(GREEN_LED,HIGH))
#define YellowOn     (digitalWrite(YELLOW_LED,HIGH))
#define RedOn        (digitalWrite(RED_LED,HIGH))

// Turn-Off the leds
#define GreenOff      (digitalWrite(GREEN_LED,LOW))
#define YellowOff     (digitalWrite(YELLOW_LED,LOW))
#define RedOff        (digitalWrite(RED_LED,LOW))

#define LedsOff      (GreenOff,YellowOff,RedOff)

String state_P25 = "off";
String state_P26 = "off";
String state_P27 = "off";

#endif MyDefines.h_
