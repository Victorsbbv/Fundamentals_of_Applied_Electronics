#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20, 16, 2);

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
  lcd.init();
  lcd.backlight();
  
  int X = analogRead(A0);
  int Y = analogRead(A1);
  buttonstate = digitalRead(2);
  
  Serial.print ("O eixo X eh: ");
  Serial.println (X);
  Serial.print ("O eixo Y eh: ");
  Serial.println (Y);
  Serial.println ("--------------");
  
  
  if (buttonstate == 1){
  Serial.println ("Button Pressionado");
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Button Pressionado"); 
  }
  else{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print ("Button Livre");  
  }
  
  if (X <= 200){
   lcd.setCursor(0, 1);
   lcd.print ("O eixo x direita");
  }
  else
   if (X > 200 && X <= 400){
   lcd.setCursor(0, 1);
   lcd.print ("O eixo x esquerda");
  }
  
                            if ( X > 400){                          
  if (Y > 400 && Y <= 600){
   lcd.setCursor(0, 1);
   lcd.print ("O eixo Y cima");
  }
  else
   if (Y > 600 && Y <= 800){
   lcd.setCursor(0, 1);
   lcd.print ("O eixo Y baixo");
  }
                            }
  delay (5000);
  
  /* Serial.print("O eixo X tem o valor: ");
  Serial.println(X);
  Serial.print("O eixo Y tem o valor: ");
  Serial.println(Y);
  delay (5000); */
}