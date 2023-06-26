
int botao1= 2;
int botao2 = 3;
int led = 13;
int estado1 = 0;
int estado2 = 0;

void setup()
{
  pinMode(led,OUTPUT);
  pinMode(botao1, INPUT);
  pinMode(botao2, INPUT);
}

void loop()
{
  estado1 = digitalRead(botao1);
  estado2 = digitalRead(botao2);
  
  if (estado1 == HIGH)
  {
    digitalWrite(led,HIGH);
  }
  if (estado2 == HIGH)
  {
  	digitalWrite(led, LOW);
  }
}