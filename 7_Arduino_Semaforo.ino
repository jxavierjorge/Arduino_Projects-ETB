const int redLed_pin = 4;
const int yellowLed_pin = 3;
const int greenLed_pin = 2;

void setup()
{
  pinMode(redLed_pin, OUTPUT);
  pinMode(yellowLed_pin, OUTPUT);
  pinMode(greenLed_pin, OUTPUT);
}

void loop()
{
  
  digitalWrite(greenLed_pin, HIGH);
  delay(3000);
  digitalWrite(greenLed_pin, LOW);
  delay(1000);
  
  digitalWrite(yellowLed_pin, HIGH);
  delay(1000);
  digitalWrite(yellowLed_pin, LOW);
  delay(1000);
  
  digitalWrite(redLed_pin, HIGH);
  delay(3000);
  digitalWrite(redLed_pin, LOW);
  delay(1000);
}