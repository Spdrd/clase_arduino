int motorPin1 = 3;
int motorPin2 = 4;

int velMotor = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  Serial.begin(9600);
  while (!Serial) {
    Serial.println("Funcionant :V");
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    velMotor = Serial.parseInt();
    if(velMotor >= 0 && velMotor <= 255){
      analogWrite(motorPin1, velMotor);
      Serial.print("Velocidad: ");
      Serial.println(velMotor);
      delay(10000);
    }
    
  }
  
}
