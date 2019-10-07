
// Declaro la variable donde esta conectado el led del ESP32
int LED_ONBOARD = 2;


void setup() {
  // put your setup code here, to run once:
pinMode(LED_ONBOARD,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(LED_ONBOARD,HIGH);
  delay(1000);
  digitalWrite(LED_ONBOARD,LOW);
  delay(1000);

}
