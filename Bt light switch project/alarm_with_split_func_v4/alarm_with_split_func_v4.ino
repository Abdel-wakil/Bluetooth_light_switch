#include <SoftwareSerial.h>
#include "Servo.h"
#define Arduino_relay_pin 8
#define Servo_relay_pin 7

Servo servo;


int History, angl_rotation_current;
unsigned long sleep_time;

String BT_msg,USB_msg,code_for_alarm,duration_befo_off;


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

void ARDUiNO(String a){
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
  BTSerial.begin(9600);

  servo.attach(9);
  servo.write(5);

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
    code_for_alarm = BT_msg.substring(0,1);
    duration_befo_off = BT_msg.substring(1);


    //angl_rotation_current = BT_msg.toInt();
    
    if (code_for_alarm=="a"){
        ARDUiNO("OFF");
    }
    else if (code_for_alarm=="b"){
        SERVO("ON");
    }
    else if (code_for_alarm=="c"){
        angl_rotation_current=History;
        SERVO("OFF");
    }
    else if (code_for_alarm=="d"){
        LIGHTS("ON");
    }
    else if (code_for_alarm=="e"){
        LIGHTS("OFF");
    }
    else if (code_for_alarm=="*") {
      
      sleep_time = duration_befo_off.toInt();
      delay(sleep_time);
      SERVO("ON");
      LIGHTS("OFF");
      ARDUiNO("OFF");
    }
  delay(500);
}