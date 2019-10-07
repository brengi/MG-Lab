/**************************************************************************
 * Programa de prueba para el uso del ESP32  con la conexión WIFI a una 
 * pagina http. Adaptado de un ejemplo conseguido en randomnerdtutorials.com  
 * por Gustavo Rodríguez - INTI CMNB
 *************************************************************************/

 #include <WiFi.h>        // Cargo la libreria para el uso de WiFi
 #include <Ticker.h>      // Cargo libreria para blinkear al led
#include <EEPROM.h>               // Eeprom library 
#define SSID_ADDR     0
#define PASS_ADDR     64
#define EEPROM_BLOCK  128
/*************************************************************************
 * Aqui se debe colocar el Nombre y la contraseña de la red WiFi a la 
 * cual se desea conectar
 *************************************************************************/
 // Network credentials
String Ssid = "CNMB";
String Pass = "NestorVive";
String ssid;
String pas;
 //const char *ssid = "CNMB";
// const char *pass = "NestorVive";


 WiFiServer server(80); //Set WebServer Port
 
 String header; // Store the HTTP request
 
// Store the current output state
 String state_P25 = "off";
 String state_P26 = "off";
 String state_P27 = "off";

 // Set the GPIO Ports
const int green = 25;        // Port P25 --> Green Led
const int yellow = 26;       // Port P26 --> Yellow Led
const int red = 27;          // Port P27 --> Red Led
const int LED_ONBOARD = 2;   // Port P2 --> Led OnBoard ESP32

/***************************************************************************
 *                     Blinker Section
 ***************************************************************************/
#define Led_OnBoard 2

Ticker blinker, toggler;
float blinkerPace = 0.5;      // seconds
const float togglePeriod = 1; // seconds

void blink ()
{
  digitalWrite(Led_OnBoard, !digitalRead(Led_OnBoard));
}

void toggle()
{
  static bool isBlinking = false;
  if(isBlinking)
  {
    blinker.detach();
    isBlinking = false;
  }
  else
  {
    blinker.attach(blinkerPace, blink);
    isBlinking = true;
  }
// Make sure LED on after toggling  
  digitalWrite(Led_OnBoard,HIGH);
}

/*************************************************************************
 *          End of Blinker Section
 *************************************************************************/


void clear_eeprom(void)
{
  for(int addr = 0; addr < EEPROM_BLOCK; addr++)
  {
    EEPROM.put(addr,0);
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
 Serial.println("los caracteres que estoy guardando son");
  for(i = 0; i < length1; i++)
  {
    EEPROM.put(addr1 + (char)i, network[i]);
    Serial.print("el caracter es: ");
    Serial.println(network[i]);
    delay(500);
  }
  if(i == length1)
  {
    EEPROM.put(addr1 + i, '\0');
  }
  Serial.println();
  Serial.println("los caracteres que estoy guardando son");
  for(j = 0; j < length2; j++)
  {
    EEPROM.put(addr2 + (char)j,pass[j]);
    Serial.print("el caracter es: ");
    Serial.println(pass[j]);
    delay(500);
  }
   if(j == length2)
  {
    EEPROM.put(addr2 + j, '\0');
  }

  EEPROM.commit();
}

String read_eeprom(int addr)
{
  String readStr = "";
  EEPROM.get(addr,readStr);   // Get data of memory address
  Serial.println();
  Serial.print("lo que estoy leyendo de la eeprom es: ");
  Serial.println(readStr);
  return readStr;
}




void setup() {
  
pinMode(Led_OnBoard,OUTPUT);
toggler.attach(togglePeriod, toggle);

char count = 0;

Serial.begin(115200);
//Configure the Ports like outputs and set low state
pinMode(green,OUTPUT);
pinMode(yellow,OUTPUT);
pinMode(red,OUTPUT);
pinMode(LED_ONBOARD,OUTPUT);
digitalWrite(green,LOW);
digitalWrite(yellow,LOW);
digitalWrite(red,LOW);
digitalWrite(LED_ONBOARD,LOW);

      Serial.println();
      Serial.println("****************************************************************");
      Serial.println("Los datos de la red a conectarse son");
      Serial.print("Nombre de la red: ");
      Serial.println(Ssid);
      Serial.print("Contraseña: ");
      Serial.println(Pass);
      Serial.println("****************************************************************");
      Serial.println();
      storage_keywords(SSID_ADDR,PASS_ADDR,Ssid,Pass); // Load data into EEPROM memory
      ssid = read_eeprom(SSID_ADDR);
      pas = read_eeprom(PASS_ADDR);
      Serial.println();
      Serial.println("This data was readed of EEPROM Memory");Serial.println();
      Serial.print("Your network chooseen is:  ");
      Serial.println(ssid);
      Serial.println();
      Serial.print("Your password entered is:  ");
      Serial.println(pas); 
      delay(2000);
      const char *id = Ssid.c_str();
      const char *pass = Pass.c_str(); 

// Connect to Wi-Fi network 
Serial.print("Connecting to ");
//Serial.println(ssid);
//WiFi.begin(Ssid,Pass);
Serial.println(id);
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
/*
  digitalWrite(LED_ONBOARD,HIGH);
  delay(1000);
  digitalWrite(LED_ONBOARD,LOW);
  delay(1000);
 */ 
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
              digitalWrite(green,HIGH);
            } 
            else if(header.indexOf("GET /25/off") >= 0)
                 {
                   Serial.println("Green Led Off");
                   state_P25 = "off";
                   digitalWrite(green,LOW);
                 }
                 else if(header.indexOf("GET /26/on") >= 0)
                      {
                        Serial.println("Yellow Led ON");
                        state_P26 = "on";
                        digitalWrite(yellow,HIGH);
                      }
                      else if(header.indexOf("GET /26/off") >= 0)
                           {
                            Serial.println("Yellow Led OFF");
                            state_P26 = "off";
                            digitalWrite(yellow,LOW);
                           }
                           else if(header.indexOf("GET /27/on") >= 0)
                                {
                                  Serial.println("Red Led ON");
                                  state_P27 = "on";
                                  digitalWrite(red,HIGH);
                                }
                                else if(header.indexOf("GET /27/off") >= 0)
                                     {
                                      Serial.println("Red Led OFF");
                                      state_P27 = "off";
                                      digitalWrite(red,LOW);
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





































  
