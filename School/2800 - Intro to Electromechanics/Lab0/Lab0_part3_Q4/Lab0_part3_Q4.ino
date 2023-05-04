  int x,y;
  int k=1;

  void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  int k=10;
  x=0;
  y=4;
  Serial.print("x= ");
  Serial.println(x);
  x=x+y;
  Serial.print("x+y= ");
  Serial.println(x);
  x=x*k;
  Serial.print("x*k= ");
  Serial.println(x);
}

void loop() {
  // put your main code here, to run repeatedly:

}
