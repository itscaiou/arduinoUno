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
  Serial.println(analogRead(A0));
  Serial.println(analogRead(A1));
  if (analogRead(A0) > 200) {
    analogWrite(6, 180);
    analogWrite(9, 0);
  }
  else{
    analogWrite(6, 0);
    analogWrite(9, 180);
  }
  if (analogRead(A1) > 200) {
      analogWrite(3, 180);
      analogWrite(5, 0);
  }
  else{
    analogWrite(3, 0);
    analogWrite(5, 180);
  }
  delay(10); // Delay a little bit to improve simulation performance
}
