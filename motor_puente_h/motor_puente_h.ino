int motorPin1 = 3;
int motorPin2 = 4;
int velMotor = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, HIGH);
  
}
