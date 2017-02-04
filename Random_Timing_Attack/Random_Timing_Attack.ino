#include "KeypadEmulation.h"

KeypadEmulation keypadS;
unsigned short maximums[4] = {0}; //password
void setup() {
  keypadS = KeypadEmulation();
  pinMode(PB2, INPUT_PULLUP);
  delay(1000);
  Serial.begin(9600);
}
void maximum(unsigned short pos)
{
  int t = 0;
  double timeSum = 0, averages[12] = {0};
  //compute average time for all keys, the position of key defined by pos
  for (maximums[pos] = 0; maximums[pos] < 12; maximums[pos]++)
  {
    timeSum = 0;
    for (int j = 0; j < 80; j++)
    {
      
      t = keypadS.inputSimulation((unsigned short)maximums[0], (unsigned short)maximums[1],
                                  (unsigned short)maximums[2], (unsigned short)maximums[3]) ; 
                                  //Serial.println(t);   
      timeSum = timeSum + (t);
      t = 0;
    }
    averages[maximums[pos]] = (timeSum / 80.00); //average by key
    
    Serial.println(averages[maximums[pos]]);
  }
  maximums[pos] = 0;
  //Compute the key with the great average
  for (int i = 0; i < 11; i++)
  {
    if (averages[maximums[pos]] < averages[i + 1]) {
      maximums[pos] = i + 1;
    }
  }
}

// the loop routine runs over and over again forever:
void loop() {
//delay(600000);
  for (int i = 0; i < 4; i++)
  {
    maximum(i);

    Serial.println(maximums[i]);
    delay(1);
  }
keypadS.inputSimulation((unsigned short)maximums[0], (unsigned short)maximums[1],
                                  (unsigned short)maximums[2], (unsigned short)maximums[3]) ;
  //reinitialise the password to 0000
  for(int i = 0; i < 4; i++)
  {
    maximums[i] = 0;
  }
  delay(60000);

  Serial.println();
}
