#include <Servo.h>

Servo m1;
void setup(){
  m1.attach(5);
  m1.write(255);
  delay(2000);
  m1.write(0);
  delay(2000);
}

void loop()
{
  m1.write(00);
  delay(3000);

  m1.write(10);
  delay(3000);

  m1.write(20);
  delay(2000);

  m1.write(30);
  delay(2000);

  m1.write(40);
  delay(2000);
  
  m1.write(50);
  delay(2000);

  m1.write(60);
  delay(2000);

  m1.write(70);
  delay(2000);

  m1.write(80);
  delay(2000);

  m1.write(90);
  delay(2000);

  m1.write(100);
  delay(2000);

  m1.write(110);
  delay(2000);

  m1.write(120);
  delay(2000);

  m1.write(130);
  delay(2000);

  m1.write(140);
  delay(2000);

  m1.write(150);
  delay(2000);

  m1.write(160);
  delay(2000);

  m1.write(170);
  delay(2000);

  m1.write(180);
  delay(2000);

  m1.write(190);
  delay(2000);

  m1.write(200);
  delay(2000);

  m1.write(210);
  delay(2000);

  m1.write(220);
  delay(2000);

  m1.write(230);
  delay(2000);

  m1.write(240);
  delay(2000);

  m1.write(255);
  delay(4000);

  //BLDC Speed reduces

  m1.write(125);
  delay(2000);

  m1.write(55);
  delay(2000);

  m1.write(10);
  delay(2000);

  m1.write(00);
  delay(1000);
}
