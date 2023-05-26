// Arduino Leonardo,Arduino Micro,Sparkfun Pro Microなど、ATMega32u4チップのものを使うこと

#include <Mouse.h>
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

int range = 10;

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
void moveMouse(int x, int y, int mouse_state) {
  Mouse.move(x, y, 0);
  if (mouse_state == 1) {
     if (!Mouse.isPressed(MOUSE_LEFT)) {
         Mouse.press(MOUSE_LEFT);
     }
  }
  else {
     if (Mouse.isPressed(MOUSE_LEFT)) {
         Mouse.release(MOUSE_LEFT);
     }
  }
}

void loop() {

  int v1 = ADCTouch.read(upButton, 100) - ref_up;
  int v2 = ADCTouch.read(downButton, 100) - ref_down;
  int v3 = ADCTouch.read(leftButton, 100) - ref_left;
  int v4 = ADCTouch.read(rightButton, 100) - ref_right;
  int v5 = ADCTouch.read(mouseButton, 100) - ref_mouse;
  int upState = v1 > 40 ? 1 : 0;
  int downState = v2 > 40 ? 1 : 0;
  int rightState = v3 > 40 ? 1 : 0;
  int leftState = v4 > 40 ? 1 : 0;
  int clickState = v5 > 40 ? 1 : 0;

  int xDistance = (leftState - rightState) * range;
  int yDistance = (upState - downState) * range;


  if (!(xDistance == 0 && yDistance == 0 && clickState == 0)) {
    moveMouse(xDistance, yDistance, clickState);
  }

  delay(5);
}