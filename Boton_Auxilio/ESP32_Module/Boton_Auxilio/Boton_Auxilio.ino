/**************************************************************************
 * Programa base para el ESP32 a ser utilizado en el proyecto 
 * BOTON de AUXILIO con conectividad a red WiFi y configuración mediante 
 * conexión BlueTooth
 * Es para las tutorias del MGLAB 
 * Por Gustavo Rodríguez - INTI CMNB
 *************************************************************************/


#include <EEPROM.h>               // Eeprom library 
#include <WiFi.h>                 // WiFi library arduino's for ESP32
#include <BluetoothSerial.h>      // BlueTooth library arduino's for ESP32
#include <HTTPClient.h>



#define GREEN_LED     25      // Port P25 --> Green led
#define YELLOW_LED    26      // Port P26 --> Yellow led
#define RED_LED       27      // Port P27 --> Red led
#define SSID_ADDR     0       // Start address Flash Memory for Ssid
#define PASS_ADDR     35      // Start address Flash Memory for Pass
#define EEPROM_BLOCK  128     // Size of Flash Memory block
#define FLAG_ADDR     127

#define HOSTIFTTT     "maker.ifttt.com"
#define EVENTO        "BotonDeAuxilio"
#define IFTTTKEY      "fXBQCJmM4axyyRzbZzgH7i0DkpIhM_Z-855a_3SOlaS" // My IFTTT key of event
#define PORT           443


// Set-Up the ports as outputs
#define PORTS_SETUP  (pinMode(GREEN_LED,OUTPUT),pinMode(RED_LED,OUTPUT), \
                      pinMode(YELLOW_LED,OUTPUT))
// Turn-On the leds
#define GreenOn      (digitalWrite(GREEN_LED,HIGH))
#define YellowOn     (digitalWrite(YELLOW_LED,HIGH))
#define RedOn        (digitalWrite(RED_LED,HIGH))

// Turn-Off the leds
#define GreenOff      (digitalWrite(GREEN_LED,LOW))
#define YellowOff     (digitalWrite(YELLOW_LED,LOW))
#define RedOff        (digitalWrite(RED_LED,LOW))

#define LedsOff      (GreenOff,YellowOff,RedOff)


BluetoothSerial Esp32;            // Create a Bluetooth class object
HTTPClient      http;

const char *ssid;
const char *pass;
String url;                    // webpage to connect for trigger event IFTTT


/* --------------------- Grabar en Flash Memory ----------------------- */
void write_eeprom(int addr,String Name)
{
/* tomo las longitud del dato de la red a utilizar, a priori 
 * no se que longitud tiene cada parametro */
  int tamanio = Name.length();
  
// creo el vector para almacenar los datos en la Eeprom
  char datos[tamanio];
/* convierto el string a caracteres para almacenarlos en la eeprom */
  Name.toCharArray(datos,tamanio + 1);
  for(int i = 0; i <= tamanio; i++)
  {
      if(i == tamanio)
      {
        EEPROM.write(addr + i, '\0');
      }
      else
      {
        EEPROM.write(addr + i, datos[i]);
      }
  }
  EEPROM.commit();    // Si no está, no se graban los datos en la Flash!!!!
}

/* ------------------ Leer de Flash Memory ------------------------*/
String read_eeprom(int addr)
{
  byte reading;
  String readStr;
  for(int i = addr; i < EEPROM_BLOCK; i++)
  {
    reading = EEPROM.read(i);   // Get data of memory address
    if(reading == '\0')
    {
      readStr += (char)reading;
      return readStr;
    }
    readStr += (char)reading;
  }
}

/* ---------- Configuración de la Red Wifi por BlueTooth -------------*/
/*
void Device_Config(void)
{
  char incoming = 0;
  char wait = 1;
  char wrong = 1;
  WiFi.disconnect();
  Esp32.begin("ESP32_BT");   // Name of the BlueTooth Signal
//  Serial.println("**************************************");
//  Serial.println("The BlueTooth device is ready to link");
//  Serial.println("**************************************");
  GreenOn;
  if(Esp32.available() <= 0)
  {
    delay(6000);    // Give a little time to conect the device
    Esp32.println("Push the s key to begining");
    while(wrong)
    {    
      wrong = 0;
      while(wait)     // Wait for enter choise
      {
        if(Esp32.available() > 0)
        {
          wait = 0;   // break the loop, means enter the s key
        } 
      }
      incoming = Esp32.read();
      if(incoming == 115 || incoming == 83)
      {
        Esp32.println("Device Set-Up start's");
        int network = 0;                        // Amount of netwoks availables in the zone 
        network = WiFi.scanNetworks();          // Scan for availables networks
        String names[network];                  // Vector with SSID Name
        if(network)
        {
          Esp32.print(network); 
          Esp32.println(" netwoks found");
          for(int i = 0; i < network; i++)
          {
            names[i] = WiFi.SSID(i);            // ID network stored
            Esp32.print(i + 1, DEC);
            Esp32.print(" ) ");
            Esp32.println(names[i]);           // List on BlueTooth Device
            delay(100);
          }  
        }
        else 
        {
          Esp32.println("No Networks Found");
        }
        Esp32.println("Choose the network to connect");
        wait = 1;
        char pos;
        while(wait)    // Wait for enter choise  
        {
          if(Esp32.available() > 0)
          {
            wait = 0; // Broken the loop, incoming data
            incoming = Esp32.read();
            pos = (incoming -48)-1;               // Converted the ASCII code to character and indexing with vectors' name
            write_eeprom(SSID_ADDR,names[pos]);   // Load the SSID of the Network in Flash Memory
            Esp32.print("Your Choise: ");
            Esp32.println(names[pos]); 
          }
        }
        wait = 1;
        String pas;
        Esp32.println("Enter your password"); 
        while(wait)        // Wait for enter choise
        {
          if(Esp32.available() > 0)
          {
            wait = 0;                              // Broken the loop, incoming data
            do
            {
              incoming = Esp32.read();
              pas += (char)incoming;              // Converted the ASCII code to character
            }while(Esp32.available() != 0);
          }
        }
        write_eeprom(PASS_ADDR,pas);              // Load the PASS of the Network in Flash Memory
/*Set the flag in Flash memory with the porpouse to make only one time the process of
 * configure the device into the network */
/*        write_eeprom(FLAG_ADDR,(String)1);       // Pass like parameter the number 1 
      }
      else
      {
        Esp32.println("That's wrong key");
        Esp32.println("Please enter the s letter");
        wrong = 1;
        wait = 1;
      }      
    }
  }
}
*/
char wifi_connect(void)
{
  char count = 0; 
  WiFi.mode(WIFI_STA);
  delay(4000);
  WiFi.begin(ssid,pass);
  while(WiFi.status() != WL_CONNECTED && count < 50)
  {
    delay(500);
    count += 1;    // keep track of connection attempts
  }
  if(count == 50)
  {
    write_eeprom(FLAG_ADDR,(String)0);
  }
  return count;
}

void wifi_setup(void)
{
  char Status = 0;
/* Geting of Flash Memory the SSID and PASS of Network to connect */
      ssid = read_eeprom(SSID_ADDR).c_str();
      pass = read_eeprom(PASS_ADDR).c_str();
      Status = wifi_connect(); 
      if(Status == 50)
      {
         //Device_Config();
      } 
}

void clear_eeprom(void)
{
  for(int addr = 0; addr < EEPROM_BLOCK; addr++)
  {
    EEPROM.write(addr,'0');
  }
  EEPROM.commit();
}


void setup() {

  int flag;
  PORTS_SETUP; 
  LedsOff;
  Serial.begin(115200);
  EEPROM.begin(EEPROM_BLOCK);    // Inicio la eeprom para poder escribir con 130 bytes de bloque 
//  clear_eeprom();
//  delay(3000);
  flag = read_eeprom(FLAG_ADDR).toInt();
  if(flag == 0)       // Means that the device ins't configured
  {
   // Device_Config();  // Start communication via BT and Get the SSID & PASS of Network desired
    wifi_setup();
  }
  else
  {
    wifi_setup();
  }
  Serial.println("Termino la función setup");
}

void loop() {
 

    if(WiFi.status() == WL_CONNECTED)    // Wifi connection successful
    {
    // make the url webpage to connect and trigger event  
        url  = "https://";
        url += HOSTIFTTT;
        url += "/trigger/";
        url += EVENTO;
        url += "/with/key/";
        url += IFTTTKEY;

 // Here is when triggered the event on IFTTT       
        http.begin(url);              // Connection beginning
        int httpCode = http.GET();    // Make request
               
        if(httpCode > 0)  // Check for the returning code
        {
          String httpRequest = http.getString(); // Take the IFTTT response 
        }
        else
        {
          Serial.println();
          Serial.println("Error en respuesta HTTP");
        }
        http.end();
    }
    else
    {
      Serial.println();
      Serial.println("La conexión WiFi se perdió");
    }
}
