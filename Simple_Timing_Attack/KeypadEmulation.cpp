#include "KeypadEmulation.h"
#define DELAY 12

KeypadEmulation::KeypadEmulation()
{
  //INIT ROWS
  pinMode(kEYPADPIN_1, OUTPUT);
  pinMode(kEYPADPIN_2, OUTPUT);
  pinMode(kEYPADPIN_3, OUTPUT);
  pinMode(kEYPADPIN_4, OUTPUT);
  digitalWrite(kEYPADPIN_1, HIGH);
  digitalWrite(kEYPADPIN_2, HIGH);
  digitalWrite(kEYPADPIN_3, HIGH);
  digitalWrite(kEYPADPIN_4, HIGH);
  //INIT COLUMNS
  pinMode(kEYPADPIN_5, INPUT);
  pinMode(kEYPADPIN_6, INPUT);
  pinMode(kEYPADPIN_7, INPUT);
}

unsigned int KeypadEmulation::buttonPushed(int row, int col, bool computeTimeThankSignal)
{
  unsigned int tps = 0;
  //Wait the good configuºration
  pulseIn(col, HIGH);
  digitalWrite(row, LOW); // push
  if (computeTimeThankSignal)
  {
    noInterrupts();
    tps = pulseIn(PB2, HIGH);
    interrupts();
    //Serial.println(tps);
  }
  delay(DELAY); //rebound time

  digitalWrite(row, HIGH); //return to initial state
  delay(13);
  return tps;
}
unsigned int KeypadEmulation::pushButton(unsigned short input, bool computeTimeThankSignal = false)
{
  unsigned int tim = 0;

  switch (input)
  {
    case 1:
      tim = buttonPushed(kEYPADPIN_1, kEYPADPIN_5, computeTimeThankSignal);
      break;
    case 2:
      tim = buttonPushed(kEYPADPIN_1, kEYPADPIN_6, computeTimeThankSignal);
      break;
    case 3:
      tim = buttonPushed(kEYPADPIN_1, kEYPADPIN_7, computeTimeThankSignal);
      break;
    case 4:
      tim = buttonPushed(kEYPADPIN_2, kEYPADPIN_5, computeTimeThankSignal);
      break;
    case 5:
      tim = buttonPushed(kEYPADPIN_2, kEYPADPIN_6, computeTimeThankSignal);
      break;
    case 6:
      tim = buttonPushed(kEYPADPIN_2, kEYPADPIN_7, computeTimeThankSignal);
      break;
    case 7:
      tim = buttonPushed(kEYPADPIN_3, kEYPADPIN_5, computeTimeThankSignal);
      break;
    case 8:
      tim = buttonPushed(kEYPADPIN_3, kEYPADPIN_6, computeTimeThankSignal);
      break;
    case 9:
      tim = buttonPushed(kEYPADPIN_3, kEYPADPIN_7, computeTimeThankSignal);
      break;
    case 10: // start
      tim = buttonPushed(kEYPADPIN_4, kEYPADPIN_5, computeTimeThankSignal);
      break;
    case 0:
      tim = buttonPushed(kEYPADPIN_4, kEYPADPIN_6, computeTimeThankSignal);
      break;
    case 11://hash
      tim = buttonPushed(kEYPADPIN_4, kEYPADPIN_7, computeTimeThankSignal);
      break;
    default:
      break;
  }

  return tim;
}

unsigned int KeypadEmulation::inputSimulation(unsigned short button1, unsigned short button2, unsigned short button3,
                                       unsigned short button4)
{
  pushButton(button1);
  pushButton(button2);
  pushButton(button3);
  return pushButton(button4, true);
}


