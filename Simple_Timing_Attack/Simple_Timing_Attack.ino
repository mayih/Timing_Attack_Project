#include "KeypadSimulation.h"

int tps_1 = 0;
int tps_2 = 0;
KeypadSimulation keypadS;
#define PB2 9


void setup() {
  // initialize the digital pin as an output.
  keypadS = KeypadSimulation();
  delay(1000);
  pinMode(PB2, INPUT);
  Serial.begin(9600);
}
int i = 0;
int input = 0;
// the loop routine runs over and over again forever:
void loop() {
  tps_1 = micros();
  keypadS.inputSimulation(2);
  delay(13);
  keypadS.inputSimulation(6);
  delay(13);
  keypadS.inputSimulation(8);
  delay(13);
  keypadS.inputSimulation(11);
  while (digitalRead(PB2) == HIGH);
  tps_2 = micros();

  Serial.println("xxxx");
  Serial.println(tps_2 - tps_1 - keypadS.getInputTime());
  tps_1 = 0;
  tps_2 = 0;
  delay(2000);
  tps_1 = micros();
  keypadS.inputSimulation(1);
  delay(13);
  keypadS.inputSimulation(6);
  delay(13);
  keypadS.inputSimulation(8);
  delay(13);
  keypadS.inputSimulation(11);
  while (digitalRead(PB2) == HIGH);
  tps_2 = micros();

  Serial.println("1xxx");
  Serial.println(tps_2 - tps_1 - keypadS.getInputTime());
tps_1 = 0;
  tps_2 = 0;
  delay(2000);

  tps_1 = micros();


  keypadS.inputSimulation(1);
  delay(13);
  keypadS.inputSimulation(3);
  delay(13);
  keypadS.inputSimulation(4);
  delay(13);
  keypadS.inputSimulation(6);
  while (digitalRead(PB2) == HIGH);

  tps_2 = micros();
  Serial.println("13xx");
  Serial.println(tps_2 - tps_1 - keypadS.getInputTime());
tps_1 = 0;
  tps_2 = 0;
  delay(2000);
  tps_1 = micros();


  keypadS.inputSimulation(1);
  delay(13);
  keypadS.inputSimulation(3);
  delay(13);
  keypadS.inputSimulation(1);
  delay(13);
  keypadS.inputSimulation(6);
  while (digitalRead(PB2) == HIGH);

  tps_2 = micros();
  Serial.println("131x");
  Serial.println(tps_2 - tps_1 - keypadS.getInputTime());
tps_1 = 0;
  tps_2 = 0;
  delay(2000);
  tps_1 = micros();


  keypadS.inputSimulation(1);
  delay(13);
  keypadS.inputSimulation(3);
  delay(13);
  keypadS.inputSimulation(1);
  delay(13);
  keypadS.inputSimulation(5);
  while (digitalRead(PB2) == HIGH);

  tps_2 = micros();

  Serial.println("1315");
  Serial.println(tps_2 - tps_1 - keypadS.getInputTime());
tps_1 = 0;
  tps_2 = 0;
  delay(60000);
  //exit(0);
}
