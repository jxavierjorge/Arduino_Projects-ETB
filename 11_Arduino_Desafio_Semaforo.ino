const int ledCarPinRED = 8;
const int ledCarPinYELLOW = 9;
const int ledCarPinGREEN = 10;
const int ledPedestrianPinRED = 11;
const int ledPedestrianPinGREEN = 12;


void setup()
{
  pinMode(ledCarPinRED, OUTPUT);
  pinMode(ledCarPinYELLOW, OUTPUT);
  pinMode(ledCarPinGREEN, OUTPUT);
  pinMode(ledPedestrianPinRED, OUTPUT);
  pinMode(ledPedestrianPinGREEN, OUTPUT);
}

void loop()
{
  digitalWrite(ledCarPinGREEN, HIGH);
  digitalWrite(ledPedestrianPinRED, HIGH);
  
  delay(5000);
  
  digitalWrite(ledCarPinGREEN, LOW);
  digitalWrite(ledCarPinYELLOW, HIGH);
  
  delay(5000);
  
  digitalWrite(ledCarPinYELLOW, LOW);
  digitalWrite(ledCarPinRED, HIGH);
  digitalWrite(ledPedestrianPinRED, LOW);
  digitalWrite(ledPedestrianPinGREEN, HIGH);
  
  for( int i = 0; i < 10; i++) {
  	digitalWrite(ledPedestrianPinGREEN, HIGH);
    delay(500);
    digitalWrite(ledPedestrianPinGREEN, LOW);
    delay(500);
  }
  
  digitalWrite(ledPedestrianPinGREEN, LOW);
  digitalWrite(ledCarPinRED, LOW);
}