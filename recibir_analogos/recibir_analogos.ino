//declaracion de variables

int sensorPin=0; //Conecta el sensor al pin analogo


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  //las señales analogas 
}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = analogRead(sensorPin);
  Serial.println(reading);
  delay(30);
}
