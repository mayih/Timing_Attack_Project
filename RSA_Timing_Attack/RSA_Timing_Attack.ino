#define PB2 5

void setup() {
  // initialize the digital pin as an output.
  pinMode(PB2, INPUT_PULLUP);
  delay(1000);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
//delay(600000);
unsigned int tps = 0, start = 0;
    
     tps = pulseIn(PB2, HIGH);
     
Serial.println(tps);
  Serial.println();
}
