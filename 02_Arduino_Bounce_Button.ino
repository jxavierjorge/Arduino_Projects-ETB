const int pinLed = 13;
const int buttonPin = 2;

int buttonState = 0;

void setup()
{
  pinMode(pinLed, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop()
{
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == HIGH){
  	digitalWrite(pinLed,HIGH);
  }
  else{
  	digitalWrite(pinLed,LOW);
  }
  
}