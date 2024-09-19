int sensorTemp = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensorTemp, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int tempRaw = analogRead(sensorTemp);
  int temp = (tempRaw*5.0/1024)/0.01;
  Serial.println(temp);
  delay(500);
}
