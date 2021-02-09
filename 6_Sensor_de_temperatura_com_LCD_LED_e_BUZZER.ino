/*
ETB - ESCOLA TÉCNICA DE BRASÍLIA
Aluno: João Victor Xavier Jorge
Turma: 2º "J"
Curso: Técnico em Eletrônica
Data: 17/01/2021 - 17JAN2021
Firmware: PROJETO FINAL-04JAN21
*/

//Inclusão da biblioteca necessária para a utilização do LCD
#include <LiquidCrystal.h>

//Declaramos os valores onde os pinos do LCD estão conectados
//na PDA.
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//Aqui são definidas as variaveis para os pinos da sirene,led e
//sensor de temperatura.
const int buzzer = 8;
const int led_pin = 6;
const int sensorPin = A0;

//Abaixo foram definidas variáveis de tipo ponto flutuante para
//armazenar o valor obtido do sensor de temperatura e um para
//armazenar a conversão de voltagem do mesmo.
float valorSensor = 0;
float temperatura = 0;

//Aqui foi definido um array de possiveis estados
//definidos previamente no escopo do projeto.
String estado[3] = {"OK!OK!", "CUIDADO!", "PERIGO!"};

//É definido o estado inicial do projeto como 0 = "OK!OK!".
int estadoAtual = 0;

//A função setup abaixo será executada uma vez 
//por execução de programa
void setup() {
  //Saida serial definida para fins de teste e debug de código
  Serial.begin(9600);
  
  //São definidos os pinos do buzzer e do led como saidas (output)
  pinMode(buzzer, OUTPUT);
  pinMode(led_pin, OUTPUT);
  
  //Definimos quantas colunas e fileiras (o tamanho) do nosso LCD utilizado
  lcd.begin(16, 2);
}

//A função loop como já define o nome será executada repetidamente
//durante a execução do programa.
void loop() {
  //É chamada a função func_Temp(), para receber os dados da temperatura
  //func_Temp();
  
  //Definimos onde começará a ser escrito os dados no LCD
  lcd.setCursor(0, 0);
  
  //Definimos para que seja escrito a temperatura + seu valor no LCD
  lcd.print("TEMP. = "+ (String)temperatura);
  
  //Definimos novamente o cursor para que seja escrito na segunda linha do LCD
  lcd.setCursor(0,1);
  
  //Iniciamos uma estrutura condicional para atender a exigencias do projeto
  if (temperatura < 0){//SE temperatura MENOR QUE 0 FAÇA
  	//Definimos o estado como 0 = OK!OK!;
    estadoAtual = 0;
  }else if (temperatura > 0){// SENÃO SE temperatura MAIOR QUE 0 FAÇA
  	//Definomos o estado como 2 = "Perigo!";
    estadoAtual = 2;
    
    //Então são executadas as funções de piscar LED e soar o buzzer
    func_Led();
    func_Alarm();
  }else{//SENÃO FAÇA
    //Caso nenhuma das outras condições seja completa 
    // o estado será definido como 1 = "Cuidado!";
  	estadoAtual = 1;
    
    //Então apenas o LED piscará
    func_Led();
  }
  
  //E finalmente será impresso no LCD o Alerta
  //com seu respectivo estado;
  lcd.print("ALERT = "+ estado[estadoAtual]);
  
}

//Funções
/*
	Afim de tornar o código do firmware mais modular,
    foi optado por utilizar funções para operar 
    as atividades do projeto
*/

void func_Alarm(){//Função da sirene
  //É definido o som emitido pela sirene
  //sendo "tone(pino da sirene/buzzer, frequencia em hertz)"
  tone(buzzer, 110);
  
  //definido o tempo de delay
  delay(1000);
  
  //Após o tempo o buzzer será silenciado por 1 segundo
  noTone(buzzer);
  delay(1000);  
}

void func_Led(){//Função do LED
  digitalWrite(led_pin, HIGH);//função para ligar o led
  delay(1000);  //função de espera onde 1000ms == 1s                     
  digitalWrite(led_pin, LOW);//função para desligar o led    
  delay(1000); //função de espera onde 1000ms == 1s
}

void func_Temp(){//Função do sensor de Temperatura
  //é definida a variavel que armazena o valor obtido pelo sensor
  valorSensor = analogRead(sensorPin); 
  
  
  temperatura = valorSensor / 1024;    
  temperatura = temperatura * 5;      
  temperatura = temperatura - 0.5;      
  temperatura = temperatura * 100; 
  Serial.print("Temperatura = ");
  Serial.print(temperatura);
  Serial.println(" C");
  delay(2000);
}
 