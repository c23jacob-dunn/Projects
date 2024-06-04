const int analogInPin = A0;
int sensorValue = 0;
int outputValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(analogInPin);
  outputValue = map(sensorValue, 0, 1023, 255, 0);

  //Serial.print("sensor = ");
  //Serial.print(sensorValue);
  //Serial.print("\t output = ");
  Serial.println(outputValue);

  delay(500);
}