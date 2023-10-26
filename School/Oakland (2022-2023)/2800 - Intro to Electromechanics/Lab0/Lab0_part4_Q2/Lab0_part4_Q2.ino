  double c;
  int f=10;

  void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  c=(f-32);
  c=c*5;
  c=c/9;
  Serial.print("f=");
  Serial.println(f);
  Serial.print("c=");
  Serial.println(c);
}

void loop() {
  // put your main code here, to run repeatedly:

}
