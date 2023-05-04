  void fahr2cels(int f) {
    double c;
    c=(f-32);
    c=c*5;
    c=c/9;
    Serial.print("f=");
    Serial.println(f);
    Serial.print("c=");
    Serial.println(c);
    Serial.println("---------");
  }

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  fahr2cels(10);
  fahr2cels(20);
  fahr2cels(30);
  fahr2cels(40);
}

void loop() {
  // put your main code here, to run repeatedly:

}
