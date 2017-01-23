#include "KeypadEmulation.h"

KeypadEmulation keypadS;

void setup() {
  // initialize the digital pin as an output.

  keypadS = KeypadEmulation();
  pinMode(PB2, INPUT_PULLUP);
  delay(1000);
  Serial.begin(9600);

}



// the loop routine runs over and over again forever:
void loop() {
  unsigned int t = 0;
  float average = 0, averages[12] = {0};
  unsigned int maximum[4] = {0};
  for (int i = 0; i < 12; i++) 
  {
    for (int j = 0; j < 10; j++)
    {
      //delayMicroseconds(10000);
      t = keypadS.inputSimulation(i, 1, 1, 4);
      average += t;
      t = 0;
    }
    averages[i] = average / 10.0;
    if(averages[i] < averages[i + 1]){
      maximum[0] = i; 
    }
    average = 0;
  }
 
    Serial.println(maximum[0]);
 

  delay(10000);


  Serial.println();
}
