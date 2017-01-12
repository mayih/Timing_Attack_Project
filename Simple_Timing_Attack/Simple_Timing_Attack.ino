#include "KeypadSimulation.h"

int tps_1 = 0;
int tps_2 = 0;
int l = 0;
#define PB2 9


void setup() {
  // initialize the digital pin as an output.
  keyPadInit();
delay(1000);
  pinMode(PB2, INPUT);
  Serial.begin(9600);
}
int i = 0;
int input = 0;
// the loop routine runs over and over again forever:
void loop() {
  //delay(1000);
     inputSimulation(1);
     delay(500);
      inputSimulation(2);
    delay(500);
     

  //

  /* tps_1 = micros();
    while(digitalRead(PB2) == HIGH)
    {

     tps_2 = micros();
    }
    Serial.println(tps_2 - tps_1);
    while(digitalRead(PB2) != HIGH)
    {
     inputSimulation(input);
    }*/

  //exit(0);
}
