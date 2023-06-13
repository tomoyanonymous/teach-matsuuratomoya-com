const int button_pin = 2;
const int sound_pin = 9;

bool is_playing = false;
int button_prev= LOW;
float freq = 440;

float midiToFreq(int midi){
  return 440.*pow(2.,(midi-69.)/12.);
}

void setup() {
  pinMode(button_pin,INPUT);
  pinMode(sound_pin, OUTPUT);
}

void loop() {
  auto button_state = digitalRead(button_pin);

  if(button_prev == LOW && button_state==HIGH){
    is_playing = !is_playing;
    freq = midiToFreq(random(65,100));
  }
  if(is_playing){
    tone(sound_pin,freq);
  }else{
    noTone(sound_pin);
  }

  delay(20);
  button_prev = button_state;
}
