int pinesSieteSeg[7];
// g 0
// f 1
// e 2
// d 3
// c 4
// b 5
// a 6

int numeros[10][7] ={
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
  }
};

void setup() {
  // put your setup code here, to run once:
  int pin = 3;
  for(int i = 0; i < 7; i++){
    pinesSieteSeg[i] = pin;
    pinMode(pinesSieteSeg[i], OUTPUT);
    pin++;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 7; j++){
      analogWrite(pinesSieteSeg[i][j] , numeros[j]);
    }
  }
}
