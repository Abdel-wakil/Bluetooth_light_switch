
int capteur_IR_DROIT=12;
int capteur_IR_GAUCHE=11;

int detection_DROITE;
int detection_GAUCHE;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(capteur_IR_DROIT,INPUT);
  pinMode(capteur_IR_GAUCHE,INPUT);
  

}

void loop() {
  mode_automatique();
  delay(20);
  


}












void mode_automatique(){
  
  detection_DROITE=digitalRead(capteur_IR_DROIT);
  detection_GAUCHE=digitalRead(capteur_IR_GAUCHE);

  if (detection_DROITE==0 && detection_GAUCHE==0){
    forword();
  }
  else if (detection_DROITE==1){
    turnRight_small();
  }
  else if (detection_GAUCHE==1){
    turnLeft_small(); 
  }
  else if (detection_DROITE==1 && detection_GAUCHE==1){
    Stop();
  }
}
