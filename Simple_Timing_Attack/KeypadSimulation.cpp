#include "KeypadSimulation.h"
void keyPadInit()
{
  pinMode(kEYPADPIN_1, OUTPUT);
  pinMode(kEYPADPIN_2, OUTPUT);
  pinMode(kEYPADPIN_3, OUTPUT);
  pinMode(kEYPADPIN_4, OUTPUT);


  pinMode(kEYPADPIN_5, INPUT);
  pinMode(kEYPADPIN_6, INPUT);
  pinMode(kEYPADPIN_7, INPUT);

}
void inputSimulation(int input)
{
 
  switch (input)
  {
    case 1:
      
      while (digitalRead(kEYPADPIN_5) == HIGH);
      digitalWrite(kEYPADPIN_1, LOW);
      while (digitalRead(kEYPADPIN_6) == LOW);
      while (digitalRead(kEYPADPIN_7) == LOW);
      digitalWrite(kEYPADPIN_1, HIGH);

      break;
    case 2:
    
      while (digitalRead(kEYPADPIN_6) == HIGH);
      digitalWrite(kEYPADPIN_1, LOW);
      while (digitalRead(kEYPADPIN_7) == LOW);
      while (digitalRead(kEYPADPIN_5) == LOW);
      digitalWrite(kEYPADPIN_1, HIGH);
      break;
    case 3:
      while (digitalRead(kEYPADPIN_7) == HIGH);
      
      digitalWrite(kEYPADPIN_1, LOW);
      delayMicroseconds(3);
      digitalWrite(kEYPADPIN_1, HIGH);
      break;
    case 4:
      while (digitalRead(kEYPADPIN_5) == HIGH);

      digitalWrite(kEYPADPIN_2, LOW);
       delayMicroseconds(13);
       digitalWrite(kEYPADPIN_2, HIGH);

       Serial.println(4);
      break;
    case 5:
      while (digitalRead(kEYPADPIN_6) == HIGH);

      digitalWrite(kEYPADPIN_2, LOW);
      break;
    case 6:
      while (digitalRead(kEYPADPIN_7) == HIGH);

      digitalWrite(kEYPADPIN_2, LOW);
      break;
    case 7:
      while (digitalRead(kEYPADPIN_5) == HIGH);

      digitalWrite(kEYPADPIN_3, LOW);
      break;
    case 8:
      while (digitalRead(kEYPADPIN_6) == HIGH);

      digitalWrite(kEYPADPIN_3, LOW);
      break;
    case 9:
      while (digitalRead(kEYPADPIN_7) == HIGH);

      digitalWrite(kEYPADPIN_3, LOW);
      break;
    case 10: // start
      while (digitalRead(kEYPADPIN_5) == HIGH);

      digitalWrite(kEYPADPIN_4, LOW);
      break;
    case 0:
      while (digitalRead(kEYPADPIN_6) == HIGH);

      digitalWrite(kEYPADPIN_4, LOW);
      break;
    case 11://hash
      while (digitalRead(kEYPADPIN_7) == HIGH);

      digitalWrite(kEYPADPIN_4, LOW);
      break;
    default:
      break;
  }
  


}

