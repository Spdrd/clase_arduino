int microfono = 1;
int fotoresist = 0;
int led = 13;

int tolerancia_ruido = 650;
int tolerancia_luz = 600;

int del = 1000;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int lectura_ruido = analogRead(microfono);
  int lectura_luz = analogRead(fotoresist);

  Serial.println(lectura_ruido);
  Serial.println(lectura_luz);
  Serial.println();

  bool retorno_luz = lectura_luz > tolerancia_luz;
  bool retorno_ruido = lectura_ruido > tolerancia_ruido;

  if(retorno_luz){
    digitalWrite(13, LOW);
  } else{
    digitalWrite(13, HIGH);
  }

  delay(del);
}


void subir(int &intensidadActual){
  int i = intensidadActual;
  for(i = 0; i <= 255; i+=10){
    analogWrite(led, i);
  }
}

void bajar(int &intensidadActual){
  int i = intensidadActual;
  for(i = 255; i >= 0; i-=10){
    analogWrite(led, i);
  }
}
