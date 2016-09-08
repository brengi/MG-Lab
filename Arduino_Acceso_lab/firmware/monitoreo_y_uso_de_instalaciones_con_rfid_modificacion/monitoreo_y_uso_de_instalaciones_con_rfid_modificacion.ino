#include <Wire.h>

#include <Adafruit_NFCShield_I2C.h>
#include "RTClib.h"                 //Libreria para el reloj

#define IRQ   (2)
#define RESET (3)

Adafruit_NFCShield_I2C nfc(IRQ, RESET);

RTC_DS1307 RTC;

/*_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _            
             zona1              *              zona2                      *
  (entrada y salida del recinto)*  (uso y permanencia en el laboratorio)  *   
--------------------------------------------------------------------------*
             sensor1            *             sensor2                     *
             buzzer1            *             buzzer2                     *
              led1              *              led2                       *
             estado1            *             estado2                     *
--------------------------------------------------------------------------*/


const int sensor1 = 5, buzzer1 = 8, led1 = 3;                        
const int sensor2 = 6, buzzer2 = 9, led2 = A3;          

boolean estado1;                       //variable utilizada para el estado del sensor1
boolean estado2;                       //variable utilizada para el estado del sensor2
uint8_t targeta;
uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };  // Buffer para almacenar el UID devuelto
uint8_t uidLength;                       // Duración del UID (4 o 7 bytes dependiendo del tipo de tarjeta ISO14443A )

void setup(){
  pinMode(sensor1, INPUT);        
  pinMode(sensor2, INPUT);
  pinMode(led1, OUTPUT);  
  pinMode(buzzer1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(buzzer2, OUTPUT);
  Serial.begin(9600);
  Wire.begin();                  //Inicia el puerto I2C
  RTC.begin();                   //Inicia la comunicacion con el RTC
  //RTC.adjust(DateTime(__DATE__, __TIME__));    //Establece fecha y hora en el reloj se ejecuta un sola vez
  nfc.begin();
  // configuracion de placa para leer etiquetas RFID
  nfc.SAMConfig();
  
}

void loop(){ 
    
    zona1();
    
    zona2();
    
    rfid();
 }

//******************************* Zona1 entrada y salida del recinto ****************************
void zona1(){
  estado1 = digitalRead(sensor1);           //lectura del sensor de entrada y salida de 
                                            //la zona 1
  if(estado1){
    Serial.println("entra/sale");
    digitalWrite(led1, HIGH);
    digitalWrite(buzzer1, HIGH);
    //delay(1000);
    //digitalWrite(led1, LOW);
    //digitalWrite(buzzer1, LOW);
    }
  else{
     digitalWrite(led1, LOW);
     digitalWrite(buzzer1, LOW);
   //delay(1000);
   }
   delay(1000);
 } 
   
//******************************* Zona2 presencia en el laboratorio ********************************
void zona2(){
  estado2 = digitalRead(sensor2);            //lectura del sensor de presencia en zona 2
   if(estado2){                       //si sen2 detecta
     digitalWrite(buzzer2, LOW);
     digitalWrite(led2, LOW);
     Serial.println("presencia en el laboratorio");
     Serial.print("Esperando targeta.");
     Serial.print(".");
     Serial.println(".");
       
     for(int t=0; t<20; t++){             //se activa la luz con temporizacion al apagado (tiempo para poner la targeta)
        digitalWrite(led2, HIGH);                      
        zona1();                            //va a la subrutina zona1
        lecturaTargeta();
        if(targeta){
          digitalWrite(led2, LOW);
          Serial.print("Fecha y hora de ingreso: ");
          fechaHora();
          tomarDatos();
          sigue();
         }
       }
      digitalWrite(led2, LOW); 
      alarma: 
      estado2 = digitalRead(sensor2);      //Suena alarma si todavia no se ingreso la targeta y sigue detectando movimiento
     if(estado2){
       digitalWrite(led2, HIGH);
       digitalWrite(buzzer2, HIGH);
       zona1();
       digitalWrite(led2, LOW);
       digitalWrite(buzzer2, LOW);
       zona1();
       lecturaTargeta();
       if(targeta){
          Serial.print("Fecha y hora de ingreso: ");
          fechaHora();
          tomarDatos();
          sigue();
        }
       goto alarma;
      }  
    }
 }  
  
  
void sigue(){
  long x=0;
  
  while(targeta){
    zona1();
    x++;
    
    if(x > 300){                        //cada cinco minutos se fija si hay alguien
      estado2 = digitalRead(sensor2);
      if(!estado2){                     //si no hay presencia suena buzzer2 
        rfid();
      }
      else{
        digitalWrite(buzzer2, LOW);
        digitalWrite(led2, LOW);
        x=0;
      }
    }
  }
  Serial.print("Hora de salida: ");
  fechaHora();
  for(int t=0; t<20; t++){               //tiempo para retirarse del laboratorio antes que se active el sensor2
    //digitalWrite(led2, HIGH);
    zona1();
  }
 //digitalWrite(led2, LOW);
 }



//******************** RFID lectura de targeta sin presencia en el laboratorio **********************    
void rfid(){
 lecturaTargeta();
 if(targeta){
   Serial.print("ERROR!!!");
   Serial.println("TARGETA COLOCADA SIN PRESENCIA EN EL LABORATORIO");
   digitalWrite(buzzer2, HIGH);
   digitalWrite(led2, HIGH);
   delay(500); 
 }  
}    
    
    //si recibe datos (targeta colocada)
void tomarDatos(){                            
     // Mustra alguna información básica sobre la tarjeta
         Serial.println("Una targeta ISO14443A encontrada");
         Serial.print("  UID Length: ");Serial.print(uidLength, DEC);Serial.println(" bytes");
         Serial.print("  UID Value: ");
         nfc.PrintHex(uid, uidLength);
         Serial.println("");
      
         if (uidLength == 4){  
         // Es probable que tengamos una tarjeta Mifare Classic ... 
        Serial.println("Parece ser una tarjeta Mifare Classic (4 byte UID)");
    
        // Ahora tenemos que intentar autenticar para lectura / escritura
        // Pruebe con los valores de fábrica KeyA: 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF
        Serial.println("Intentar autenticar el bloque 4 con el valor por defecto KEYA");
        uint8_t keya[6] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
        //uint8_t keya[6] = { 0xAA, 0xBB, 0XCC, 0xDD, 0xEE, 0xFF };
      
        // Inicia con el bloque 4 ( el primer bloque del sector 1 ), ya que el sector 0
        // Contiene los datos del fabricante y es probablemente mejor sólo
        // Dejarlo solo a menos que sepa lo que está haciendo
        targeta = nfc.mifareclassic_AuthenticateBlock(uid, uidLength, 4, 0, keya);
     
        if (targeta){
          Serial.println("Sector 1 (Blocks 4..7) ha sido autenticado");
          uint8_t data[16];
    
          // Si quiere escribir algo al bloque 4 para probar con Descomentar
          // La siguiente línea y este texto debe leerse de nuevo en un minuto
        
          //memcpy(data, (const uint8_t[]){ 'C', 'O', 'S', 'T', 'A', ' ', 'L', 'E', 'O', 'N', 'E', 'L', 0, 0, 0, 0 }, sizeof data);
          //success = nfc.mifareclassic_WriteDataBlock (4, data);

          // Trate de leer el contenido del bloque 4
          targeta = nfc.mifareclassic_ReadDataBlock(4, data);
    
          if (targeta){
            // Parece que los datos han sido leídos ... escupirla
            Serial.println("Leyendo bloque 4:");
            nfc.PrintHexChar(data, 16);
            Serial.println("");
            
           Serial.print("fecha y hora de entrada:");      //en el momento en que se coloca la targeta
           fechaHora();                                   //imprime fecha y hora de entrada
            
            // Esperar un poco antes de leer la tarjeta de nuevo
            delay(3000);
          }
         else
        {
          Serial.println("Ooops ... incapaz de leer el bloque solicitado . Prueba con otro Key");
        }
      }
      else
      {
        Serial.println("Ooops ... Error de autenticacion: Prueba con otro Key");
        delay(1000);
      }
     }   
    }
    

  
void fechaHora(){
  DateTime now = RTC.now(); // Obtiene la fecha y hora del RTC
  
  Serial.print(now.day(), DEC); // Dia
  Serial.print('/');
  Serial.print(now.month(), DEC); // Mes
  Serial.print('/');
  Serial.print(now.year(), DEC); // Año
  
  Serial.print(' ');
  
  Serial.print(now.hour(), DEC); // Horas
  Serial.print(':');
  Serial.print(now.minute(), DEC); // Minutos
  Serial.print(':');
  Serial.print(now.second(), DEC); // Segundos
  Serial.println();
}

void lecturaTargeta(){
   targeta = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength); //la variable targeta guarda los datos leidos de la tarjeta
}



