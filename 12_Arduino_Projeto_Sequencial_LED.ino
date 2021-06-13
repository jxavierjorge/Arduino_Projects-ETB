const int leds[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13};
const int delayON = 250; //Em microssegundos
const int delayOFF = 50; //Em microssegundos

void setup()
{
  for (int i = 0; i <= 13; i++){
  	pinMode(leds[i], OUTPUT);
  }  
}

void loop()
{
  for(int i = 0; i<= 13; i++){
    digitalWrite(i, HIGH);
    delay(delayON);
  }
    for(int i = 0; i<= 13; i++){
      digitalWrite(i, LOW);
      delay(delayOFF);
   }
}