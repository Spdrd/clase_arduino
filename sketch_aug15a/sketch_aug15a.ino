int led = 13; // Nombre del led 

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT); // Configura el pin digital como salida 
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(1000);
}
