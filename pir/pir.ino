int pir = 2;
int led = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(pir, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int pirVal = digitalRead(pir);
  if(pirVal == HIGH){
    digitalWrite(led, LOW);
    Serial.println("Sapo detectado");
  }
  else{
    digitalWrite(led, HIGH);
    Serial.println("Esperando Sapo");
  }
}
