#define btn1 12
#define btn2 11
#define btn3 10
#define btn4 9

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  pinMode(btn3, INPUT_PULLUP);
  pinMode(btn4, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(digitalRead(btn1));
  Serial.print(digitalRead(btn2));
  Serial.print(digitalRead(btn3));
  Serial.print(digitalRead(btn4));
  Serial.println();
  
}
