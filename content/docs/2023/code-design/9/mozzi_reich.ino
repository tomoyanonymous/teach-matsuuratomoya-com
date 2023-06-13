#include <MozziGuts.h>
#include <mozzi_midi.h>
#include <Oscil.h>
#include <EventDelay.h>
#include <ADSR.h>
#include <tables/sin8192_int8.h>

Oscil <8192, AUDIO_RATE> aOscil(SIN8192_DATA);//元となる音色
Oscil <8192, AUDIO_RATE> aOscil2(SIN8192_DATA);//元となる音色
ADSR <AUDIO_RATE, AUDIO_RATE> envelope_A;//エンベロープをかけるためのクラス
ADSR <AUDIO_RATE, AUDIO_RATE> envelope_B;//エンベロープをかけるためのクラス
unsigned int Dur, Atk, Dec, Sus, Rel;//ADSRの長さを入れておく変数

//piano phaseのパターン
unsigned int pattern[] = {64, 66, 71, 73, 74, 66, 64, 73, 71, 66, 74, 73};

//二つのタイマーを用意
int phase_A = 0;
int phase_B = 0;
EventDelay timer_B;
EventDelay timer_A;

void setup() {
  startMozzi(1024);
  Atk = 10;
  Dec = 10;
  Sus = 50;
  Rel = 100;
  envelope_A.setTimes(Atk, Dec, Sus, Rel);
  envelope_A.setADLevels(255, 128);
  envelope_B.setTimes(Atk, Dec, Sus, Rel);
  envelope_B.setADLevels(255, 128);

  timer_A.set(150);
  timer_B.set(151);
  timer_B.start();
  timer_A.start();
}

void updateControl()
{  
  if (timer_A.ready())
  {
    int note = pattern[phase_A];
    phase_A = (phase_A + 1) % 12;
    aOscil.setFreq(mtof(note));
    envelope_A.noteOn();
    timer_A.start();
  }

  if (timer_B.ready())
  {
    int note = pattern[phase_B];
    phase_B = (phase_B + 1) % 12;
    aOscil2.setFreq(mtof(note));
    envelope_B.noteOn();
    timer_B.start();
  }
}

int updateAudio()
{
  envelope_A.update();
  envelope_B.update();
  int A = (envelope_A.next() * aOscil.next()) >> 8;
  int B = (envelope_B.next() * aOscil2.next()) >> 8;

  return (A + B) / 2;
}

void loop() {
  audioHook();
}