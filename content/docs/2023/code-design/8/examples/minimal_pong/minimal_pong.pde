class Ball {
  float x;
  float y;
  float vel_x;
  float vel_y;
  Ball() {
    this.x = width/2;
    this.y = height/2;
    this.vel_x = random(0, 1.0) > 0.5 ? -3 : 3;
    this.vel_y = random(0, 1.0) > 0.5 ? -3 : 3;
  }
  public void update_pos() {
    this.x +=  this.vel_x;
    this.y +=  this.vel_y;
    if (this.x <0 || this.x > width) {
      this.reflect_horizontal();
    }
    if (this.y < 0 ) {
      this.reflect_vertical();
    }
  }
  void reflect_horizontal() {
    this.vel_x = -this.vel_x*1.1;
  }
  public void reflect_vertical() {
    this.vel_y = -this.vel_y*1.1;
  }
}
final float bar_width = 100;
final float bar_y = 550;
float bar_pos = 0.;
boolean gameover = false;
Ball ball = new Ball();

void setup() {
  size(600, 600);
  textMode(CENTER);
  rectMode(CENTER);
}

void draw() {
  ball.update_pos();
  if (ball.y>height) {
    gameover = true;
  }
  if (gameover) {
    textSize(24);
    text("game over", width/2, height/2);
  } else {
    bar_pos = mouseX;
    if (ball.y > bar_y && 
        ball.x > bar_pos - bar_width/2 && 
        ball.x < bar_pos + bar_width/2) {
      ball.reflect_vertical();
    }
    background(255);
    fill(0);
    rect(bar_pos, bar_y, bar_width, 30);
    ellipse(ball.x, ball.y, 10, 10);
  }
}

void mousePressed() {
  if (gameover) {
    gameover  =false;
    ball = new Ball();
  }
}
