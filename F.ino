#include <Servo.h>
#include <stdint.h>
Servo up;
Servo down;
//Servo Init
#define cl(x) delay(x)
#define ptln(x) Serial.println(x)
#define pt(x) Serial.print(x)
#define inR analogRead(A12)
#define inB analogRead(A0)
//RGB input port

void setup() {
up.attach(A1);
down.attach(A5);
Serial.begin(9600);
input_Init();
}


void loop() {
  delay(150);
    if (inB>900)
  {sc(180,160);}//Adobe模式角度
  if (inB<300)
  {sc(90,70);}//标准模式角度
  if (inB>300 && inB<900 )
  {sc(130,40);}//游戏模式角度
  
ptln(inB);
}


void sc(int16_t sup,int16_t sdown)
{
  up.write(sup);
  down.write(sdown);
}
//dual Servo control
  

 void input_Init(void)
 {
  for(int i=0;i<2;i++)
  {
    pinMode(A12+i,INPUT);
    }
  }
  //RGB input init
