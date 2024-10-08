#include <SPI.h> //sensor
#include <MFRC522.h> //sensor
#include<LiquidCrystal.h> // LCD

#define SS_PIN 10 //sensor
#define RST_PIN 9 //sensor

MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  lcd.begin(16, 2);
  Serial.begin(9600);
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
}

void loop()
{
  
  // ACESSO NEGADO
    Serial.println("Acesso Negado");
    lcd.setCursor(1,0);          
    lcd.print("Acesso negado");

   // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }

  String content= ""; 

  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  
 // ACESSSO AUTORIZADO 
  content.toUpperCase();
  if (content.substring(1) == "C6 66 A1 AC" ){
    Serial.println("Acesso Autorizado");
    lcd.setCursor(1,1);          
    lcd.print("Acesso Autorizado"); 
  }
  
  delay(500);
}