// Definición de pines
const int led1 = 10;
const int led2 = 11;
const int led3 = 13;
const int led4 = 9;
const int micPin = A0;         // Pin del micrófono
const int ldrPin = A2;         // Pin del LDR
const int potPin = A1;         // Pin del potenciómetro
const int buttonPin = 2;       // Pin del pulsador

// Umbrales y variables
int ldrValue;
int micValue;
int potValue;
int buttonState;
int ldrThreshold = 800;        // Umbral para determinar si está oscuro
int micThreshold = 700;        // Umbral para detectar ruido fuerte

void setup() {
  Serial.begin(9600);
  // Configuración de pines de salida
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  // Configuración de pines de entrada
  pinMode(ldrPin, INPUT);
  pinMode(micPin, INPUT);
  pinMode(potPin, INPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // Leer valores de sensores
  ldrValue = analogRead(ldrPin);
  Serial.print("foto: ");
  Serial.println(ldrValue);
  micValue = analogRead(micPin);
  Serial.print("micro: ");
  Serial.println(micValue);
  potValue = analogRead(potPin);
  buttonState = digitalRead(buttonPin);
  if(buttonState){
    Serial.println("Boton");
  }
  else{
    Serial.println("NoBoton");
  }
  
  // Condición 1: Encender LEDs si está oscuro
  if (ldrValue < ldrThreshold) {
    turnOnLEDs(); 
  }
  // Condición 3: Secuencia creativa si el pulsador está presionado
  else if (buttonState == HIGH) {
    creativeSequence();
  }
  else if (micValue > micThreshold) {
    gradualBlink();
  }

  // Condición 2: Detectar ruido si hay luz y LEDs están apagados
  else {
    turnOffLEDs();
  }
}

// Función para encender los LEDs
void turnOnLEDs() {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
}

// Función para apagar los LEDs
void turnOffLEDs() {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
}

// Función para parpadear los LEDs gradualmente 4 veces
void gradualBlink() {
  for (int i = 0; i < 4; i++) {
    for (int brightness = 0; brightness <= 255; brightness += 5) {
      analogWrite(led1, brightness);
      analogWrite(led2, brightness);
      analogWrite(led3, brightness);
      analogWrite(led4, brightness);
      delay(10);
    }
    for (int brightness = 255; brightness >= 0; brightness -= 5) {
      analogWrite(led1, brightness);
      analogWrite(led2, brightness);
      analogWrite(led3, brightness);
      analogWrite(led4, brightness);
      delay(10);
    }
  }
}

// Función para generar la secuencia creativa de LEDs según el valor del potenciómetro
void creativeSequence() {
  int delayTime;

  // Determinar la frecuencia según el valor del potenciómetro
  /*
  if (potValue < 341) {
    delayTime = 100; // Frecuencia rápida
  } else if (potValue < 682) {
    delayTime = 300; // Frecuencia media
  } else {
    delayTime = 500; // Frecuencia lenta
  }
  */
  delayTime = potValue;

  // Ejemplo de secuencia 
  digitalWrite(led1, HIGH);
  delay(delayTime);
  digitalWrite(led2, HIGH);
  delay(delayTime);
  digitalWrite(led3, HIGH);
  delay(delayTime);
  digitalWrite(led4, HIGH);
  delay(delayTime);
  
  digitalWrite(led1, LOW);
  delay(delayTime);
  digitalWrite(led2, LOW);
  delay(delayTime);
  digitalWrite(led3, LOW);
  delay(delayTime);
  digitalWrite(led4, LOW);
  delay(delayTime);
}
