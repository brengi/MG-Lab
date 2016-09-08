#include <Wire.h>                        //Libreria para el puerto I2C
#include "RTClib.h"                 //Libreria para el reloj
//#include<Adafruit_NFCShield_I2C.h>

//#define IRQ   (2)
//#define RESET (3

//Adafruit_NFCShield_I2C nfc(IRQ, RESET);

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
const int targeta = 2;               //uso un pulsador para representar una targeta

boolean estado1;                       //variable utilizada para el estado del sensor1
boolean estado2;                       //variable utilizada para el estado del sensor2

void setup(){
  pinMode(sensor1, INPUT);        
  pinMode(sensor2, INPUT);
  pinMode(led1, OUTPUT);  
  pinMode(buzzer1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(buzzer2, OUTPUT);
  pinMode(targeta, INPUT);
  Serial.begin(9600);
  Wire.begin();                  //Inicia el puerto I2C
  RTC.begin();                   //Inicia la comunicacion con el RTC
  //RTC.adjust(DateTime(__DATE__, __TIME__));    //Establece fecha y hora en el reloj se ejecuta un sola vez
  //nfc.begin();
}

void loop(){ //*************************************************
  
    zona1();
    zona2();
 }
//*****************************************************************
void zona1(){
  estado1 = digitalRead(sensor1);           //lectura del sensor de entrada y salida de 
                                            //la zona 1
  if(estado1){
    Serial.println("entra/sale");
    digitalWrite(led1, HIGH);
    digitalWrite(buzzer1, HIGH);
    delay(1000);
  }
  else{
     digitalWrite(led1, LOW);
     digitalWrite(buzzer1, LOW);
     delay(1000);
     }
} 
   

void zona2(){
  estado2 = digitalRead(sensor2);            //lectura del sensor de presencia en zona 2
  
  if(estado2==HIGH){                               //si sen2 detecta
    Serial.println("presencia en el laboratorio");   
   
    for(int t=0; t<10; t++){             //se activa la luz con temporizacion al apagado
      digitalWrite(led2, HIGH);                      
      zona1();                            //va a la subrutina zona1
    }
    digitalWrite(led2, LOW);
       
       
    while(digitalRead(targeta) == LOW){      //si no se coloco la targeta suena buzzer
        digitalWrite(buzzer2, HIGH);         //hasta que la misma se ingrese
        zona1();
        digitalWrite(buzzer2, LOW);
        zona1();
    }
    
        Serial.print("fecha y hora de entrada:");      //en el momento en que se coloca la targeta
        fechaHora();                                   //imprime fecha y hora de entrada
    
         while(digitalRead(targeta) == HIGH){            
             digitalWrite(led2, HIGH);
             zona1();
         }
    
    
         Serial.print("fecha y hora de salida:");        //cuando saca la tarjeta imprime fecha y hora de salida
         fechaHora();  
    
         digitalWrite(led2, LOW);
         for(int x=0; x<20; x++){          //tiempo en el que se retira la persona del laboratorio
            zona1();                        //para luego activar el sensor
            //x++;
         }
                                
  }                             
  else{
     digitalWrite(led2, LOW);               //sino detecta nada
     digitalWrite(buzzer2, LOW);
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



