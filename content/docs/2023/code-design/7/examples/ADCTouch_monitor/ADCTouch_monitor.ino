#include <ADCTouch.h>

void setup() {
  pinMode(A0, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int val = ADCTouch.read(A0, 100);
  Serial.println(val);
  delay(40);
}
