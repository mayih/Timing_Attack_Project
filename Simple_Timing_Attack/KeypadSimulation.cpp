#include "KeypadSimulation.h"
void keyPadInit()
{
  pinMode(kEYPADPIN_1, OUTPUT);
  pinMode(kEYPADPIN_2, OUTPUT);
  pinMode(kEYPADPIN_3, OUTPUT);
  pinMode(kEYPADPIN_4, OUTPUT);
  
   pinMode(kEYPADPIN_5, OUTPUT);
  pinMode(kEYPADPIN_6, OUTPUT);
  pinMode(kEYPADPIN_7, OUTPUT);
  
  digitalWrite(kEYPADPIN_5, LOW);
  digitalWrite(kEYPADPIN_6, LOW);
  digitalWrite(kEYPADPIN_7, LOW);
  
  pinMode(kEYPADPIN_5, INPUT);
  pinMode(kEYPADPIN_6, INPUT);
  pinMode(kEYPADPIN_7, INPUT);

  
  digitalWrite(kEYPADPIN_1, HIGH);
  digitalWrite(kEYPADPIN_2, HIGH);
  digitalWrite(kEYPADPIN_3, HIGH);
  digitalWrite(kEYPADPIN_4, HIGH);
     

}
void inputSimulation(int input)
{

  switch (input)
  {
    case 1:
      digitalWrite(kEYPADPIN_1, LOW);
      digitalWrite(kEYPADPIN_5, LOW);
      delayMicroseconds(100);
      digitalWrite(kEYPADPIN_1, HIGH);
      digitalWrite(kEYPADPIN_5, HIGH);

      break;
    case 2:
      digitalWrite(kEYPADPIN_6, LOW);
      digitalWrite(kEYPADPIN_1, LOW);
      delayMicroseconds(100);
      digitalWrite(kEYPADPIN_6, HIGH);
      digitalWrite(kEYPADPIN_1, HIGH);

      break;
    case 3:
      digitalWrite(kEYPADPIN_1, LOW);
      digitalWrite(kEYPADPIN_7, LOW);
      delayMicroseconds(100);
      digitalWrite(kEYPADPIN_1, HIGH);
      digitalWrite(kEYPADPIN_7, HIGH);
      break;
    case 4:
      digitalWrite(kEYPADPIN_2, LOW);
      digitalWrite(kEYPADPIN_5, LOW);
      delayMicroseconds(100);
      digitalWrite(kEYPADPIN_2, HIGH);
      digitalWrite(kEYPADPIN_5, HIGH);
      break;
    case 5:
      digitalWrite(kEYPADPIN_2, LOW);
      digitalWrite(kEYPADPIN_6, LOW);
      delayMicroseconds(100);
      digitalWrite(kEYPADPIN_2, HIGH);
      digitalWrite(kEYPADPIN_6, HIGH);
      break;
    case 6:
      digitalWrite(kEYPADPIN_2, LOW);
      digitalWrite(kEYPADPIN_7, LOW);
      delayMicroseconds(100);
      digitalWrite(kEYPADPIN_2, HIGH);
      digitalWrite(kEYPADPIN_7, HIGH);
      break;
    case 7:
      digitalWrite(kEYPADPIN_3, LOW);
      digitalWrite(kEYPADPIN_5, LOW);
      delayMicroseconds(100);
      digitalWrite(kEYPADPIN_3, HIGH);
      digitalWrite(kEYPADPIN_5, HIGH);
      break;
    case 8:
      digitalWrite(kEYPADPIN_3, LOW);
      digitalWrite(kEYPADPIN_6, LOW);
      delayMicroseconds(100);
      digitalWrite(kEYPADPIN_3, HIGH);
      digitalWrite(kEYPADPIN_6, HIGH);
      break;
    case 9:
      digitalWrite(kEYPADPIN_3, LOW);
      digitalWrite(kEYPADPIN_7, LOW);
      delayMicroseconds(100);
      digitalWrite(kEYPADPIN_3, HIGH);
      digitalWrite(kEYPADPIN_7, HIGH);
      break;
    case 10: // start
      digitalWrite(kEYPADPIN_4, LOW);
      digitalWrite(kEYPADPIN_5, LOW);
      delayMicroseconds(100);
      digitalWrite(kEYPADPIN_4, HIGH);
      digitalWrite(kEYPADPIN_5, HIGH);
      break;
    case 0:
      digitalWrite(kEYPADPIN_4, LOW);
      digitalWrite(kEYPADPIN_6, LOW);
      delayMicroseconds(100);
      digitalWrite(kEYPADPIN_4, HIGH);
      digitalWrite(kEYPADPIN_6, HIGH);
      break;
    case 11://hash
      digitalWrite(kEYPADPIN_4, LOW);
      digitalWrite(kEYPADPIN_7, LOW);
      delayMicroseconds(100);
      digitalWrite(kEYPADPIN_4, HIGH);
      digitalWrite(kEYPADPIN_7, HIGH);
      break;
    default:
      break;
  }
}

