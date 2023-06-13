---
title: Week 7
date: 2023-05-26
weight: 7
---

# 2023 Tokyo University of the Arts Art media Center「Code and Design」

## Slides (in Japanese)

{{< button href="2023-code-and-design-7.pdf">}}Slides（PDF）{{< /button >}}

{{< button href="./slides">}}Slides（HTML）{{< /button >}}


## Python Scripts for Mouse Automation

https://github.com/tomoyanonymous/py-serial-automouse

{{< button href="https://github.com/tomoyanonymous/py-serial-automouse/archive/refs/heads/main.zip">}} DL Zip {{< /button >}}

## Arduino Example Codes

### ADCTouch_monitor.ino

{{< button href="./ADCTouch_monitor/ADCTouch_monitor.ino">}}DL{{< /button >}}

```cpp
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
```

### ADCTouch_minimal.ino

{{< button href="./ADCTouch_minimal/ADCTouch_minimal.ino">}}DL{{< /button >}}

```cpp
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
```

### ADCTouch_Mouse

{{< button href="./ADCTouch_Mouse/ADCTouch_Mouse.ino">}}DL{{< /button >}}

```cpp
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
  int xDistance = (leftState - rightState) * range;
  int yDistance = (upState - downState) * range;

  //移動もクリックもしてないならシリアル送信は冗長なので、しない
  // &&　は　AND、!はNOT
  if (!(xDistance == 0 && yDistance == 0 && clickState == 0)) {
    moveMouse(xDistance, yDistance, clickState);
  }
  delay(5);
}
```

### DrunkMouse(Add Randomness)

{{< button href="./DrunkMouse/DrunkMouse.ino">}}DL{{< /button >}}

### ADCTouch_Mouse_HID.ino (Only works for Leonardo and Pro Micro)

{{< button href="./ADCTouch_Mouse_HID/ADCTouch_Mouse_HID.ino">}}DL{{< /button >}}

### ADCTouch_Mouse_scroll.ino(works only with `move_relative_scroll.command`)

{{< button href="./ADCTouch_Mouse_scroll/ADCTouch_Mouse_scroll.ino">}}DL{{< /button >}}