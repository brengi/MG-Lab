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


#define SSID_ADDR     0       // Start address Flash Memory for Ssid
#define PASS_ADDR     35      // Start address Flash Memory for Pass
#define EEPROM_BLOCK  128     // Size of Flash Memory block
#define FLAG_ADDR     127
/*
#define HOSTIFTTT     "maker.ifttt.com"
#define EVENTO        "BotonDeAuxilio"
#define IFTTTKEY      "fXBQCJmM4axyyRzbZzgH7i0DkpIhM_Z-855a_3SOlaS" // My IFTTT key of event
*/
#define url           "https://maker.ifttt.com/trigger/BotonDeAuxilio/with/key/fXBQCJmM4axyyRzbZzgH7i0DkpIhM_Z-855a_3SOlaS" 

BluetoothSerial Esp32;            // Create a Bluetooth class object
HTTPClient      http;

const char *ssid;
const char *pass;
//String url;                    // webpage to connect for trigger event IFTTT


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

/* ------------- Busca redes WiFi Disponibles ---------------------*/
void ScanNetworks(void)
{
  char network = WiFi.scanNetworks();
  char incoming = 0;
  String names[network];

  if(network)
  {
    for(char i = network; i > 0; i--)
    {
      names[network - i] = WiFi.SSID(network - i);
      Esp32.print((network -i)+1,DEC);
      Esp32.print(" )");
      Esp32.println(names[network - i]);
      delay(100);
    }
  }
  else
  {
    Esp32.println("No Networks Found");
  }
  Esp32.println("Choose the network to connect");

 while(!Esp32.available())    // Wait for enter choise  
  {
    continue;
  }
  incoming = Esp32.read();
  write_eeprom(SSID_ADDR,names[(incoming -48)-1]);   // Load the SSID of the Network in Flash Memory
  Esp32.print("Your Choise: ");
  Esp32.println(names[(incoming -48)-1]); 
}

/* -------------- Pide la Pass de la red ---------------------*/
void GetPassword(void)
{
  String Pass = "";
  char incoming = 0;
  Esp32.println("Enter your password");
  while(!Esp32.available())        // Wait for enter choise
  {
     continue;
  }
  do
  {
    incoming = Esp32.read();
    Pass += (char)incoming;              // Converted the ASCII code to character
  }while(Esp32.available() != 0);
  write_eeprom(PASS_ADDR,Pass);          // Load the PASS of the Network in Flash Memory
  write_eeprom(FLAG_ADDR,(String)1);     // Pass like parameter the number 1 
}

/* ---------- Configuración de la Red Wifi por BlueTooth -------------*/

void Device_Config(void)
{
  char wrong = 1;
  char incoming = 0;
  WiFi.disconnect();
  Esp32.begin("ESP32_BT");   // Name of the BlueTooth Signal
  if(!Esp32.available())
  {
    delay(6000);    // Give a little time to conect the device
    Esp32.println("Push the s key to begining");
    while(wrong)
    {    
      wrong = 0;
      while(!Esp32.available())     // Wait for enter choise
      {
        continue;
      }
      incoming = Esp32.read();
      if(incoming == 115 || incoming == 83)
      {
        Esp32.println("Device Set-Up start's");
        ScanNetworks();
        GetPassword();
      }
      else
      {
        Esp32.println("That's wrong key");
        Esp32.println("Please enter the s letter");
        wrong = 1;
      }      
    }
  }
}

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
     Device_Config();
  } 
}

void setup() {

  int flag;
//  PORTS_SETUP; 
  Serial.begin(115200);
  EEPROM.begin(EEPROM_BLOCK);    // Inicio la eeprom para poder escribir con 130 bytes de bloque 
  flag = read_eeprom(FLAG_ADDR).toInt();
  if(flag == 0)       // Means that the device ins't configured
  {
    Device_Config();  // Start communication via BT and Get the SSID & PASS of Network desired
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
 // Here is when triggered the event on IFTTT       
      http.begin(url);              // Connection beginning
      int httpCode = http.GET();    // Make request
      http.end();
    }
}
