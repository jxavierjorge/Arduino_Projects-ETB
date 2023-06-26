int botao = 2;
int led = 13;
int estado = 0;
int ledState = LOW;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(botao, INPUT);
}

void loop()
{
  estado = digitalRead(botao);
  if(estado == HIGH)
  {
    if(ledState == LOW)
    {
      ledState = HIGH;
    }
    else
    {
      ledState = LOW;
    }
    delay(100);
  }
  digitalWrite(led, ledState);
}