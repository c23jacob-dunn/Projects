/*void setup() { //Part 1a
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
}
void loop() { 
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}*/


void setup() { //Part 1b
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<3; i++){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(250);
    digitalWrite(LED_BUILTIN, LOW);
    delay(250);
  }

  for(int i=0; i<3; i++){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(750);
    digitalWrite(LED_BUILTIN, LOW);
    delay(750);
  }

  for(int i=0; i<3; i++){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(250);
    digitalWrite(LED_BUILTIN, LOW);
    delay(250);
  }

  delay(1000);
  
}


/*const byte LED = 11;
const byte SWU = 5;
const byte SWD = 3;
uint8_t dc = 128;
void setup() { //Part 2
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(SWU, INPUT);
  pinMode(SWD, INPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  int up = digitalRead(SWU);
  int down = digitalRead(SWD);
  if(up){
    dc += 25;
  }
  if(down){
    dc -= 25;
  }

  analogWrite(LED, dc);
  delay(200);
}*/


/*const byte LED[] = {6,7,8,9};
void setup() { //Part 3
  // put your setup code here, to run once:
  for(int i=0; i<4; i++){
    pinMode(LED[i], OUTPUT);
  }
}
  for(int i=0; i<16; i++){
    if(i%2 > 0){
      digitalWrite(LED[0], HIGH);
    }
    else{
      digitalWrite(LED[0], LOW);
    }

    if(i%4 > 1){
      digitalWrite(LED[1], HIGH);
    }
    else{
      digitalWrite(LED[1], LOW);
    }

    if(i%8 > 3){
      digitalWrite(LED[2], HIGH);
    }
    else{
      digitalWrite(LED[2], LOW);
    }

    if(i%16 > 7){
      digitalWrite(LED[3], HIGH);
    }
    else{
      digitalWrite(LED[3], LOW);
    }

    delay(500);
  }
}*/