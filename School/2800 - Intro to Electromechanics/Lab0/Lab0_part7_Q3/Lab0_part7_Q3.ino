/*void setup() { //FIRST PART (STARS ONLY)
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i=0;i<=5;i++){
    for(int j=0;j<i;j++){
      Serial.print("*");
    }
    Serial.println();
  }
}*/

void setup(){ //SECOND PART (STARS AND HASHTAGS)
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i=0;i<=5;i++){
    for(int j=0;j<i;j++){
      Serial.print("*");
    }
    for(int k=5;k>i;k--){
      Serial.print("#");
    }
    Serial.println();
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
