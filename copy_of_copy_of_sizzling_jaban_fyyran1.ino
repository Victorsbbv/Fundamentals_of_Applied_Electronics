// C++ code
//
int buttonstate = 0;

void setup()
{
  pinMode (A0, INPUT); // X
  pinMode (A1, INPUT); // Y
  pinMode (2, INPUT); // BOTÃO
  Serial.begin(9600);
}

void loop()
{
  int X = analogRead(A0);
  int Y = analogRead(A1);
  buttonstate = digitalRead(2);
  
  
  if (buttonstate == 1){
  Serial.println ("Button Pressionado");  
  }
  else{
  Serial.println ("Button Livre");  
  }
  
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