
#define OptoUno (7)
#define OptoDos (6)
#define OptoTres (5)
#define OptoCuatro (4)
#define SensorUno (3)
#define SensorDos (2)
#define SensorTres (1)
#define SensorCuatro (0)
#define TrigUS1 (8) 
#define TrigUS2 (10)
#define EchoUS1 (9)
#define EchoUS2 (11)

  int cm1=0;
  int cm2=0;
  int valorInfra=0;

void setup()
{
  Serial.begin(9600);
  pinMode(TrigUS1, OUTPUT);
  pinMode(EchoUS1, INPUT);
  pinMode(TrigUS2, OUTPUT);
  pinMode(EchoUS2, INPUT);
  pinMode(SensorUno, INPUT);
  pinMode(SensorDos, INPUT);
  pinMode(SensorTres, INPUT);
  pinMode(SensorCuatro, INPUT);
  pinMode(OptoUno, OUTPUT);
  pinMode(OptoDos, OUTPUT);
  pinMode(OptoTres, OUTPUT);
  pinMode(OptoCuatro, OUTPUT);

  digitalWrite(OptoUno, LOW);

  delay(5000);
}
  
void loop()
{
    
  valorInfra = digitalRead(SensorUno);
  Serial.print("SensorUno: ");
  Serial.println(valorInfra);
  delay(500); 
  
  if (valorInfra == HIGH)
  {digitalWrite(OptoDos, HIGH);
  }
else
{
digitalWrite(OptoDos, LOW);
}

//cm1 = ping(TrigUS1, EchoUS1)
//Serial.print("DistanciaUltraSonidoUno: ");
//Serial.println(cm1);
//delay(1000);
/*if (digitalRead(cm1) <= 20);
{digitalWrite(OptoDos, HIGH);
digitalWrite(OptoTres, HIGH);
}
delay(3);
{digitalWrite(OptoDos, LOW);
digitalWrite(OptoTres, LOW);
}
*/

cm2 = ping2(TrigUS2, EchoUS2);
Serial.print("DistanciaUltraSonidoDos: ");
Serial.println(cm2);
///delay(1000);

if (cm2 <= 20)
{digitalWrite(OptoUno, HIGH);
}
else
//delay(1000);
{
digitalWrite(OptoUno, LOW);
}

}

int ping(int TUS1, int EUS1) {
long duration, distanciaCm1;

digitalWrite(TUS1, LOW);
delayMicroseconds (4);
digitalWrite(TUS1, HIGH);
delayMicroseconds (10);
digitalWrite(TUS1, LOW);

duration = pulseIn(EUS1, HIGH);

distanciaCm1 = duration * 10/ 292/ 2;
return distanciaCm1;
}

int ping2(int TUS2, int EUS2) {
long duration2, distanciaCm2;

digitalWrite(TUS2, LOW);
delayMicroseconds (4);
digitalWrite(TUS2, HIGH);
delayMicroseconds (10);
digitalWrite(TUS2, LOW);

duration2 = pulseIn(EUS2, HIGH);

distanciaCm2 = duration2 * 10/ 292/ 2;
return distanciaCm2;
}
