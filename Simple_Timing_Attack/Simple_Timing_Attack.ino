#include "KeypadSimulation.h"

KeypadSimulation keypadS;

void setup() {
  // initialize the digital pin as an output.
  keypadS = KeypadSimulation();
  pinMode(PB2, INPUT);
  Serial.begin(9600);
}

int i = 0;
unsigned long tps[5] = {0, 0, 0, 0, 0};

// the loop routine runs over and over again forever:
void loop() {
  tps[0] = keypadS.inputSimulation(2, 3, 4, 5);
  delay(1000);
  tps[1] = keypadS.inputSimulation(1, 5, 4, 5);
  delay(1000);
  tps[2] = keypadS.inputSimulation(1, 3, 4, 5);
  delay(1000);
  tps[3] = keypadS.inputSimulation(1, 3, 1, 4);
  delay(1000);
  tps[4] = keypadS.inputSimulation(1, 3, 1, 5);
  
  for(int i = 0; i < 5; i++) Serial.println(tps[i]);
  Serial.println("");
  delay(1000);
}
