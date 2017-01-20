#include "KeypadEmulation.h"

KeypadEmulation keypadS;

void setup() {
  // initialize the digital pin as an output.
  
  keypadS = KeypadEmulation();
  pinMode(PB2, INPUT);
  Serial.begin(9600);
  delay(1000);
}

unsigned long tps[12] = {0};
unsigned short maximum[4] = {0};

// the loop routine runs over and over again forever:
void loop() {
  for(int i = 0; i < 12; i++) 
  {
    Serial.println(i);
    tps[i] = keypadS.inputSimulation(i, 4, 4, 4);
    if(tps[maximum[0]] < tps[i]){
      maximum[0] = i;
    }
    Serial.println(tps[i]);
  }

  Serial.println("");

  delay(10000);
}
