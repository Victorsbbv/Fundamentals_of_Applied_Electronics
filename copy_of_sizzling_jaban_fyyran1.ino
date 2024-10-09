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
  
  
  if (X >= 512){
   Serial.print ("O eixo x esta para a direita, pois seu valor eh: ");
   Serial.println(X);
  }
  else{
   Serial.print ("O eixo x esta para a esquerda, pois seu valor eh: ");
   Serial.println(X);
  }
  
  if (Y >= 512){
   Serial.print ("O eixo Y esta para a cima, pois seu valor eh: ");
   Serial.println(Y);
  }
  else{
   Serial.print ("O eixo Y esta para a baixo, pois seu valor eh: ");
   Serial.println(Y);
  }
  delay (5000);
  
  /* Serial.print("O eixo X tem o valor: ");
  Serial.println(X);
  Serial.print("O eixo Y tem o valor: ");
  Serial.println(Y);
  delay (5000); */
}