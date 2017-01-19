#include "KeypadEmulation.h"

KeypadEmulation keypadS;

void setup() {
  // initialize the digital pin as an output.
  keypadS = KeypadEmulation();
  pinMode(PB2, INPUT);
  Serial.begin(9600);
}

int i = 0;
unsigned long tps[12] = {0};

// the loop routine runs over and over again forever:
void loop() {
  for(int i = 0; i < 12; i++) 
  {
    Serial.println(i);
    tps[i] = keypadS.inputSimulation(i, 3, 4, 5);
    delay(1000);
    Serial.println(tps[i]);
  }
  
  Serial.println("");
  delay(1000);
}
