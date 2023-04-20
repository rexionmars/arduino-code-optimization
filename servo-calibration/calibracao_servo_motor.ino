#include "Servo.h"                                //biblioteca para o servo
Servo servo;                                      //cria o objeto servo
int angulo=0;                                     //variável do tipo inteira
String valor_recebido = "";                       //string para receber o valor digitado


void setup(){
  Serial.begin(9600);                             //inicia a comunicação serial
  servo.attach(6);                               //anexa o servo ao pino 10
  Serial.println("AGUARDANDO COMANDO");           //imprime o texto entre aspas
}    
void loop(){

    while (Serial.available() > 0) {              //enquanto houver dados na comunicação serial, faça...
    int caracter_digitado = Serial.read();        //leitura dos caracteres 
    if (isDigit(caracter_digitado)) {             //se o caracter for um digito, faça...
      valor_recebido += (char)caracter_digitado;  //atribui ao valor_recebido o caracter_digitado
      }

    if (caracter_digitado == '\n') {              //se o caracter_digitado for nulo (fim da leitura), faça...
      angulo = valor_recebido.toInt();            //coverte o valor_recebido para inteiro e atribui ao angulo
      Serial.print("Angulo atual: "); Serial.println(angulo);     //mostra o angulo atual no monitor
      //angulo = map(angulo, 0,180,0,150);        //calibração
      servo.write(angulo);                        //move o servo para o angulo informado
      valor_recebido = "";                        //limpa as inforçoes guardadas em valor_recebido
     }
   }  
 }
