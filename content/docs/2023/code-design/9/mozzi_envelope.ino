#include <MozziGuts.h>
#include <mozzi_midi.h>
#include <Oscil.h>

#include <ADSR.h>
#include <tables/sin8192_int8.h>

Oscil<8192, AUDIO_RATE> aOscil(SIN8192_DATA);  //元となる音色
ADSR<AUDIO_RATE, AUDIO_RATE> envelope;         //エンベロープをかけるためのクラス

unsigned int Dur, Atk, Dec, Sus, Rel;  //ADSRの長さを入れておく変数
int button_prev = LOW;

void setup() {
  startMozzi(1024);
  Atk = 10;
  Dec = 10;
  Sus = 50;
  Rel = 100;
  envelope.setTimes(Atk, Dec, Sus, Rel);
  envelope.setADLevels(255, 128);
}

void updateControl() {
  auto button_state = digitalRead(2);
  if (button_prev == LOW && button_state == HIGH) {
    auto f = mtof((int)random(65, 100));
    aOscil.setFreq(f);
    envelope.noteOn();
  }
  if (button_prev == HIGH && button_state == LOW) {
    envelope.noteOff();
  }
  button_prev = button_state;
}

int updateAudio() {
  envelope.update();
  return envelope.next() * aOscil.next() / 255;
}

void loop() {
  audioHook();
}