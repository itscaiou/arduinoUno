#include <SoftwareSerial.h>

// Definição dos pinos para comunicação com o módulo Bluetooth
int bluetoothTx = 10;  // Pino TX do módulo Bluetooth conectado ao RX do Arduino
int bluetoothRx = 11;  // Pino RX do módulo Bluetooth conectado ao TX do Arduino

// Inicialização do objeto para comunicação Bluetooth
SoftwareSerial bluetooth(bluetoothRx, bluetoothTx);


void setup() 
{
  // Inicialização da comunicação serial padrão (para comunicação com o computador via USB)
  Serial.begin(9600);
  
  // Inicialização da comunicação serial com o módulo Bluetooth
  bluetooth.begin(9600);

  // Motor Esquerdo
  pinMode(13, OUTPUT);

  {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
}
}


void loop() 
{
   if(bluetooth.available() > 0)
   {
	char direcao = bluetooth.read();
    // Condicional para Ligar o LED
    if (direcao == '1') {
    digitalWrite(13,HIGH);
    Serial.println('LIGADO');
    }
    // Condicional para Desligar o LED
    if (direcao == '0') {
    digitalWrite(13,LOW);
    Serial.println('DESLIGADO');
    }
    if (direcao == '2') { // PARA FRENTE
      digitalWrite(3, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      digitalWrite(9, LOW);
    }
    if (direcao == '3') { // PARA ESQUERDA
      digitalWrite(3, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(9, LOW);
    }
    if (direcao == '4') { // PARA DIREITA
      digitalWrite(3, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      digitalWrite(9, LOW);
    }
    if (direcao == '5') { // PARA TRÁS
      digitalWrite(3, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);
      digitalWrite(9, HIGH);
    }
    if (direcao == '6') { // STOP
      digitalWrite(3, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(9, LOW);
    }
   }
}
