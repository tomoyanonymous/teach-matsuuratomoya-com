#include <ADCTouch.h>

const int upButton = A0;
const int downButton = A1;
const int leftButton = A2;
const int rightButton = A3;
const int mouseButton = A4;
int ref_up = 0;
int ref_down = 0;
int ref_left = 0;
int ref_right = 0;
int ref_mouse = 0;

int range = 10;         // マウスカーソルの移動幅

void setup() {
  randomSeed(analogRead(A5));
  
  pinMode(upButton, INPUT);
  pinMode(downButton, INPUT);
  pinMode(leftButton, INPUT);
  pinMode(rightButton, INPUT);
  pinMode(mouseButton, INPUT);

  ref_up = ADCTouch.read(upButton, 100);
  ref_down = ADCTouch.read(downButton, 100);
  ref_left = ADCTouch.read(leftButton, 100);
  ref_right = ADCTouch.read(rightButton, 100);
  ref_mouse = ADCTouch.read(mouseButton, 100);
  
  Serial.begin(9600);
}

//マウス移動に関する処理をひとまとめに
void moveMouse(int x, int y, int mouse_state) {
  Serial.print(x);
  Serial.print(" ");
  Serial.print(y);
  Serial.print(" ");
  Serial.println(mouse_state);
}

void loop() {
  // ボタンの検出
  int v1 = ADCTouch.read(upButton, 100) - ref_up;
  int v2 = ADCTouch.read(downButton, 100) - ref_down;
  int v3 = ADCTouch.read(leftButton, 100) - ref_left;
  int v4 = ADCTouch.read(rightButton, 100) - ref_right;
  int v5 = ADCTouch.read(mouseButton, 100) - ref_mouse;
  //40以上ならクリックしたとみなし、1を、40以下なら0を
  // A ? B : C;はif (A) { return B;} else {return C;} の略記(三項演算子)
  int upState = v1 > 40 ? 1 : 0;
  int downState = v2 > 40 ? 1 : 0;
  int rightState = v3 > 40 ? 1 : 0;
  int leftState = v4 > 40 ? 1 : 0;
  int clickState = v5 > 40 ? 1 : 0;
  // 移動距離を算出（左右同時押しも考慮）
  int xDistance = (leftState - rightState) * range + random(-10,10);
  int yDistance = (upState - downState) * range + random(-10,10);

  //移動もクリックもしてないならシリアル送信は冗長なので、しない
  // &&　は　AND、!はNOT
  if (!(xDistance == 0 && yDistance == 0 && clickState == 0)) {
    moveMouse(xDistance, yDistance, clickState);
  }

  delay(5);
}
