void setup(){
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(3, OUTPUT);
}

void loop(){
  double val = analogRead(A0);
  Serial.println(val);
 
  if (val > 562)
  {
    val = map(val, 563, 1023, 0, 255);
    forward(val);
  }
 
  else if (val < 462)
  {
    val = map(val, 461, 0, 0, 255);
    reverse(val);
  }
 
  else
  {
    brake();
  }
}

void forward (int rate)
{
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(7, LOW);
  analogWrite(3, rate);
}

void reverse (int rate)
{
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(7, HIGH);
  analogWrite(3, rate);
}

void brake ()
{
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(7, LOW);
  digitalWrite(3, HIGH);
}

/*#include <Servo.h>

const int SERVO = 11; //Servo on Pin 9
const int POT  = A0;  //POT on Analog Pin 0

Servo myServo;
int val = 0; //For storing the reading from the POT

void setup()
{
 //Attach the Servo Object
 myServo.attach(SERVO);
}
  
void loop()
{
 val = analogRead(POT);           //Read Pot
 val = map(val, 0, 1023, 0, 179); //scale it to servo range 
 myServo.write(val);              //sets the servo 
 delay(15);                       //waits for the servo
} 


//	Include the AccelStepper library: 
#include <AccelStepper.h>
//	Motor pin definitions:
#define motorPin1 11 // IN1 on the ULN2003 driver 
#define motorPin2 10 // IN2 on the ULN2003 driver 
#define motorPin3 9 // IN3 on the ULN2003 driver 
#define motorPin4 8 // IN4 on the ULN2003 driver
//	Define the AccelStepper interface type; 4 wire motor in half step mode: 
#define MotorInterfaceType 8
//	Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper library with 28BYJ-//48 stepper motor:
AccelStepper stepper = AccelStepper(MotorInterfaceType, motorPin1, motorPin3, motorPin2, motorPin4);

void setup() {
  //	Set the maximum steps per second:   
  stepper.setMaxSpeed(1000);
  stepper.setCurrentPosition(0);
  stepper.setSpeed(500);
}

void loop() {
  //	write code 1 here 
  stepper.currentPosition();
  stepper.runSpeed();
  stepper.run();
  stepper.moveTo(50);
  delay(500);

  //	write code 2 here 
  
  delay(500);

}*/
