#include <SoftwareSerial.h>
#include "Servo.h"
Servo servo;

int angl_rotation;

String BT_msg;
String USB_msg;

SoftwareSerial BTSerial(10,11);//  RX--10 et TX--11
 



void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  servo.attach(9);
  BTSerial.begin(9600);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  while (BTSerial.available()){
    BT_msg = BTSerial.readString();
    BTSerial.println(BT_msg);
    }
    
    angl_rotation = BT_msg.toInt();
    servo.write(angl_rotation);
    delay(1000);

    
}