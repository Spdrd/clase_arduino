int led = 13; // Nombre del led 
int pulsador = 12;
int valPul;
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT); // Configura el pin digital como salida 
  pinMode(pulsador,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  valPul = digitalRead(pulsador);
  Serial.println(valPul);
  if ( valPul == HIGH){
    digitalWrite(led, HIGH);
  }else{
    digitalWrite(led, LOW);
  }
  
}
