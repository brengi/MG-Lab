/**************************************************************************
 * Programa de prueba para el uso del ESP32  con la conexión WIFI y BlueTooth. 
 * Se basa en los test WiFi_test y BlueTooth_test y en conjunto con los   
 * ejemplos que posee el  IDE para el modulo ESP32. 
 * Las impresiones al monitor serial que presenta el IDE son a modo de 
 * Debbuger de la lógica y verificación del correcto funcionamiento de 
 * la misma.
 * Por Gustavo Rodríguez - INTI CMNB
 *************************************************************************/

#include <Ticker.h>               // Blinking led library arduino's for ESP32
#include <BluetoothSerial.h>      // BlueTooth library arduino's for ESP32
#include <WiFi.h>                 // WiFi library arduino's for ESP32
#include <EEPROM.h>               // Eeprom library 

//#define LED_ONBOARD   2       // Port P2  --> led on board ESP32 DEVKIT V1
#define GREEN_LED     25      // Port P25 --> Green led
#define YELLOW_LED    26      // Port P26 --> Yellow led
#define RED_LED       27      // Port P27 --> Red led
#define SSID_ADDR     0
#define PASS_ADDR     64
#define EEPROM_BLOCK  128
      

// Set-Up the ports as outputs
#define PORTS_SETUP  (/*pinMode(LED_ONBOARD,OUTPUT),*/pinMode(GREEN_LED,OUTPUT),\
                      pinMode(YELLOW_LED,OUTPUT),pinMode(RED_LED,OUTPUT))
// Turn-On the leds
#define GreenOn      (digitalWrite(GREEN_LED,HIGH))
#define YellowOn     (digitalWrite(YELLOW_LED,HIGH))
#define RedOn        (digitalWrite(RED_LED,HIGH))
//#define BlueOn        (digitalWrite(LED_ONBOARD,HIGH))

// Turn-Off the leds
#define GreenOff      (digitalWrite(GREEN_LED,LOW))
#define YellowOff     (digitalWrite(YELLOW_LED,LOW))
#define RedOff        (digitalWrite(RED_LED,LOW))
//#define Blueoff       (digitalWrite(LED_ONBOARD,LOW))

#define LedsOff      (GreenOff,YellowOff,RedOff/*,Blueoff*/)

BluetoothSerial Esp32;            // Create a Bluetooth class object
WiFiServer      server(80);       // Set WebServer Port

/*************************************************************************
 * Variables para almacenar el nombre de la red y su contraseña a la cual
 * se desea conectar; los datos se obtienen por Bluetooht en el set-up
 *************************************************************************/
String Ssid;
String Pass;
String ssid;
String pass;
String header;                   // Store the HTTP request
const char *id;
const char *pas;
// Store the current output state
String state_P25 = "off";
String state_P26 = "off";
String state_P27 = "off";
char count = 0;
char cicle = 1;
char wait = 1;
int incoming;

 // Set the GPIO Ports
const int green = 25;        // Port P25 --> Green Led
const int yellow = 26;       // Port P26 --> Yellow Led
const int red = 27;          // Port P27 --> Red Led
const int LED_ONBOARD = 2;   // Port P2 --> Led OnBoard ESP32


void clear_eeprom(void)
{
  for(int addr = 0; addr < EEPROM_BLOCK; addr++)
  {
    EEPROM.write(addr,255);
  }
}

void storage_keywords(int addr1,int addr2, String Name, String Pass)
{
  /* tomo las longitudes de los datos de la red a utilizar, a priori 
   * no se que longitud tiene cada parametro */
  int length1 = Name.length();
  int length2 = Pass.length(); 
  // creo los vectores para almacenar los datos en la Eeprom
  char network[length1];
  char pass[length2];

  // convierto los string a caracteres para almacenarlos en la eeprom
  Name.toCharArray(network,length1 + 1);
  Pass.toCharArray(pass,length2 + 1);
  int i;
  int j;

  for(i = 0; i < length1; i++)
  {
    EEPROM.write(addr1 + i, network[i]);
  }
  if(i == length1)
  {
    EEPROM.write(addr1 + i, '\0');
  }
  for(j = 0; j < length2; j++)
  {
    EEPROM.write(addr2 + j,pass[j]);
  }
   if(j == length2)
  {
    EEPROM.write(addr2 + j, '\0');
  }

  EEPROM.commit();
}

String read_eeprom(int addr)
{
  byte reading;
  String readStr;
  for(int i = addr; i < addr + PASS_ADDR; i++)
  {
    reading = EEPROM.read(i);   // Get data of memory address
//    if(reading != '\0')
 //   {
      readStr += (char)reading;
//    }
  }
  return readStr;
}


void setup() {

  PORTS_SETUP; 
  LedsOff;

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(500);
  Serial.begin(115200);
  Esp32.begin("ESP32_BT");   // Name of the BlueTooth Signal
  Serial.println();
  Serial.println("**************************************");
  Serial.println("The BlueTooth device is ready to link");
  Serial.println("**************************************");
  
//  GreenOn; 
  EEPROM.begin(EEPROM_BLOCK);    // Inicio la eeprom para poder escribir con 128 bytes de bloque 
  //clear_eeprom();                // Clean all entire block of eeprom to use. 
  Serial.println(Esp32.available(),DEC);
  if(/*Esp32.available() == 0 ||*/ Esp32.available() <= 0 )
  {
      YellowOn; // Se enciende
/*      incoming = Esp32.read();
      Serial.print("El contenido del buffer es: ");
      Serial.println(incoming,DEC);
      //while(true);*/
      delay(1000);
     // Esp32.write(Esp32.read());
      Esp32.println("Push the s key to begining"); // Este mensaje no aparece en el Bluetooth terminal.
      incoming = 0; 
      while(wait)     // Wait for enter choise
      {
         if(Esp32.available() > 0)
         {
            char cicle = 1;
         //   RedOn;            // se enciende
            wait = 0;         //  break the loop, means enter the s key
         }
      }      
  } 
  wait = 1;
  while (cicle)
  {
    incoming = Esp32.read();
    Serial.println(incoming);
    if(incoming == 115 || incoming == 83)
    {
     // GreenOff;                                 // se apaga
      Esp32.println("Device Set-Up start's");
      delay(2000);
      int network = 0;                  // Amount of netwoks availables in the zone
      network = WiFi.scanNetworks();    // Scan for availables networks
      String ssid[network];             // Vector with SSID Name        
      if(network)
      {
        Esp32.print(network); 
        Esp32.println(" netwoks found");
        for(int i = 0; i < network; i++)
        {
          ssid[i] = WiFi.SSID(i);    // ID network stored
          Esp32.print(i + 1, DEC);
          Esp32.print(" ) ");
          Esp32.println(ssid[i]);          // List on BlueTooth Device
          delay(100);
        }
      }
      else
      {
        Esp32.println("No Networks Found");
      }
      Esp32.println("Choose the network to connect");
        
      while(wait)     // Wait for enter choise    
      {
        if(Esp32.available() > 0)
        {
          wait = 0;
          incoming = Esp32.read();
          Serial.print("The network chossen is: ");
          Serial.println(incoming - 48);
          Ssid = ssid[(incoming - 48)-1];
         // Serial.println(ssid[(incoming - 48)-1]);
          Serial.println(Ssid);
          Esp32.print("Your Choise: ");                
        }
      }
      wait = 1;
      Esp32.println(Ssid);
      //Esp32.println(ssid[(incoming - 48)-1]);  
      Esp32.println("Enter your password");
      while(wait)     // Wait for enter choise    
      {
        if(Esp32.available() > 0)
        {
          wait = 0;
          do {
            incoming = Esp32.read();
            Pass += (char)incoming;       // Converted the ASCII code to character
          }while(Esp32.available() != 0);
          Serial.print("Your Pass is: ");
          Serial.println(Pass);
        }
      }
      storage_keywords(SSID_ADDR,PASS_ADDR,Ssid,Pass); // Load data into EEPROM memory
      Ssid = read_eeprom(SSID_ADDR);
      Pass = read_eeprom(PASS_ADDR);
      Serial.println();
      Serial.println("This data was readed of EEPROM Memory");
      Serial.print("Your network chooseen is:  ");
      Serial.println(Ssid);
      Serial.println();
      Serial.print("Your password entered is:  ");
      Serial.println(Pass); 
    }
    cicle = 0;  // Se debe eliminar el while porque no tiene sentido, ya se depuro la logica y funciona     
  }
  // Connect to Wi-Fi network 
Esp32.end();  
const char *id = Ssid.c_str();
const char *pass = Pass.c_str(); 
Serial.println();
Serial.print("WL_DISCONNECTED =  ");
Serial.println(WL_DISCONNECTED);  
Serial.println();
Serial.print("Connecting to ");
Serial.println(id);
Serial.print("With password: ");
Serial.println(pass);
Serial.println();
WiFi.begin(id,pass);
while(WiFi.status() != WL_CONNECTED)
{
  delay(500);
  Serial.print("*"); Serial.print("Status Response: ");
  Serial.print(WiFi.status());Serial.print(" "); Serial.print("-->");
  Serial.print(" Constant Value: ");
  Serial.print(WL_CONNECTED);
  Serial.println();
  count+=1;
}
Serial.print("Amount of iterations: ");
Serial.print(count,DEC);Serial.println("");
// Print the local IP Address ans start web server
Serial.print("");Serial.println();
Serial.println("WiFi connected!!!");
Serial.print("IP Address: ");
Serial.println(WiFi.localIP());
server.begin();
Serial.println();
 }

void loop() {

WiFiClient client = server.available();     // Listen for incoming clients

  if(client)
  { 
    Serial.println("New Client");
    String currentLine = "";        // Hold the incoming data from the client
    while (client.connected())
    { 
      if(client.available())        // byte to read from client??
      {
        char c = client.read();     // read a byte incoming
        Serial.write(c);            // printed them in the serial monitor
        header += c;
        // The byte is a newline character??
        if(c == '\n')
        {
          if(currentLine.length() == 0)
          {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type: text/html");
            client.println("Connection: close");
            client.println();

            // Manangament of the GPIO Ports
            if(header.indexOf("GET /25/on") >= 0)
            {
              Serial.println("Green Led ON");
              state_P25 = "on";
              //digitalWrite(green,HIGH);
              GreenOn;
            } 
            else if(header.indexOf("GET /25/off") >= 0)
                 {
                   Serial.println("Green Led Off");
                   state_P25 = "off";
                  //digitalWrite(green,LOW);
                  GreenOff;
                 }
                 else if(header.indexOf("GET /26/on") >= 0)
                      {
                        Serial.println("Yellow Led ON");
                        state_P26 = "on";
                        //digitalWrite(yellow,HIGH);
                        YellowOn;
                      }
                      else if(header.indexOf("GET /26/off") >= 0)
                           {
                            Serial.println("Yellow Led OFF");
                            state_P26 = "off";
                            //digitalWrite(yellow,LOW);
                            YellowOff;
                           }
                           else if(header.indexOf("GET /27/on") >= 0)
                                {
                                  Serial.println("Red Led ON");
                                  state_P27 = "on";
                                  //digitalWrite(red,HIGH);
                                  RedOn;
                                }
                                else if(header.indexOf("GET /27/off") >= 0)
                                     {
                                      Serial.println("Red Led OFF");
                                      state_P27 = "off";
                                      //digitalWrite(red,LOW);
                                      RedOff;
                                     }
          // Display the HTML web page
          client.println("<!DOCTYPE HTML><html>");
          client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
          client.println("<link rel=\"icon\" href=\"data:,\">");
          //CSS to style the ON - OFF buttons
          client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
          client.println(".button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;");
          client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
          client.println(".button2 {background-color: #555555;}</style></head>");

          // Web page Heading
          client.println("<body><h1>ESP32 Web Server</h1>");
         
          //Display current state, ON - OFF button of Green Led
          client.println("<p>Green Led State:  " + state_P25 + "</p>");
          client.println("");
          if(state_P25 == "off")    // GPIO in low state --> Show ON button
          {  
            client.println("<p>Press button for turn-on</p>");
            client.println("<p><a href=\"/25/on\"><button class=\"button\">ON</button></a></p>");
          }
          else 
          {
            client.println("<p>Press button for turn-off</p>");
            client.println("<p><a href=\"/25/off\"><button class=\"button button2\">OFF</button></a></p>");
          }
          //Display current state, ON - OFF button of Yellow Led
          client.println("<p>Yellow Led State:  " + state_P26 + "</p>");
          client.println("");
          if(state_P26 == "off")    // GPIO in low state --> Show ON button
          {
            client.println("<p>Press button for turn-on</p>");
            client.println("<p><a href=\"/26/on\"><button class=\"button\">ON</button></a></p>");
          }
          else 
          {
            client.println("<p>Press button for turn-off</p>");
            client.println("<p><a href=\"/26/off\"><button class=\"button button2\">OFF</button></a></p>");
          }  
          //Display current state, ON - OFF button of Red Led
          client.println("<p>Red Led State:  " + state_P27 + "</p>");
          client.println("");       
          if(state_P27 == "off")    // GPIO in low state --> Show ON button
          {
            client.println("<p>Press button for turn-on</p>");  
            client.println("<p><a href=\"/27/on\"><button class=\"button\">ON</button></a></p>");}
          else 
          {
            client.println("<p>Press button for turn-off</p>");
            client.println("<p><a href=\"/27/off\"><button class=\"button button2\">OFF</button></a></p>");
          }  

          client.println("</body></html>");

          // The HTTP response ends with another blank line
          client.println();

          //Break out of the while loop
          break;
          }
          else {
            currentLine = "";} // If a new line --> clear currentLine
 
        }
        else if( c != '\r'){
                currentLine += c;} // add to the end of the currentLine
      }
    }  // Close the while loop

    // Clear the header
    header = "";

    //Close the connection
    client.stop();
    Serial.println("Client disconnected");
    Serial.println("");
  } // Close  if(client)
}







/*
void setup_wifi() {
// Conexión WIFI
  WiFi.mode(WIFI_STA); //para que no inicie el SoftAP en el modo normal
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED and contconexion <50) { //Cuenta hasta 50 si no se puede conectar lo cancela
    ++contconexion;
    delay(250);
    Serial.print(".");
    digitalWrite(13, HIGH);
    delay(250);
    digitalWrite(13, LOW);
  }
  if (contconexion <50) {   
      Serial.println("");
      Serial.println("WiFi conectado");
      Serial.println(WiFi.localIP());
      digitalWrite(13, HIGH);  
  }
  else { 
      Serial.println("");
      Serial.println("Error de conexion");
      digitalWrite(13, LOW);
  }
}

//--------------------------------------------------------------
WiFiClient espClient;
ESP8266WebServer server(80);
//--------------------------------------------------------------

//-------------------PAGINA DE CONFIGURACION--------------------
void paginaconf() {
  server.send(200, "text/html", pagina + mensaje + paginafin); 
}


*/













































  
