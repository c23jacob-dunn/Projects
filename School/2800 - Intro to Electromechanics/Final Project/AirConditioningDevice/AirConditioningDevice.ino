///////////////////////////////////////////////////////////////////////////////
//File Name:     AirConditioningDevice.ino
//Authors:       Jacob Dunn, Saad Seir, Joel Sturdivant, Thomas Zurek
//Created On:    23 March 2023
//Last Modified: 24 April 2023
//Description:   This program will control the temperature between two rooms by
//               using an air conditioning duct to filter hot air to the colder
//               room as well as getting colder air from outside by the use of
//               thermistors and fans. The temperatures and other status
//               updates will be displayed on an LED.
///////////////////////////////////////////////////////////////////////////////

#include <LiquidCrystal.h> //Library for LCD use

const int TEMP_TOO_HOT = 22;
const int TEMP_HIGH_HOT = 27;
const int TEMP_LOW_HOT = 24;

const int ROOM_TEMP_1 = 21;
const int ROOM_TEMP_2 = 21;

const int CHANGE_LIGHT_VALUE = 100;
int speedDuct = 0;
int speedOutside = 0;
double tempRoom1 = 0;
double tempRoom2 = 0;

byte thermRes1 = A0;
byte thermRes2 = A1;
const int photoRes = A2; //Photoresistor pin
const int outsideFan = 6; //Fan pins
const int Hen = 9, H1a = 8, H2a = 10; //H-Bridge Connections
const int LEDrs = 12, LEDen = 11, LEDd4 = 5, 
          LEDd5 = 4,  LEDd6 = 3,  LEDd7 = 2; //LED Connections

LiquidCrystal lcd(LEDrs, LEDen, LEDd4, 
                  LEDd5, LEDd6, LEDd7); //Struct Definition

void setup() {
  Serial.begin(9600);

  pinMode(photoRes, INPUT); //Photoresistor for Day/Night
  pinMode(thermRes1, INPUT); //Thermistor for Room 1
  pinMode(thermRes1, INPUT); //Thermistor for Room 2
  pinMode(outsideFan, OUTPUT); //Fan for Outside Air
  pinMode(Hen, OUTPUT); //Fan for Ventilation Duct

  lcd.begin(16, 2); //Configure LED
  lcd.setCursor(6,0);
  lcd.print("A/C");
  lcd.setCursor(5,1);
  lcd.print("Device");
  delay(3000);
  lcd.clear();
  delay(500);
}

void loop() {
  int i = 1;
  while(i){
    Serial.print(i);
    Serial.println("----------------------------------");
    Photoresistor();
    DuctFan();
    OutsideFan();
    Serial.println("-----------------------------------");
    Serial.println();
    i++;
    delay(1000);
  }
}

void Photoresistor(void){
  int light = analogRead(photoRes);

  if(light < CHANGE_LIGHT_VALUE){ //Determine Day or Night
    lcd.setCursor(15,1);
    lcd.print("N");

    Serial.print("Day/Night: ");
    Serial.print("N ");
    Serial.println(light);
  }
  else{
    lcd.setCursor(15,1);
    lcd.print("D");

    Serial.print("Day/Night: ");
    Serial.print("D ");
    Serial.println(light);
  }
}

void DuctFan(void){
  tempRoom1 = readThermistor(A0);
  tempRoom2 = readThermistor(A1);

  if((tempRoom1 < (tempRoom2 + (tempRoom2*.075))) && 
     (tempRoom1 > (tempRoom2 - (tempRoom2*.075)))){ //15% range to shut off fan
    stop();
    speedDuct = 0;
  }
  else if(tempRoom1 > tempRoom2){ //fan speed forward
    speedDuct = tempRoom1 - tempRoom2; //speed based on difference
    speedDuct = map(speedDuct, 0, TEMP_HIGH_HOT-ROOM_TEMP_2, 0, 255);
    reverse(speedDuct);
  }
  else if(tempRoom1 < tempRoom2){ //fan speed backward
    speedDuct = tempRoom2 - tempRoom1; //speed based on difference
    speedDuct = map(speedDuct, 0, TEMP_HIGH_HOT-ROOM_TEMP_1, 0, 255);
    forward(speedDuct);
  }

  lcd.setCursor(0,0);
  lcd.print("T1=");
  int temp1 = tempRoom1;
  lcd.print(temp1);

  Serial.print("TempRoom1 = ");
  Serial.println(temp1);
  
  lcd.setCursor(0,1);
  lcd.print("T2=");
  int temp2 = tempRoom2;
  lcd.print(temp2);

  Serial.print("TempRoom2 = ");
  Serial.println(temp2);

  speedDuct = map(speedDuct, 0, 255, 0, 99);
  lcd.setCursor(7,0);
  lcd.print("S1=");
  lcd.print(speedDuct);

  Serial.print("Speed of Duct Fan = ");
  Serial.println(speedDuct);
}

double readThermistor(int pin){ //Calculate temperature in Celcius
  double result = 0.00;
  double adc= 0.00;
  int index = 0;
  
  for(index = 0; index <10; index++){
    adc+= analogRead(pin);
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

void OutsideFan(void){
  tempRoom1 = readThermistor(A0);

  if(tempRoom1 >= TEMP_TOO_HOT){ //turn on A/C fan on outside of box
    speedOutside = map(tempRoom1, TEMP_TOO_HOT, TEMP_HIGH_HOT, 0, 255);
    analogWrite(outsideFan, speedOutside);
    speedOutside = map(speedOutside, 0, 255, 0, 99);
  }
  else if(tempRoom1 < TEMP_TOO_HOT){
    //turn off A/C fan on outside of box
    speedOutside = 0;
    analogWrite(outsideFan, speedOutside);
  }

  lcd.setCursor(7,1);
  lcd.print("S2=");
  lcd.print(speedOutside);

  Serial.print("Speed of Outside Fan = ");
  Serial.println(speedOutside);
}

void forward (int rate){ //Duct fan spins forward at rate
  digitalWrite(Hen, LOW);
  digitalWrite(H1a, HIGH);
  digitalWrite(H2a, LOW);
  analogWrite(Hen, rate);
}

void reverse (int rate){ //Duct fan spins backwards at rate
  digitalWrite(Hen, LOW);
  digitalWrite(H1a, LOW);
  digitalWrite(H2a, HIGH);
  analogWrite(Hen, rate);
}

void stop (){ //Duct fan off
  digitalWrite(Hen, LOW);
  digitalWrite(H1a, LOW);
  digitalWrite(H2a, LOW);
  digitalWrite(Hen, HIGH);
}
