#include <SoftwareSerial.h>

String BT_msg;
String USB_msg;


int motor_right_pin1 = 2;
int motor_right_pin2 = 3;
int motor_left_pin1 = 4;
int motor_left_pin2 = 5;

int motor_right_speed=9;
int motor_left_speed=8;


SoftwareSerial BTSerial(10,11);//  RX--10 et TX--11
 



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BTSerial.begin(9600);
  
  
  pinMode(motor_right_pin1, OUTPUT);
  pinMode(motor_right_pin2, OUTPUT);
  pinMode(motor_left_pin1, OUTPUT);
  pinMode(motor_left_pin2, OUTPUT);

  pinMode(motor_right_speed, OUTPUT); 
  pinMode(motor_left_speed, OUTPUT); 

  analogWrite(motor_right_speed, 50);
  analogWrite(motor_left_speed, 50);

}

void loop() {
  // put your main code here, to run repeatedly:
  while (BTSerial.available()){
    BT_msg = BTSerial.readStringUntil('\n');
    Serial.println(BT_msg);
  
    if (BT_msg == "Forwards"){
      
      digitalWrite(motor_right_pin1, HIGH);
      digitalWrite(motor_right_pin2, LOW);
      digitalWrite(motor_left_pin1, HIGH);
      digitalWrite(motor_left_pin2, LOW);
      
      //digitalWrite(LED,HIGH);
      }
    else if (BT_msg == "Backwards"){
      digitalWrite(motor_right_pin1,LOW);  
      digitalWrite(motor_right_pin2,HIGH);
      digitalWrite(motor_left_pin1,LOW);  
      digitalWrite(motor_left_pin2,HIGH); 
    }

    else if (BT_msg =="RIGHT"){
      digitalWrite(motor_right_pin1,LOW);  
      digitalWrite(motor_right_pin2,HIGH);
      digitalWrite(motor_left_pin1,HIGH);  
      digitalWrite(motor_left_pin2,LOW); 
      
    }

    else if (BT_msg =="LEFT"){
      digitalWrite(motor_right_pin1,HIGH);  
      digitalWrite(motor_right_pin2,LOW);
      digitalWrite(motor_left_pin1,LOW);  
      digitalWrite(motor_left_pin2,HIGH);
      
    }
    else {
      digitalWrite(motor_right_pin1,LOW);  
      digitalWrite(motor_right_pin2,LOW);
      digitalWrite(motor_left_pin1,LOW);  
      digitalWrite(motor_left_pin2,LOW);
      
    }
  }
  delay(500);    

    
}
