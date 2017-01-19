#include "Keypad.h"
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

const byte ledpin = 13;

bool secretPass(char userInput[4]);
void setUserInput();
char userInput[4];
int i = 0, j = 0;

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[ROWS] = {14, 15, 16, 17}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {18, 19, 2}; //connect to the column pinouts of the keypad
Keypad mykeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  pinMode(ledpin, OUTPUT);
  Serial.begin(9600);
  lcd.begin(LCDCOLS, LCDROWS);
  lcd.setCursor(0, 0);
  lcd.print("Put your password:");
}

void loop()
{
  setUserInput();
}

void setUserInput()
{
  char key = mykeypad.getKey();

  if (key != NO_KEY)
  {
    if (i == 0) lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Put your password:");
    lcd.setCursor(i % 4, 1);
    lcd.print(key);
    //Serial.println(key);
    userInput[i % 4] = key;
    if (sizeof(userInput) > 4) exit(0); //check input

    i++;
    if (i > 3)
    {
      i = 0;
      j++;

      //delayMicroseconds(1);
      
      //delay(500);
      //Serial.println(userInput);
      lcd.setCursor(0, 2);
      if (secretPass(userInput)) lcd.print("Access granted");
      else
      {
        lcd.print("Acess denied");
      }
      digitalWrite(ledpin, LOW);

    }
  }
}
bool secretPass(char userInput[4])
{
  char passw[4] = "1315";
  bool isEqual;
  digitalWrite(ledpin, HIGH);
  isEqual = !strncmp(passw, userInput, 4);
  return isEqual;
}
