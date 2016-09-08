/**************************************************************************/
/*! 
    @file     readMifare.pde
    @author   Adafruit Industries
    @license  BSD (see license.txt)

   En este ejemplo se va a esperar para cualquier tarjeta o etiqueta ISO14443A , y
    dependiendo del tamaño de la UID intentará leer de él.
   
    Si la tarjeta tiene un UID 4 - byte es probable que sea un Mifare
    clásico de cartas , y se toman los siguientes pasos:
   
    - Autenticación del bloque 4 ( el primer bloque del Sector 1 ) usando
      el valor por defecto de 0xFF 0xFF KEYA 0xFF 0xFF 0xFF 0xFF
    - Si la autenticación tiene éxito , entonces podemos leer cualquiera de las
      4 bloques en ese sector ( aunque sólo el bloque 4 se lee aquí)
   
    Si la tarjeta tiene un UID 7 - byte es probable que sea un Mifare
    Tarjeta ultralight , y las páginas 4 bytes se pueden leer directamente .
    Página 4 es leído por defecto, ya que esta es la primera ' general-
    finalidad página ' en las etiquetas.


    This is an example sketch for the Adafruit PN532 NFC/RFID breakout boards
    This library works with the Adafruit NFC breakout 
      ----> https://www.adafruit.com/products/364
 
    Check out the links above for our tutorials and wiring diagrams 
    These chips use I2C to communicate

    Adafruit invests time and resources providing this open source code, 
    please support Adafruit and open-source hardware by purchasing 
    products from Adafruit!
*/
/**************************************************************************/
#include <Wire.h>
#include <Adafruit_NFCShield_I2C.h>

#define IRQ   (2)
#define RESET (3)  // Not connected by default on the NFC Shield

Adafruit_NFCShield_I2C nfc(IRQ, RESET);

void setup(void) {
  Serial.begin(115200);
  Serial.println("Hola!");

  nfc.begin();

  uint32_t versiondata = nfc.getFirmwareVersion();            //verifica si el shield PN5x esta insertada y se puede conseguir los datos
  if (! versiondata) {                                             //si no esta conectada
    Serial.print("No se ha encontrado ninguna placa PN53x");      //imprime mensaje
    while (1); //detenido                          //y queda detenido el programa
  } 
  //datos conseguidos                                                      
  Serial.print("Encontrado PN5"); Serial.println((versiondata>>24) & 0xFF, HEX); //imprime el nombre, la version y modelo del nfc
  Serial.print("Firmware ver. "); Serial.print((versiondata>>16) & 0xFF, DEC); 
  Serial.print('.'); Serial.println((versiondata>>8) & 0xFF, DEC);
  
  // configuracion de placa para leer etiquetas RFID
  nfc.SAMConfig();
  
  Serial.println("Esperando por una tarjeta ISO14443A ...");
}


void loop(void) {
  uint8_t success;
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };  // Buffer para almacenar el UID devuelto
  uint8_t uidLength;                        // Duración del UID (4 o 7 bytes dependiendo del tipo de tarjeta ISO14443A )
    
  // Esperar a que un tipo de tarjetas ISO14443A ( Mifare , etc. ) . Cuando uno se encuentra
  // ' Uid ' se rellenará con el UID , y uidLength indicará
  // Si el fluido es de 4 bytes ( Mifare Classic) o 7 bytes ( Mifare Ultralight )
  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength); //la variable success guarda los datos leidos de la tarjeta 
                                                                               
  if (success) {  //si recibe datos
    // Mustra alguna información básica sobre la tarjeta
    Serial.println("Una targeta ISO14443A encontrada");
    Serial.print("  UID Length: ");Serial.print(uidLength, DEC);Serial.println(" bytes");
    Serial.print("  UID Value: ");
    nfc.PrintHex(uid, uidLength);
    Serial.println("");
    
    if (uidLength == 4)
    {
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
      success = nfc.mifareclassic_AuthenticateBlock(uid, uidLength, 4, 0, keya);
    
      if (success)
      {
        Serial.println("Sector 1 (Blocks 4..7) ha sido autenticado");
        uint8_t data[16];
    
        // Si quiere escribir algo al bloque 4 para probar con Descomentar
        // La siguiente línea y este texto debe leerse de nuevo en un minuto
        
      //memcpy(data, (const uint8_t[]){ 'C', 'O', 'S', 'T', 'A', ' ', 'L', 'E', 'O', 'N', 'E', 'L', 0, 0, 0, 0 }, sizeof data);
        //success = nfc.mifareclassic_WriteDataBlock (4, data);

        // Trate de leer el contenido del bloque 4
        success = nfc.mifareclassic_ReadDataBlock(4, data);
    
        if (success)
        {
          // Parece que los datos han sido leídos ... escupirla
          Serial.println("Leyendo bloque 4:");
          nfc.PrintHexChar(data, 16);
          Serial.println("");
      
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
        delay(3000);
      }
    }
    
    if (uidLength == 7)
    {
      // Es probable que tengamos una tarjeta Mifare Ultralight ...
      Serial.println("Parece ser un targeta Mifare Ultralight (7 byte UID)");
    
      // Trate de leer la primera página de usuario de propósito general (#4)
      Serial.println("Leyendo pagina 4");
      uint8_t data[32];
      success = nfc.mifareultralight_ReadPage (4, data);
      if (success)
      {
        // Parece que los datos han sido leídos ... escupirla
        nfc.PrintHexChar(data, 4);
        Serial.println("");
    
        // Esperar un poco antes de leer la tarjeta de nuevo
        delay(3000);
      }
      else
      {
        Serial.println("Ooops ... incapaz de leer la página solicitada !?");
        delay(3000);
      }
    }
  }
}

