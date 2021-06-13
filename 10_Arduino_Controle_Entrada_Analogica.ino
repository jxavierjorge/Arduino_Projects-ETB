const int leds[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13};
const int Potpin = 0;
int PotValue = 0; //Esta variável armazena o valor lido do potenciômetro

void setup()
{
  for (int i = 0; i <= 13; i++){
  	pinMode(leds[i], OUTPUT);
  }  
}

void loop()
{
  PotValue = analogRead(Potpin);
  /*O valor de tensão no potenciômetro
  	é diretamente proporcional
  	ao tempo para trasição de estado dos LEDS */
  
  for(int i = 0; i<= 13; i++){
    digitalWrite(i, HIGH);
    delay(PotValue);
  }
  for(int i = 0; i<= 13; i++){
    digitalWrite(i, LOW);
    delay(PotValue);
  }
}