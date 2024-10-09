// C++ code
//
void setup()
{
  pinMode (A0, INPUT);
  pinMode (A1, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int X = analogRead(A0);
  int Y = analogRead(A1);
  
  
  Serial.print("O eixo X tem o valor: ");
  Serial.println(X);
  Serial.print("O eixo Y tem o valor: ");
  Serial.println(Y);
  delay (5000);
}