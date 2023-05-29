//code write by Moz for YouTube changel LogMaker360, 27-10-2015
//code belongs to this video: https://www.youtube.com/watch?v=6jZMJ7DFCY0

#include <SoftwareSerial.h>
SoftwareSerial BT(1, 0); 

int B1a = 6;//Back left
int B2a = 7;//Back left
int A1a = 8;//Back right
int A2b = 9;//Back right

int b1a = 10;//Front left Bk
int b2a = 11;//Front left FW
int a1a = 12;//Front right
int a1b = 13;//Front right

// creates a "virtual" serial port/UART
// connect BT module TX to 0
// connect BT module RX to 1
// connect BT Vcc to 5V, GND to GND

void setup()  
{
  // set digital pin to control as an output
  pinMode(B1a, OUTPUT);
  pinMode(B2a, OUTPUT);
  pinMode(A1a, OUTPUT);
  pinMode(A2b, OUTPUT);
  pinMode(b1a, OUTPUT);
  pinMode(b2a, OUTPUT);
  pinMode(a1a, OUTPUT);
  pinMode(a1b, OUTPUT);
  // set the data rate for the SoftwareSerial port
  BT.begin(9600);
  // Send test message to other device
  
}

void fw(){
  digitalWrite(B1a, HIGH);//Back lef  fw
  digitalWrite(B2a, LOW);//Back lef  bk
  digitalWrite(A1a, LOW);//Back r bk
  digitalWrite(A2b, HIGH);//Back r  fw
  digitalWrite(b1a, LOW);//Front L BK  
  digitalWrite(b2a, HIGH);//Front L FW
  digitalWrite(a1a, HIGH);//Front right fw 
  digitalWrite(a1b, LOW);//Front right bk

}

void left(){
  digitalWrite(B1a, LOW);//Back lef  fw
  digitalWrite(B2a, HIGH);//Back lef  bk
  digitalWrite(A1a, LOW);//Back r bk
  digitalWrite(A2b, HIGH);//Back r  fw
  digitalWrite(b1a, HIGH);//Front L BK  
  digitalWrite(b2a, LOW);//Front L FW
  digitalWrite(a1a, HIGH);//Front right fw 
  digitalWrite(a1b, LOW);//Front right bk
}


void right() {
 digitalWrite(B1a, HIGH);//Back lef  fw
  digitalWrite(B2a, LOW);//Back lef  bk
  digitalWrite(A1a, HIGH);//Back r bk
  digitalWrite(A2b, LOW);//Back r  fw
  digitalWrite(b1a, LOW);//Front L BK  
  digitalWrite(b2a, HIGH);//Front L FW
  digitalWrite(a1a, LOW);//Front right fw 
  digitalWrite(a1b, HIGH);//Front right bk
}
void back(){
 digitalWrite(B1a, LOW);//Back lef  fw
  digitalWrite(B2a, HIGH);//Back lef  bk
  digitalWrite(A1a, HIGH);//Back r bk
  digitalWrite(A2b, LOW);//Back r  fw
  digitalWrite(b1a, HIGH);//Front L BK  
  digitalWrite(b2a, LOW);//Front L FW
  digitalWrite(a1a, LOW);//Front right fw 
  digitalWrite(a1b, HIGH);//Front right bk
}
void slideRight(){
 digitalWrite(B1a, LOW);//Back lef  fw
  digitalWrite(B2a, HIGH);//Back lef  bk
  digitalWrite(A1a, LOW);//Back r bk
  digitalWrite(A2b, HIGH);//Back r  fw
  digitalWrite(b1a, LOW);//Front L BK  
  digitalWrite(b2a, HIGH);//Front L FW
  digitalWrite(a1a, LOW);//Front right fw 
  digitalWrite(a1b, HIGH);//Front right bk
}
void slideLeft(){
 digitalWrite(B1a, LOW);//Back lef  fw
  digitalWrite(B2a, HIGH);//Back lef  bk
  digitalWrite(A1a, LOW);//Back r bk
  digitalWrite(A2b, HIGH);//Back r  fw
  digitalWrite(b1a, HIGH);//Front L BK  
  digitalWrite(b2a, LOW);//Front L FW
  digitalWrite(a1a, HIGH);//Front right fw 
  digitalWrite(a1b, LOW);//Front right bk
}
void rotationCentaralAxleRight(){
 digitalWrite(B1a, LOW);//Back lef  fw
  digitalWrite(B2a, LOW);//Back lef  bk
  digitalWrite(A1a, LOW);//Back r bk
  digitalWrite(A2b, LOW);//Back r  fw
  digitalWrite(b1a, LOW);//Front L BK  
  digitalWrite(b2a, HIGH);//Front L FW
  digitalWrite(a1a, LOW);//Front right fw 
  digitalWrite(a1b, HIGH);//Front right bk
}
void stop_all(){
digitalWrite(B1a, LOW);
  digitalWrite(B2a, LOW);
  digitalWrite(A1a, LOW);
  digitalWrite(A2b, LOW);
  digitalWrite(b1a, LOW);
  digitalWrite(b2a, LOW);
  digitalWrite(a1a, LOW);
  digitalWrite(a1b, LOW);

}

char a; // stores incoming character from other device
void loop() 
{
  if (BT.available())
  {
    a=(BT.read());
    if (a=='1')
    {
      fw();
      BT.println("Moving forward");
    }
    if (a=='2')
    {
      stop_all();
      BT.println("Stop");
    }
    if (a=='3') // new command for left
    {
      left();
      BT.println("Moving left");
    }
    if (a=='4') // new command for right
    {
      right();
      BT.println("Moving right");
    }
    if (a=='5') // new command for back
    {
      back();
      BT.println("Moving backward");
    }
    if (a=='6') // new command for back
    {
      slideRight();
      BT.println("Sliding Right");
    }
    if (a=='7') // new command for back
    {
      slideLeft();
      BT.println("Sliding Left");
    }
    if (a=='8') // new command for back
    {
      rotationCentaralAxleRight();
      BT.println("Central Axe rotation to right");
    }
    if (a=='?')
    {
      BT.println("Send '1' to move forward");
      BT.println("Send '2' to stop");
      BT.println("Send '3' to turn left");
      BT.println("Send '4' to turn right");
      BT.println("Send '5' to move backward");
      BT.println("Send '6' to slide right");
      BT.println("Send '7' to slide left");
      BT.println("Send '8' to rotate right");
    }   
  }
}
