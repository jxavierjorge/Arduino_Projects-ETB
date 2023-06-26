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
  VP1pin e VP2pin para armazenar as portas onde
  os potenciômetros foram ligados -> A0 = 0 e A1=1
  
  *A variáveis do tipo ponto flutuante (float) VP1 e VP2
  servirão para armazenar o valor de leitura dos potenciômetros
  
  *A variavel 'subtracao' servira para
  armazenar o resultado da diferença
  entre os valora de VP1 e VP2
  
*/

const int VP1pin = 0;
const int VP2pin = 1;
float VP1 = 0.0;
float VP2 = 0.0;
float subtracao = 0.0;

//TERCEIRO PASSO: Declarar os pinos utilizados para ligar o LCD
//A ordem é a seguinte:
//LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {

  
  //O comando abaixo é utilizado para inicializar
  //o LCD informando o tamanho de linhas
  //e colunas do componente
  
  lcd.begin(16, 2);
}

void loop() {
  /*
  
  Abaixo foi definido para que as variáveis VP1 e VP2
  armazenem a leitura de seus respectivos pinos
  
  */
  VP1 = analogRead(VP1pin);
  VP2 = analogRead(VP2pin);
  
  /*
  
  Agora será salvo estes valores na memória do arduino e 
  podemos dizer para que ele subtraia esses valores e
  armazene na variável subtração
  
  */
  
  subtracao = VP1-VP2;
  
  /*
  
  O comando 'lcd.setCursor(0,0)' serve para que informemos onde o
  LCD deve começar a escrever, sendo o primeiro numero a coluna
  no nosso caso pode ir de 0 a 15 e linhas (de 0 a 1)
  
  *ATENÇÃO: esse comando vai variar de acordo com o tamanho do LCD*
  
  */
  
  lcd.setCursor(0, 0);
  
  //Nas linhas de código abaixo ocorre a declaração das condições do programa
  
  if (subtracao > 0){          /* SE (valor subtraido MAIOR QUE 0) FAÇA */
    
  	lcd.print("Positivo    "); // lcd.print() irá imprimir a palavra 'Positivo'
    lcd.setCursor(0,1);        //Definir o cursor para a linha abaixo
    lcd.print("            "); //Esta linha servirá para 'apagar' a linha caso tenha algo escrito previamente
    
  }else if (subtracao < 0){    /* SE ENTÃO (valor subtraido MENOR QUE 0) FAÇA */
    
  	lcd.print("Negativo    "); // lcd.print() irá imprimir a palavra 'Negativo'
    lcd.setCursor(0,1);        //Definir o cursor para a linha abaixo
    lcd.print(subtracao);      // lcd.print() irá imprimir o valor da subtração
    lcd.print("    ");         //Esta linha servirá para 'apagar' a linha caso tenha algo escrito previamente
    
  }else{                       /* SENÃO FAÇA <-Essa condição será apenas comprida se nenhuma das duas anteriores for atendida */
    
  	lcd.print(subtracao);      // lcd.print() irá imprimir o valor da subtração
    lcd.print("V   ");         // lcd.print() irá imprimir a letra 'V' para definir a unidade de medida para tensão
    lcd.setCursor(0,1);        //Definir o cursor para a linha abaixo
    lcd.print("PERIGO!");      // lcd.print() irá imprimir 'PERIGO!' na linha inferior do LCD
  }
}