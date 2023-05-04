  double c;
  int f1=10;
  int f2=20;

  void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  c=(f1-32);
  c=c*5;
  c=c/9;
  Serial.print("f1=");
  Serial.println(f1);
  Serial.print("c=");
  Serial.println(c);

  c=(f2-32);
  c=c*5;
  c=c/9;
  Serial.print("f2=");
  Serial.println(f2);
  Serial.print("c=");
  Serial.println(c);
}

void loop() {
  // put your main code here, to run repeatedly:

}
