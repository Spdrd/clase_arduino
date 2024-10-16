#include <Servo.h>

#define  a3f    208     // 208 Hz
#define  b3f    233     // 233 Hz
#define  b3     247     // 247 Hz
#define  c4     261     // 261 Hz // MIDDLE C
#define  c4s    277     // 277 Hz
#define  e4f    311     // 311 Hz   
#define  e4     330
#define  f4     349     // 349 Hz 
#define  g4s    392
#define  a4f    415     // 415 Hz 
#define  a4     432
#define  b4f    466     // 466 Hz 
#define  b4     493     // 493 Hz 
#define  c5     523     // 523 Hz 
#define  c5s    554     // 554 Hz
#define  e5f    622     // 622 Hz  
#define  f5     698     // 698 Hz 
#define  f5s    740     // 740 Hz
#define  a5f    831     // 831 Hz

int numeros_sieteSeg[16][7] = {
  {
    // 0
    HIGH, LOW, LOW, LOW, LOW, LOW, LOW
  },
  {
    // 1
    HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH
  },
  {
    // 2
    LOW, HIGH, LOW, LOW, HIGH, LOW, LOW
  },
  {
    // 3
    LOW, HIGH, HIGH, LOW, LOW, LOW, LOW
  },
  {
    // 4
    LOW, LOW, HIGH, HIGH, LOW, LOW, HIGH
  },
  {
    // 5
    LOW, LOW, HIGH, LOW, LOW, HIGH, LOW
  },
  {
    // 6
    LOW, LOW, LOW, LOW, LOW, HIGH, LOW
  },
  {
    // 7
    HIGH, HIGH, HIGH, HIGH, LOW, LOW, LOW
  },
  {
    // 8
    LOW, LOW, LOW, LOW, LOW, LOW, LOW
  },
  {
    // 9
    LOW, LOW, HIGH, LOW, LOW, LOW, LOW
  },
  // A
  {
    LOW, LOW, LOW, HIGH, LOW, LOW, LOW
  },
  {
    // B
    LOW, LOW, LOW, LOW, LOW, LOW, LOW
  },
  {
    // C
    HIGH, LOW, LOW, LOW, HIGH, HIGH, LOW
  },
  {
    // D
    HIGH, LOW, LOW, LOW, LOW, LOW, LOW
  },
  {
    // E
    LOW, LOW, LOW, LOW, HIGH, HIGH, LOW
  },
  {
    // F
    HIGH, LOW, LOW, HIGH, HIGH, HIGH, LOW
  }
};

Servo servo;
int pin_pulsador = 3;
int pin_infrarojo = 4;
int pin_temperatura = A0;
int pin_motor_dc = A2;
int pin_servo = 11;
int pin = 6;

int pines_siete_seg[7] = {
  // g
  2, 
  // f
  12, 
  // e
  5,
  // d 
  7,
  // c
  8, 
  // b
  9, 
  // a
  10
};

int num_carros = 0;
int umbral_temp = 32;
int umbral_infrarojo = 150;
int angulo = 0;
int duracion = 750;

void setup() {
  Serial.begin(9600);

  // Salidas
  pinMode(pin, OUTPUT);
  pinMode(pin_motor_dc, OUTPUT);
  servo.attach(pin_servo);
  servo.write(0);
  
  for(int i = 0; i < 7; i++){
    pinMode(pines_siete_seg[i], OUTPUT);
  }
  actualizar_siete_seg();

  // Entradas
  pinMode(pin_infrarojo, INPUT);
  pinMode(pin_pulsador, INPUT);
  pinMode(pin_temperatura, INPUT);
}

void loop() {
  actualizar_siete_seg();
  
  int lectura_ir = digitalRead(pin_infrarojo);
  Serial.print("ir: ");
  Serial.println(lectura_ir);
  
  int lectura_pulsador = digitalRead(pin_pulsador);
  Serial.print("pulsador: ");
  Serial.println(lectura_pulsador);

  int lectura_temperatura_raw = analogRead(pin_temperatura);
  int lectura_temperatura = (lectura_temperatura_raw * 5.0 / 1024) / 0.01;
  Serial.print("temp: ");
  Serial.println(lectura_temperatura);

  if (lectura_temperatura > umbral_temp) {
    encender_ventilador();
  } else {
    apagar_ventilador();
  }

  if (lectura_ir == LOW) {
    Serial.println("Ir registrado :D");
    if (num_carros == 12) {
      temardo();
    }
    entrar();
  }

  if (lectura_pulsador == 1) {
    salir();
  }

  delay(500); // Pausa de 500 ms para ver los datos en el monitor serie
}

void entrar() {
  if (num_carros < 12) {
    num_carros++;
    abrir_puerta();
  }
}

void abrir_puerta() {
  servo.write(180);
  delay(2000); // Puerta abierta por 30 segundos
  servo.write(0);
}

void salir() {
  if (num_carros > 0) {
    num_carros--;
    abrir_puerta();
  }
}

void encender_ventilador() {
  analogWrite(pin_motor_dc, 5000);
}

void apagar_ventilador() {
  analogWrite(pin_motor_dc, 0);
}

void actualizar_siete_seg() {
  for (int i = 0; i < 7; i++) {
    digitalWrite(pines_siete_seg[i], numeros_sieteSeg[num_carros][i]);
  }
}

void temardo() {
  analogWrite(pin, e4);
  delay(duracion);
  analogWrite(pin, f4);
  delay(duracion / 2);
  analogWrite(pin, a4);
  delay(duracion / 2);
  analogWrite(pin, a4);
  delay(duracion);
  analogWrite(pin, 0);
  delay(duracion);
  analogWrite(pin, g4s);
  delay(duracion);
  analogWrite(pin, f4);
  delay(duracion / 2);
  analogWrite(pin, e4);
  delay(duracion / 2 + duracion);
  analogWrite(pin, 0);
}