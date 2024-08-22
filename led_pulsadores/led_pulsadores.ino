int pulsador = 3;
int led = 10;
int valPul;
int del = 50;

void subir(int &intensidadActual);
void bajar(int &intensidadActual);

void setup() {
  pinMode(led, OUTPUT);
  pinMode(pulsador, INPUT);
  Serial.begin(9600);
}

void loop() {
  valPul = digitalRead(pulsador);
  Serial.println(valPul);
  //delay(1);
  
  if (valPul == HIGH) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}

void subir(int &intensidadActual){
  int i = intensidadActual;
  for(i = 0; i <= 255; i+=10){
    analogWrite(led, i);
    delay(del);
  }
}

void bajar(int &intensidadActual){
  int i = intensidadActual;
  for(i = 255; i >= 0; i-=10){
    analogWrite(led, i);
    delay(del);
  }
}