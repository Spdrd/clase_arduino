int motorPin1 = 3;
int motorPin2 = 4;

int pinPulsador = 8;

int hl[2] = {HIGH, LOW};

int velMotor = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);

  pinMode(pinPulsador, INPUT);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(pinPulsador)){
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
  }
  else{
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin1, LOW);
  }
  
  
}
