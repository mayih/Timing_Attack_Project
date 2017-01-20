#include "KeypadEmulation.h"
#define DELAY 10

KeypadEmulation::KeypadEmulation()
{
  //INIT ROWS
  pinMode(kEYPADPIN_1, OUTPUT);
  pinMode(kEYPADPIN_2, OUTPUT);
  pinMode(kEYPADPIN_3, OUTPUT);
  pinMode(kEYPADPIN_4, OUTPUT);

  //INIT COLUMNS
  pinMode(kEYPADPIN_5, INPUT);
  pinMode(kEYPADPIN_6, INPUT);
  pinMode(kEYPADPIN_7, INPUT);
}

unsigned long KeypadEmulation::buttonPushed(int row, int col, bool computeTimeThankSignal)
{
  if (!computeTimeThankSignal)
  {

    //Wait the good configuration
    while (digitalRead(col) != LOW);
    digitalWrite(row, LOW); // push
    delay(DELAY); //rebound time
    digitalWrite(row, HIGH); //return to initial state
    delay(13);
    return 0;
  }

  //Initialisation
  int startTime = 0, endTime = 0;
  //Wait the good configuration
  while (digitalRead(col) != LOW);
  digitalWrite(row, LOW); // push
  delay(DELAY); //rebound time
    startTime = micros();
  while (digitalRead(PB2) != LOW);
  endTime = micros(); // while receive signal
  digitalWrite(row, HIGH); //return to initial state
    
 
  delay(13);
  return endTime - startTime;// return diff
}
unsigned long KeypadEmulation::pushButton(unsigned short input, bool computeTimeThankSignal = false)
{
  unsigned long tim = 0;

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

unsigned long KeypadEmulation::inputSimulation(unsigned short button1, unsigned short button2, unsigned short button3,
    unsigned short button4)
{
  pushButton(button1);
  pushButton(button2);
  pushButton(button3);
  return pushButton(button4, true);
}


