// Definición de pines
const int led1 = 10;           // Pin del LED 1
const int led2 = 11;           // Pin del LED 2
const int led3 = 13;           // Pin del LED 3
const int led4 = 9;            // Pin del LED 4
const int leds[4] = {led1, led2, led3, led4}; //Pines de los leds
const int micPin = A0;         // Pin del micrófono (entrada analógica)
const int ldrPin = A2;         // Pin del LDR (fotorresistor, entrada analógica)
const int potPin = A1;         // Pin del potenciómetro (entrada analógica)
const int buttonPin = 2;       // Pin del pulsador (entrada digital)

const int Alto = LOW;          // Constante para encender los LEDs (depende del circuito)
const int Bajo = HIGH;         // Constante para apagar los LEDs (depende del circuito)

// Umbrales y variables
int ldrValue;                  // Almacena el valor del LDR
int micValue;                  // Almacena el valor del micrófono
int potValue;                  // Almacena el valor del potenciómetro
int buttonState;               // Almacena el estado del pulsador
int ldrThreshold = 800;        // Umbral para determinar si está oscuro
int micThreshold = 700;        // Umbral para detectar ruido fuerte

void setup() {
  Serial.begin(9600);          // Inicia la comunicación serial para depuración

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

  Serial.begin(9600);          // Repite la inicialización serial (esto es redundante)
}

void loop() {
  // Leer valores de sensores
  ldrValue = analogRead(ldrPin);    // Lee el valor del LDR
  micValue = analogRead(micPin);    // Lee el valor del micrófono
  potValue = analogRead(potPin);    // Lee el valor del potenciómetro
  buttonState = digitalRead(buttonPin);  // Lee el estado del pulsador

  /*
  // Código comentado para imprimir valores de los sensores en el Monitor Serial
  Serial.print("Mic Value: ");
  Serial.println(micValue);  // Utilizar Serial.println para saltar de línea
  delay(2000);
  
  Serial.print("Pot Value: ");
  Serial.println(potValue);  // Imprimir una sola vez el valor del potenciómetro
  delay(2000);
  
  Serial.print("Button State: ");
  Serial.println(buttonState);
  delay(2000);
  */

  // Verificar si está oscuro
  bool isDark = ldrValue > ldrThreshold;  // Verifica si el valor del LDR supera el umbral (oscuro)
  
  if (isDark) {
    Serial.println("Oscuro");  // Imprime "Oscuro" en el Monitor Serial

    // Encender LEDs si está oscuro
    turnOnLEDs();

    // Ejecutar secuencia creativa si el pulsador está presionado
    if (buttonState == HIGH) {
      Serial.println("Boton");  // Imprime "Boton" en el Monitor Serial
      creativeSequence();       // Llama a la función de secuencia creativa
    }
  } else {
    // Si el micrófono detecta ruido, parpadear LEDs gradualmente
    bool noise = micValue > micThreshold;  // Verifica si el valor del micrófono supera el umbral
    
    if (noise) {
      Serial.println("Ruido");  // Imprime "Ruido" en el Monitor Serial
      gradualBlink();           // Llama a la función de parpadeo gradual
    }

    // Si hay luz, apagar LEDs
    turnOffLEDs();
  }
}

// Función para encender los LEDs
void turnOnLEDs() {
  digitalWrite(led1, Alto);   // Enciende el LED 1
  digitalWrite(led2, Alto);   // Enciende el LED 2
  digitalWrite(led3, Alto);   // Enciende el LED 3
  digitalWrite(led4, Alto);   // Enciende el LED 4
}

// Función para apagar los LEDs
void turnOffLEDs() {
  digitalWrite(led1, Bajo);   // Apaga el LED 1
  digitalWrite(led2, Bajo);   // Apaga el LED 2
  digitalWrite(led3, Bajo);   // Apaga el LED 3
  digitalWrite(led4, Bajo);   // Apaga el LED 4
}

// Función para parpadear los LEDs gradualmente 4 veces
void gradualBlink() {
  int del = 10;  // Tiempo de delay fijo para el parpadeo gradual

  for (int i = 0; i < 4; i++) {  // Repite el parpadeo gradual 4 veces
    for (int brightness = 0; brightness <= 255; brightness += 5) {
      // Incrementa gradualmente el brillo de los LEDs
      analogWrite(led1, brightness);
      analogWrite(led2, brightness);
      analogWrite(led3, brightness);
      analogWrite(led4, brightness);
      delay(del);  // Espera antes de aumentar más el brillo
    }

    for (int brightness = 255; brightness >= 0; brightness -= 5) {
      // Reduce gradualmente el brillo de los LEDs
      analogWrite(led1, brightness);
      analogWrite(led2, brightness);
      analogWrite(led3, brightness);
      analogWrite(led4, brightness);
      delay(del);  // Espera antes de reducir más el brillo
    }
  }
}

// Función para generar la secuencia creativa de LEDs según el valor del potenciómetro
void creativeSequence() {
  int delayTime = potValue;  // Utiliza el valor del potenciómetro para determinar el tiempo de delay
  
  /*
  // Código comentado: Determinar la frecuencia según el valor del potenciómetro
  if (potValue < 341) {
    delayTime = 100; // Frecuencia rápida
  } else if (potValue < 682) {
    delayTime = 300; // Frecuencia media
  } else {
    delayTime = 500; // Frecuencia lenta
  }
  */

  // Ejemplo de secuencia creativa
  digitalWrite(led1, Alto);
  delay(delayTime);  // Espera según el valor del potenciómetro
  digitalWrite(led2, Alto);
  delay(delayTime);  // Espera según el valor del potenciómetro
  digitalWrite(led3, Alto);
  delay(delayTime);  // Espera según el valor del potenciómetro
  digitalWrite(led4, Alto);
  delay(delayTime);  // Espera según el valor del potenciómetro

  digitalWrite(led1, Bajo);
  digitalWrite(led3, Bajo);
  delay(delayTime);  // Espera según el valor del potenciómetro
  delay(delayTime);  // Espera según el valor del potenciómetrodigitalWrite(led1, Alto);
  delay(delayTime);  // Espera según el valor del potenciómetrodigitalWrite(led1, Alto);
  
  digitalWrite(led1, Alto);
  digitalWrite(led3, Alto);
  digitalWrite(led2, Bajo);
  digitalWrite(led4, Bajo);
  delay(delayTime);  // Espera según el valor del potenciómetrodigitalWrite(led1, Alto);
  delay(delayTime);  // Espera según el valor del potenciómetrodigitalWrite(led1, Alto);
  delay(delayTime);  // Espera según el valor del potenciómetrodigitalWrite(led1, Alto);
  
  digitalWrite(led2, Alto);
  digitalWrite(led4, Alto);
  delay(delayTime);  // Espera según el valor del potenciómetrodigitalWrite(led1, Alto);
  delay(delayTime);  // Espera según el valor del potenciómetrodigitalWrite(led1, Alto);
  delay(delayTime);  // Espera según el valor del potenciómetrodigitalWrite(led1, Alto);
  
  digitalWrite(led1, Bajo);
  delay(delayTime);  // Espera según el valor del potenciómetro
  digitalWrite(led2, Bajo);
  delay(delayTime);  // Espera según el valor del potenciómetro
  digitalWrite(led3, Bajo);
  delay(delayTime);  // Espera según el valor del potenciómetro
  digitalWrite(led4, Bajo);
  delay(delayTime);  // Espera según el valor del potenciómetro
  
}
