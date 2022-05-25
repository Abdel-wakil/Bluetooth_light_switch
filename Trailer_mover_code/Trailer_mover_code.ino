#include <SoftwareSerial.h>
SoftwareSerial BT(2, 3); // RX, TX

#define enA 10
#define in1 4
#define in2 5

#define in3 6
#define in4 7
#define enB 9

int xAxis=140, yAxis=140;

String BT_msg;

int motorSpeedA = 80;
int motorSpeedB = 80;



void setup() {
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
  BT.begin(9600); // Default communication rate of the Bluetooth module
  analogWrite(enA, motorSpeedA);
  analogWrite(enB, motorSpeedB);

  

  
  delay(500);
}

void loop() {
  //xAxis = 140;
  //yAxis = 140;

  while (BT.available() >= 2) {
    xAxis = BT.read();
    delay(10);
    yAxis = BT.read();
   Serial.print(xAxis);
   Serial.print(",");
   Serial.println(yAxis);
  }
  delay(10);
  
  // Makes sure we receive corrent values

if (xAxis > 130 && xAxis <150 && yAxis > 130 && yAxis <150){Stop();}  //    130<x<150 ### stops ###


if (yAxis > 130 && yAxis <150){  // check if in x axis  
  
    if (xAxis < 130){turnLeft();
    }
    
    if (xAxis > 150) {turnRight();
    }
  
  }
else{

  if (xAxis > 130 && xAxis <150){    // check if in y axis  
  
    if (yAxis < 130){forword();}
    if (yAxis > 150){backword();}
    
   
  }
  else{
  
    if (yAxis < 130){forword();}
    if (yAxis > 150){backword();}
  } 
 }
           //  Small turns //
           
  if (xAxis > 200 && yAxis < 80){
    turnRight_small();
  }
  else if (xAxis < 80 && yAxis < 80){
    turnLeft_small(); 
  }
  else if (xAxis > 200 && yAxis > 190){
    backRight_small();
  }
  else if (xAxis < 80 && yAxis > 190){
    backLeft_small();
  }

  
 //#########################################// 
}


void forword(){/*Serial.println("forword")*/;
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW); 
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
}

void backword(){/*Serial.println("backword")*/;
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH); 
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
}

void turnRight(){/*Serial.println("turnRight")*/;
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH); 
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
}

void turnLeft(){/*Serial.println("turnLeft")*/;
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW); 
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);

}

void Stop(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW); 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  Serial.println("stop");
}
void turnLeft_small(){
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW); 
digitalWrite(in3, LOW);
digitalWrite(in4, LOW); 
}
void turnRight_small(){
digitalWrite(in1, LOW);
digitalWrite(in2, LOW); 
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW); 
}
void backLeft_small(){
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH); 
digitalWrite(in3, LOW);
digitalWrite(in4, LOW); 
}
void backRight_small(){
digitalWrite(in1, LOW);
digitalWrite(in2, LOW); 
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH); 
}
