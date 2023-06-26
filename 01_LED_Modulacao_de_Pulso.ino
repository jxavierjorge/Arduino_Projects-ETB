const int ledPin = 5;
int valor = 0;
float pwm = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  valor = analogRead(A0);
  
  pwm = map(valor, 0, 1023, 0, 255);
  
  Serial.print("Valor lido do potenciometro : ");
  Serial.print(valor);
  Serial.print("	= PWM : ");
  Serial.println(pwm);
  
  analogWrite(5, pwm); 
}
