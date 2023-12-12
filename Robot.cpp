#include <Arduino.h>
#include "Robot.h"


Robot::Robot() {}
void Robot::init() {

  pinMode(MTR_A_DIR, OUTPUT);
  pinMode(MTR_A_SPD, OUTPUT);
  pinMode(MTR_B_DIR, OUTPUT);
  pinMode(MTR_B_SPD, OUTPUT);
  
  armServo.attach(ARM_SERVO_PIN);   //claw Servo 1 is connected to D9
  clawServo.attach(CLAW_SERVO_PIN);   //arm Servo 2 is connected to D10
  baseServo.attach(BASE_SERVO_PIN);  //base Servo 3 is connected to D11

  Move_Arm(ARM_LOW_POS);
  Clamp(false);
  Rotate_Base(BASE_CENTER_POS);
}

// Drive the robot forward at the passed in speed (0-255)
void Robot::Move_Forward(int speed)
{
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
void Robot::Clamp(bool open) {
  if (open) {
    clawServo.write(CLAW_OPEN_POS);
  } else {
    clawServo.write(CLAW_CLOSED_POS);
  }
}

/*
 * Set the arm to the given position.
 */
void Robot::Move_Arm(int angle) {
  armServo.write(angle);
}

/*
 * Set the base to the given position.
 */
void Robot::Rotate_Base(int angle) {
  baseServo.write(angle);
}