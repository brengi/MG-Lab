/****************************************************************************
 * Programa de prueba para el uso del ESP32  con la conexión Bluetooth a una 
 * aplicación andriod de Terminal Bluetooth. Adaptado de un ejemplo conseguido 
 * en https://circuitdigest.com/microcontroller-projects/using-classic-bluetooth-in-esp32-and-toogle-an-led 
 * por Gustavo Rodríguez - INTI CMNB
 ***************************************************************************/

#include <BluetoothSerial.h>
#include <Ticker.h>          // Cargo libreria para blinkear al led

 BluetoothSerial Obj_Esp_Bt; // Create a Bluetooth class object
 int incoming;
  // Set the GPIO Ports
const int green = 25;        // Port P25 --> Green Led
const int yellow = 26;       // Port P26 --> Yellow Led
const int red = 27;          // Port P27 --> Red Led
const int LED_ONBOARD = 2;   // Port P2 --> Led OnBoard ESP32

int data = 0;
volatile char state_P25 = 0;
volatile char state_P26 = 0;
volatile char state_P27 = 0; 



void setup() {

  //Configure the Ports like outputs and set low state
  pinMode(green,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(LED_ONBOARD,OUTPUT);
  digitalWrite(green,LOW);
  digitalWrite(yellow,LOW);
  digitalWrite(red,LOW);
  digitalWrite(LED_ONBOARD,LOW);

  Serial.begin(9600);
  Obj_Esp_Bt.begin("ESP32_BT"); // Name of the BlueTooth signal
  Serial.println("");
  Serial.println("/************************************/");
  Serial.println("The BlueTooth device is ready to link");
  Serial.println("/************************************/");

}

void loop() {

  // The BlueTooth device is sending a message
  if(Obj_Esp_Bt.available())
  {
    incoming = Obj_Esp_Bt.read(); // Read the message sending
    Serial.print("Received:  ");
    Serial.println(incoming);     // Showing on the Serial Monitor the message 

    data = incoming - 48;         // Convert the ASCII code to decimal value
  
    if((data >= 0) && (data <= 2)) // Verifyd that the data is valid
    {
      switch (data) 
      {
            case 0:
                    if(!state_P25)
                    {
                      digitalWrite(green,HIGH); // Turn-on the green led
                      Obj_Esp_Bt.println("Green Led Turn-On"); // Send message to BlueTooth device  
                      state_P25 = 1;                  
                    }
                    else
                    {
                      digitalWrite(green,LOW); // Turn-off the green led
                      Obj_Esp_Bt.println("Green Led Turn-Off"); // Send message to BlueTooth device 
                      state_P25 = 0;
                    }
                   ;
                    break;

            case 1:
                   if(!state_P26)
                    {
                      digitalWrite(yellow,HIGH); // Turn-on the yellow led
                      Obj_Esp_Bt.println("Yellow Led Turn-On"); // Send message to BlueTooth device  
                      state_P26 = 1;                  
                    }
                    else
                    {
                      digitalWrite(yellow,LOW); // Turn-off the green led
                      Obj_Esp_Bt.println("Yellow Led Turn-Off"); // Send message to BlueTooth device 
                      state_P26 = 0;
                    }
                    data = 0;
                    break;

            case 2:
                   if(!state_P27)
                    {
                      digitalWrite(red,HIGH); // Turn-on the red led
                      Obj_Esp_Bt.println("Red Led Turn-On"); // Send message to BlueTooth device    
                      state_P27 = 1;                
                    }
                    else
                    {
                      digitalWrite(red,LOW); // Turn-off the green led
                      Obj_Esp_Bt.println("Red Led Turn-Off"); // Send message to BlueTooth device 
                      state_P27 = 0;
                    }
                    data = 0;
                    break;
            default:
                   data = 0;   
             
      } // Close the Switch case statement  
    }
    else
    {
      Obj_Esp_Bt.println("The option choosen is not valided"); // Send message to BlueTooth device 
    }
  }   // Close the if(Obj_Esp_Bt.available())

  delay(2000);
}
