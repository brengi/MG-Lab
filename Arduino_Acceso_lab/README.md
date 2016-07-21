# ARDUINO PARA  MONITOREO DE USO DE INSTALACIONES #
 
RESPONSABLE: Costa Leonel
 
## ACTIVIDAD ##
Utilizar un Arduino para ayudar a regular, monitorear y organizar el uso de un laboratorio 
de electrónica.
 
## PAUTAS ##
  * Lectura de sensor de presencia infrarrojo. Uno o preferentemente dos para distinguir 
zonas. ZONA 1:  podría marcar entrada/salida del recinto (suena siempre) y ZONA 2 
uso y permanencia en el laboratorio.  
  * Manejo de una luz que se vea a distancia. La luz indica que se ha detectado 
presencia en alguna zona y tiene temporización al apagado. 
  * Manejo de bocina/buzzer para indicar entrada/salida del recinto o ZONA 2 sin tarjeta. 
  *  Manejo de tarjeta NFC. Dejando la tarjeta en el lector, la alarma ZONA 2 no suena. 
  * Considerar el gabinete para el arduino con el sensor NFC. Se puede imprimir con 
impresora 3D. 
  * Si hay tiempo. Uso del  RTC para saber hora y fecha de los eventos. 
  * SI hay tiempo. Uso de Wifi. Analizar si es posible un sistema de alta y baja de 
tarjetas o consulta de registro de uso.