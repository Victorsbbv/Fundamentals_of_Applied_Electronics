// C++ code
//
void setup()
{
  pinMode(7, OUTPUT); // VERDE CARRO
  pinMode(6, OUTPUT); // AMARELO CARRO
  pinMode(5, OUTPUT); // VERMELHO CARRO
  
  
  pinMode(9, OUTPUT); // VERDE PEDESTRE
  pinMode(8, OUTPUT); // VERMELHO PEDESTRE
}

void loop()
{
  digitalWrite(5, LOW);
  digitalWrite(9, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  delay(8000);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  delay(8000);
  digitalWrite(8, LOW);
  digitalWrite(6, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(9, HIGH);
  delay (8000);
}