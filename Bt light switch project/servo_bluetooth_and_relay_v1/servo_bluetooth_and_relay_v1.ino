#include <SoftwareSerial.h>
#include "Servo.h"

Servo servo;

#define Arduino_relay_pin 8
#define Servo_relay_pin 7

int History, angl_rotation_current;

String BT_msg;
String USB_msg;

SoftwareSerial BTSerial(10,11);//  RX--10 et TX--11
 



void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  servo.attach(9);
  BTSerial.begin(9600);
  pinMode(Arduino_relay_pin,OUTPUT);
  digitalWrite(Arduino_relay_pin,LOW);

  pinMode(Servo_relay_pin,OUTPUT);
  digitalWrite(Servo_relay_pin,HIGH);

  

}

void loop() {
  // put your main code here, to run repeatedly:
  while (BTSerial.available()){
    BT_msg = BTSerial.readString();
    //BTSerial.println(BT_msg);
    }
    angl_rotation_current = BT_msg.toInt();
    
    /*if (angl_rotation_current==0){
      angl_rotation_current=angl_rotation_prev;
    }
    if (angl_rotation_current!=0){
      angl_rotation_prev=angl_rotation_current;
    }*/
    if (angl_rotation_current==365){
        angl_rotation_current=0;
        digitalWrite(Arduino_relay_pin,HIGH);
        delay(5000);
    }
    else if (angl_rotation_current==999){
        angl_rotation_current=History;
        digitalWrite(Servo_relay_pin,LOW);
        delay(1000);
    }
    else if (angl_rotation_current==998){
        angl_rotation_current=History;
        digitalWrite(Servo_relay_pin,HIGH);
        delay(1000);
    }
    //angl_rotation_current = BT_msg.toInt();
    BTSerial.println(angl_rotation_current);
    servo.write(angl_rotation_current);
    History=angl_rotation_current;
    delay(1000);
}








