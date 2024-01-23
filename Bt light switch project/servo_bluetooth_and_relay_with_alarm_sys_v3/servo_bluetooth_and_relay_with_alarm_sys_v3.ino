#include <SoftwareSerial.h>
#include "Servo.h"

Servo servo;

#define Arduino_relay_pin 8
#define Servo_relay_pin 7

int History, angl_rotation_current,sleep_time;

String BT_msg;
String USB_msg;

SoftwareSerial BTSerial(10,11);//  RX--10 et TX--11
/////////////////////////////////////////////////////////////////////
void SERVO(String o){
  if (o=="ON"){
    digitalWrite(Servo_relay_pin,LOW);
    delay(1000);
  }
  if (o=="OFF"){
    digitalWrite(Servo_relay_pin,HIGH);
    delay(1000);
  }
}

void LIGHTS(String l){
  if (l=="ON"){
    servo.write(10);
    delay(3000);
  }
  if (l=="OFF"){
    servo.write(35);
    delay(3000);
  }
}

void ARDUINO(String a){
  if (a=="ON"){
    digitalWrite(Arduino_relay_pin,HIGH);
    delay(5000);

  }
  if (a=="OFF"){
    digitalWrite(Arduino_relay_pin,HIGH);
    delay(5000);
  }
}
//////////////////////////////////////////////////////////////////////////////



void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  servo.attach(9);
  servo.write(5);
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
        angl_rotation_current=10;
        ARDUINO("OFF");
    }
    else if (angl_rotation_current==999){
        angl_rotation_current=History;
        SERVO("ON");
    }
    else if (angl_rotation_current==998){
        angl_rotation_current=History;
        SERVO("OFF");
    }
    else if (angl_rotation_current==10){
        LIGHTS("ON");
    }
    else if (angl_rotation_current==35){
        LIGHTS("OFF");
    }
    
    /*else if (angl_rotation_current==666){
        digitalWrite(Servo_relay_pin,LOW);             code for when the app that does the counting off ms
        delay(2000);
        servo.write(35);
        delay(3000);
        digitalWrite(Arduino_relay_pin,HIGH);
        delay(5000);
    }*/
    else if (angl_rotation_current!=0 && angl_rotation_current!=10 && angl_rotation_current!=35 && angl_rotation_current!=365 && angl_rotation_current!=999 && angl_rotation_current!=998) {
      
      sleep_time=angl_rotation_current;
      delay(sleep_time);
      SERVO("ON");
      LIGHTS("OFF");
      ARDUINO("OFF");
    }
    //angl_rotation_current = BT_msg.toInt();
    //BTSerial.println(angl_rotation_current);
   // servo.write(angl_rotation_current);
    History=angl_rotation_current;
    //delay(1000);
}








