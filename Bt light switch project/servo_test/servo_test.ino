#include "Servo.h"

Servo servo; // création de l'objet "servo"

void setup() {
   servo.attach(9);
   servo.write(200);
    // attache le servo au pin spécifié
}

void loop() {
   /*servo.write(0); // demande au servo de se déplacer à cette position
   delay(2000); // attend 1000 ms entre changement de position

   servo.write(45); // demande au servo de se déplacer à cette position
   delay(2000); // attend 1000 ms entre changement de position

   servo.write(90); // demande au servo de se déplacer à cette position
   delay(2000);

   servo.write(135); // demande au servo de se déplacer à cette position
   delay(2000);

   servo.write(180); // demande au servo de se déplacer à cette position
   delay(2000);

   servo.write(180+45); // demande au servo de se déplacer à cette position
   delay(2000);*/ // attend 1000 ms entre changement de position
}