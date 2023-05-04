int k = 10;
long fact = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i=1;i<=k;i++){
    fact *= i;
  }

  Serial.print("Factorial of ");
  Serial.print(k);
  Serial.print(" is ");
  Serial.println(fact);
}

void loop() {
  // put your main code here, to run repeatedly:

}
