// led_rojo = 5;
// led_azul = 6;
// led_amarillo = 7;

int leds[3] = { 5, 6, 7 };
int del = 30;


void setup() {
  pinMode(leds[0], OUTPUT);
  pinMode(leds[1], OUTPUT);
  pinMode(leds[2], OUTPUT);
}

void loop() {
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i <= 255; i += 5) {
      analogWrite(leds[j], i);
      delay(del);
    }
    for (int i = 255; i >= 0; i -= 10) {
      analogWrite(leds[j], i);
      delay(del);
    }
  }
}
