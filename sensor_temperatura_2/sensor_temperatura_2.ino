const  int pinTemp=A0;
 int B=3975;
 float temperatura;
 float resistance;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(A0,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
int val=analogRead(pinTemp);
resistance = (float)(1023-val)*10000/val;
temperatura =1/(log(resistance/10000)/B+1/298.15)-273.15;
Serial.println(temperatura);
delay(500);
}



