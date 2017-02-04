#include <LiquidCrystal.h>

#define RS 8
#define E 7
#define D4 6
#define D5 5
#define D6 4
#define D7 3
#define LCDCOLS 20
#define LCDROWS 4

LiquidCrystal lcd(RS, E, D4, D5, D6, D7);

const byte ledpin = 12;

long long int modpow(long long int m, long long int k, long long int n) {

  long long int result = 1;

  while (k > 0) {
    delay(10);
    digitalWrite(ledpin, HIGH);//ICI
    if ((k & 1) > 0) result = (result * m) % n;
    digitalWrite(ledpin, LOW);//
    k >>= 1;
    m = (m * m) % n;
    
  }

  return result;
}
void setup() {
  pinMode(ledpin, OUTPUT);
  Serial.begin(9600);
  lcd.begin(LCDCOLS, LCDROWS);
  lcd.setCursor(0, 0);
}
unsigned long int message = 0;
void loop()
{
  lcd.clear();
  message = 0;
  message = modpow(613056069, 583362317, 3209365189);
  String key = String(583362317, BIN);
  lcd.print(key);
  delay(10000);


}

