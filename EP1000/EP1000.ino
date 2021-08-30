//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#define DHTPIN 1
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
dht.begin();
 lcd.init();                     
 lcd.init();
}


void loop()
{
  delay (500);
  int stat = 0;
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  if( h < 20 ){
    stat =1;
  }
  
  if (h > 50){
    stat =2;
  }
  String p= "nominal";
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.setCursor(5,0);
  lcd.print(t);
  lcd.setCursor(0,1);
  lcd.print("Hum:");
  lcd.setCursor(05,1);
  lcd.print(h);
  
  if (stat==1){
  lcd.setCursor(9,0);
  lcd.print("increase");
  lcd.setCursor(9,1);
  lcd.print(p);
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  }
  
  if (stat==2){
  lcd.setCursor(9,0);
  lcd.print("OK!");
  lcd.setCursor(9,1);
  lcd.print(p);
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  }
  
}
