//
//Aluno: João Victor Xavier Jorge
//Matricula: 17717-2
//Turma: 2J
//TESTE T3 09DEZ20
//

/*

  PRIMEIRO PASSO:
  Incluir as bibliotecas necessárias
  neste caso será necessaria apenas a inclusão
  da biblioteca do LCD
  
*/

#include <LiquidCrystal.h>

/*

  SEGUNDO PASSO:
  Declarar a variáveis que serão utilizadas durante
  a execução do programa
  São elas:
  V0pin e V1pin para armazenar as portas onde
  as conexões de saída do sensor de temperatura e
  a saída da associação de diodos
  foram ligadas -> A0 e A1;
  
  *A variáveis do tipo ponto flutuante (float) Valor0 e Valor1
  servirão para armazenar o valor de leitura 
  analógica do sensor e dos diodos;
  
*/

int analogPin0 = A0;
int analogPin1 = A1;

float valor0 = 0;
float valor1 = 0;

//TERCEIRO PASSO:
//Informar ao lcd onde seus pinos estão ligados
//Seguindo a ordem: lcd(e,rs,d4,d5,d6,d7);

LiquidCrystal lcd(6, 7, 2, 3, 4, 5);

void setup()
{
  //QUARTO PASSO: Inicializar o lcd, informando sua configuração
  //lcd.begin(quantidade máxima de colunas, quantidade máxima de linhas);
  lcd.begin(16,2);
}

void loop()
{
  lcd.setCursor(0, 0); //Definir o início onde deverá começar a escrita do lcd;
  
  //Abaixo as variáveis valor0 e valor1 armazenarão o valor lido nas entradas
  //analógicas;
  
  valor0 = analogRead(analogPin0);
  valor1 = analogRead(analogPin1);
  
  //As funções lcd.print(), servirão para mostrar os dados obtidos
  //na tela de lcd
  
  lcd.print("V1 = ");
  lcd.print(valor0);
  lcd.print("V");
  
  /*
  
  Para imprimir em uma linha abaixo é necessário redefinirmos o cursor 
  para isso utilizamos novamente a função lcd.setCursor() para ir para a linha 1
  na segunda coluna
  
  lcd.setCursor(coluna desejada, linha desejada);
  
  */
  
  lcd.setCursor(0,1);
  
  //As funções lcd.print(), servirão para mostrar os dados obtidos
  //na tela de lcd  
  
  lcd.print("V2 = ");
  lcd.print(valor1);
  lcd.print("V");
}