// C++ code
//
#include <Servo.h>

int Frente = 0;

int Direita = 0;

int Esquerda = 0;

int unnamed = 0;

int i = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

Servo servo_11;

void setup()
{
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
  servo_11.attach(11, 500, 2500);

  Frente = 15;
  Esquerda = 15;
  Direita = 15;
}

void loop()
{
  digitalWrite(3, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(9, LOW);
  Serial.println(0.01723 * readUltrasonicDistance(A0, A1));
  if (0.01723 * readUltrasonicDistance(A0, A1) < 15) {
    servo_11.write(90);
  }
  delay(10); // Delay a little bit to improve simulation performance
}
