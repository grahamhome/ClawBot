#include <Arduino.h>
#include <Servo.h>
#include "Robot.h"

// Define pins for servos - all are PWM
const int ARM_SERVO_PIN = 9;
const int CLAW_SERVO_PIN = 10;
const int BASE_SERVO_PIN = 11;

// Define servo angles for init/default position
const int ARM_DEFAULT_DEG = 90;  //initialize the angle value of arm servo
const int CLAW_DEFAULT_DEG  = 135; //initialize the angle value of claw servo
const int BASE_DEFAULT_DEG = 90;  //initialize the angle value of base servo

// Define pins used for motor
// TODO add other motors
const int MTR_A_DIR = 2; // Forward or reverse - Digital
const int MTR_A_SPD = 5; // Speed - PWM
const int MTR_B_DIR = 4; // Forward or reverse - Digital
const int MTR_B_SPD = 6; // Speed - PWM

// TODO make these servo instances private variables in the Robot class
Servo armServo;  //servo of arm
Servo clawServo;   //servo of claw
Servo baseServo;  //servo of base

Robot::Robot() {
  
}
void Robot::init() {

  pinMode(MTR_A_DIR, OUTPUT);
  pinMode(MTR_A_SPD, OUTPUT);
  pinMode(MTR_B_DIR, OUTPUT);
  pinMode(MTR_B_SPD, OUTPUT);
  
  armServo.attach(ARM_SERVO_PIN);   //claw Servo 1 is connected to D9
  clawServo.attach(CLAW_SERVO_PIN);   //arm Servo 2 is connected to D10
  baseServo.attach(BASE_SERVO_PIN);  //base Servo 3 is connected to D11

  armServo.write(ARM_DEFAULT_DEG);
  clawServo.write(CLAW_DEFAULT_DEG);
  baseServo.write(BASE_DEFAULT_DEG);
}

// Drive the robot forward at the passed in speed (0-255)
void Robot::Move_Forward(int speed)
{
  Serial.println("Robot is REALLY moving forward");
  digitalWrite(MTR_A_DIR,HIGH); //D2 digital I/O port controls the direction of the motor of interface A
  analogWrite(MTR_A_SPD,speed); //D5 digital I/O port outputs PWM signal to control the speed of the motor of port A.
  digitalWrite(MTR_B_DIR,LOW);  //D4 digital I/O port controls the direction of the motor of interface B - reverse of A 
  analogWrite(MTR_B_SPD,speed); //D6 digital I/O port outputs PWM signal to control the speed of interface B motor.
}

// Drive the robot backward at the passed in speed (0-255)
void Robot::Move_Backward(int speed)
{
  digitalWrite(MTR_A_DIR,LOW);
  analogWrite(MTR_A_SPD,speed);
  digitalWrite(MTR_B_DIR,HIGH);
  analogWrite(MTR_B_SPD,speed);
}

// Spin the robot right on its axis at the passed in speed
void Robot::Rotate_Right(int speed)
{
  digitalWrite(MTR_A_DIR,HIGH);
  analogWrite(MTR_A_SPD,speed);
  digitalWrite(MTR_B_DIR,HIGH);
  analogWrite(MTR_B_SPD,speed);
}

// Spin the robot left on its axis at the passed in speed
void Robot::Rotate_Left(int speed)
{
  digitalWrite(MTR_A_DIR,LOW);
  analogWrite(MTR_A_SPD,speed);
  digitalWrite(MTR_B_DIR,LOW);
  analogWrite(MTR_B_SPD,speed);
}

// Stop all motors, set to move forward
void Robot::Stop()
{
  digitalWrite(MTR_A_DIR,LOW);
  analogWrite(MTR_A_SPD,0);
  digitalWrite(MTR_B_DIR,HIGH);
  analogWrite(MTR_B_SPD,0);
}

/*
 * Give 'em the clamps!
 * Open or close robot claw.
 */
void Robot::Clamp(int position) {
  clawServo.write(position);
}