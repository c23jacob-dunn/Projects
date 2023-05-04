void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  double temp = readThermistor(A0);
  Serial.println(temp);

  /*if(temp<25) digitalWrite(9, 0);

  else if(temp>=25 && temp<=35){
    temp = map(temp, 25, 35, 0, 255);
    Serial.println(temp);
    analogWrite(9, temp);
  }

  else digitalWrite(9, 255);

  Serial.println();*/
  delay(500);
}

double readThermistor(int pin)
{
  double result = 0.00;
  double adc= 0.00;
  int index = 0;
  for(index = 0; index <10; index++)
  {
    adc+= analogRead(pin);
    //Serial.println(adc);
    delay(10);
  }
  adc= adc/ 10.00;
  adc= (1023.00 / adc) -1.00;
  adc= 10000.0 / adc;
  result= adc/ 10000.00;
  result= log(result);
  result= result / 3950;
  result+= 1.0 / (25.00 + 273.15);
  result= 1.0 / result;
  result-= 273.15;
  return result;
}


/*
void setup(){
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(3, INPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop(){
  double x = analogRead(A0);
  double y = analogRead(A1);
  double z = digitalRead(3);

  x = map(x, 0, 1023, 0, 255);
  y = map(y, 0, 1023, 0, 255);

  analogWrite(9, x);
  analogWrite(10, y);

  while(!z){
    Serial.println(x);
    Serial.println(y);
    Serial.println();

    z = digitalRead(3);

    delay(200);
  }
}*/