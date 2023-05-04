/*int k=10, i=1;
long fact = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(i<=k){
    fact *= i;
    i++;
  }

  Serial.print("Factorial of ");
  Serial.print(k);
  Serial.print(" is ");
  Serial.println(fact);
}

void loop() {
  // put your main code here, to run repeatedly:

}*/



const int k=20;
int sum=0, i=1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(i<=k){
    sum += i;
    i++;
  }
  Serial.print("Sum=");
  Serial.println(sum);
}

void loop() {
  // put your main code here, to run repeatedly:

}
