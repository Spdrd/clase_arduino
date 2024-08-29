int sensorPin = 0;
int led = 13;
int del = 50;
int tolerancia_luz = 400;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int lectura = analogRead(sensorPin);
  Serial.println(lectura);
  bool encender = true;
  encender = (lectura > tolerancia_luz);
  if(encender){
    digitalWrite(led, LOW);
  } else{
    digitalWrite(led, HIGH);

  } 
  delay(del);
}
