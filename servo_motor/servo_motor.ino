#include <Servo.h>

Servo servo;
int motorPin = 11;
int angulo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(motorPin);
  while (!Serial) {
    Serial.println("Servo Motor");
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  for(angulo = 0; angulo < 180; angulo++){
    servo.write(angulo);
    Serial.print("Angulo: ");
    Serial.println(angulo);
    
  }
  /*
  for(; angulo > 0 ; angulo--){
    servo.write(angulo);
    Serial.print("Angulo: ");
    Serial.println(angulo);
    delay(20);
  }
  */
}
