const int button_pin = 2;
const int sound_pin = 9;

void setup() {
  pinMode(button_pin, INPUT);
  //tone()を使うときは3,11以外
  pinMode(sound_pin, OUTPUT);
}

void loop() {
  if (digitalRead(2) == HIGH) {
    tone(sound_pin, 1000);
  } else {
    noTone(sound_pin);
  }
  delay(20);
}
