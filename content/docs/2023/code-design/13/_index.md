---
title: 第13週
date: 2023-06-23
weight: 13
---

# 2023年　東京藝術大学 芸術情報センター開設科目　「コードとデザイン」 第13回

## スライド

(スライド行方不明・・・多分この日はスライドなかったと思います)

## 銅箔テープで作る平面コイルのSVGを出力するProcessingスケッチ



```java
import processing.svg.*;

void setup(){
  noLoop();
  size(800,800);
  stroke(0);
  background(255);
  beginRecord(SVG, "spiral.svg");

}

float diameter = 800;


void draw(){
  float angle = 0;
  float r  = 1;
  float r_step =0.4;
  float angle_step = 0.1;
  translate(width/2,height/2);
  float x_tmp = 0;
  float y_tmp = 0;
  while(r < width/2-10){
    r += r_step;
    angle += angle_step;
    float x = r*sin(angle);
    float y = r*cos(angle);
    line(x_tmp,y_tmp,x,y);
    x_tmp = x;
    y_tmp = y;
  }
    r+=9;
    while(r > 0){
    r -= r_step;
    angle -= angle_step;
    float x = r*sin(angle);
    float y = r*cos(angle);
    line(x_tmp,y_tmp,x,y);
    x_tmp = x;
    y_tmp = y;
  }
endRecord();
}
```