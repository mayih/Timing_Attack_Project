#include "KeypadSimulation.h"
#define DELAY 10

KeypadSimulation::KeypadSimulation()
{
  pinMode(kEYPADPIN_1, OUTPUT);
  pinMode(kEYPADPIN_2, OUTPUT);
  pinMode(kEYPADPIN_3, OUTPUT);
  pinMode(kEYPADPIN_4, OUTPUT);


  pinMode(kEYPADPIN_5, INPUT);
  pinMode(kEYPADPIN_6, INPUT);
  pinMode(kEYPADPIN_7, INPUT);


  m_inputTime = 0;
}
unsigned long KeypadSimulation::pushButton(unsigned short input)
{
  int tps_1 = 0, tps_2 = 0;

  switch (input)
  {
    case 1:
      while (digitalRead(kEYPADPIN_5) != LOW);
      digitalWrite(kEYPADPIN_1, LOW);
      delay(DELAY);
      tps_1 = micros();
      while (digitalRead(PB2) != LOW);
      tps_2 = micros();
      digitalWrite(kEYPADPIN_1, HIGH);
      break;
    case 2:
      while (digitalRead(kEYPADPIN_6) != LOW );
      digitalWrite(kEYPADPIN_1, LOW);
      delay(DELAY);
      tps_1 = micros();
      while (digitalRead(PB2) != LOW);
      tps_2 = micros();
      digitalWrite(kEYPADPIN_1, HIGH);
      break;
    case 3:
      while (digitalRead(kEYPADPIN_7) != LOW);
      digitalWrite(kEYPADPIN_1, LOW);
      delay(DELAY);
      tps_1 = micros();
      while (digitalRead(PB2) != LOW);
      tps_2 = micros();
      digitalWrite(kEYPADPIN_1, HIGH);
      break;
    case 4:
      while (digitalRead(kEYPADPIN_5) == HIGH);
      digitalWrite(kEYPADPIN_2, LOW);
      delay(DELAY);
      tps_1 = micros();
      while (digitalRead(PB2) != LOW);
      tps_2 = micros();
      digitalWrite(kEYPADPIN_2, HIGH);
      break;
    case 5:
      while (digitalRead(kEYPADPIN_6) == HIGH);
      digitalWrite(kEYPADPIN_2, LOW);
      delay(DELAY);
      tps_1 = micros();
      while (digitalRead(PB2) != LOW);
      tps_2 = micros();
      digitalWrite(kEYPADPIN_2, HIGH);
      break;
    case 6:
      while (digitalRead(kEYPADPIN_7) == HIGH);
      digitalWrite(kEYPADPIN_2, LOW);
      delay(DELAY);
      tps_1 = micros();
      while (digitalRead(PB2) != LOW);
      tps_2 = micros();
      digitalWrite(kEYPADPIN_2, HIGH);
      break;
    case 7:
      while (digitalRead(kEYPADPIN_5) == HIGH);
      digitalWrite(kEYPADPIN_3, LOW);
      delay(DELAY);
      tps_1 = micros();
      while (digitalRead(PB2) != LOW);
      tps_2 = micros();
      digitalWrite(kEYPADPIN_3, HIGH);
      break;
    case 8:
      while (digitalRead(kEYPADPIN_6) == HIGH);
      digitalWrite(kEYPADPIN_3, LOW);
      delay(DELAY);
      tps_1 = micros();
      while (digitalRead(PB2) != LOW);
      tps_2 = micros();
      digitalWrite(kEYPADPIN_3, HIGH);
      break;
    case 9:
      while (digitalRead(kEYPADPIN_7) == HIGH);
      digitalWrite(kEYPADPIN_3, LOW);
      delay(DELAY);
      tps_1 = micros();
      while (digitalRead(PB2) != LOW);
      tps_2 = micros();
      digitalWrite(kEYPADPIN_3, HIGH);
      break;
    case 10: // start
      while (digitalRead(kEYPADPIN_5) == HIGH);
      digitalWrite(kEYPADPIN_4, LOW);
      delay(DELAY);
      tps_1 = micros();
      while (digitalRead(PB2) != LOW);
      tps_2 = micros();
      digitalWrite(kEYPADPIN_4, HIGH);
      break;
    case 0:
      while (digitalRead(kEYPADPIN_6) == HIGH);
      digitalWrite(kEYPADPIN_4, LOW);
      delay(DELAY);
      tps_1 = micros();
      while (digitalRead(PB2) != LOW);
      tps_2 = micros();
      digitalWrite(kEYPADPIN_4, HIGH);
      break;
    case 11://hash
      while (digitalRead(kEYPADPIN_7) == HIGH);
      digitalWrite(kEYPADPIN_4, LOW);
      delay(DELAY);
      tps_1 = micros();
      while (digitalRead(PB2) != LOW);
      tps_2 = micros();
      digitalWrite(kEYPADPIN_4, HIGH);
      break;
    default:
      break;
  }
  delay(13);
  return tps_2 - tps_1;

  
}

unsigned long KeypadSimulation::inputSimulation(unsigned short button1, unsigned short button2, unsigned short button3, unsigned short button4)
{
  pushButton(button1);
  pushButton(button2);
  pushButton(button3);
  return pushButton(button4);
}


