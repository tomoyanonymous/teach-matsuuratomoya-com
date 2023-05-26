
#include <ADCTouch.h>
//setup()とloop()で共通して使う値はグローバル変数(関数の外側)で定義しておく
int ref = 0;

void setup() {
  pinMode(A0, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  //繋げた導体の状態で初期値が変わるので、それを保存しておく必要がある
  ref = ADCTouch.read(A0, 100);  //(使用するピン番号,平均を取るサンプル数)
}

void loop() {

  int val = ADCTouch.read(A0, 100) - ref;
  if (val > 40) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }

  Serial.println(val);

  delay(40);
}
