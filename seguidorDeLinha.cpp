// C++ code
//
void setup()
{
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(A1, INPUT);
}

void loop()
{
  analogWrite(3, LOW);
  analogWrite(5, 150);
  analogWrite(6, LOW);
  analogWrite(9, 150);
  Serial.println(analogRead(A0));
  Serial.println(analogRead(A1));
  if (analogRead(A0) > 200) {
    analogWrite(3, LOW);
    analogWrite(5, 150);
    analogWrite(6, LOW);
    analogWrite(9, LOW);
  }
  if (analogRead(A1) > 200) {
      analogWrite(3, LOW);
      analogWrite(5, LOW);
      analogWrite(6, LOW);
      analogWrite(9, 150);
  }
  delay(10); // Delay a little bit to improve simulation performance
}
