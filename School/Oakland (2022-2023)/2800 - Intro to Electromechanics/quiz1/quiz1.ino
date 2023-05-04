bool on = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int btnPress = digitalRead(3);
  delay(500);

  if(btnPress){
    if(on) on = false;
    else on = true;
  }

  if(on){
    digitalWrite(9, HIGH);
    delay(500);
    digitalWrite(9, LOW);
  }
}

