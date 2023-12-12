#include "Controller.h"
#include "Robot.h"
#include "Settings.h"

/* 
 * Functions to set robot speed and steering angle 
 * in response to button press and release events.
 * Update this code if different robot behavior or control scheme is desired.
 */

Robot robot;
Controller controller;

/*
 * Drive the robot full speed forwards when a button is pressed.
 * Stop the robot when the button is released.
 */
void driveForward(bool pressed) {
  Serial.print("Robot ");
  if (pressed) {
      Serial.println("is moving forward");
      robot.Move_Forward(70);
  } else {
      Serial.println("has stopped");
      robot.Stop();
  }
}

/*
 * Drive the robot full speed backwards when a button is pressed.
 * Stop the robot when the button is released.
 */
void driveBackward(bool pressed) {
  Serial.print("Robot ");
  if (pressed) {
      Serial.println("is moving backward");
      robot.Move_Backward(70);
  } else {
      Serial.println("has stopped");
      robot.Stop();
  }
}

/*
 * Steer the robot all the way to the right when a button is pressed.
 * Return the robot to the forward direction when the button is released.
 */
void steerRight(bool pressed) {
  Serial.print("Robot ");
  if (pressed) {
      Serial.println("is steering right");
      robot.Rotate_Right(70);
  } else {
      Serial.println("is steering forward");
      robot.Stop();
  }
}

/*
 * Steer the robot all the way to the left when a button is pressed.
 * Return the robot to the forward direction when the button is released.
 */
void steerLeft(bool pressed) {
  Serial.print("Robot ");
  if (pressed) {
      Serial.println("is steering left");
      robot.Rotate_Left(70);
  } else {
      Serial.println("is steering forward");
      robot.Stop();
  }
}

/*
 * Open the robot's claw when a button is pressed.
 * Close the claw when the button is released.
 */
void clamp(bool pressed) {
  Serial.print("Robot ");
  if (pressed) {
      Serial.println("is opening claw");
  } else {
      Serial.println("is closing claw");
  }
  robot.Clamp(pressed);
}

/*
 * Raise the robot's arm when a button is pressed.
 * Stop raising arm when the button is released.
 */
void raise(bool pressed) {
  Serial.print("Robot ");
  if (pressed) {
      Serial.println("is raising arm");
      robot.Move_Arm(45);
  } else {
    Serial.println("is lowering arm");
    robot.Move_Arm(135);
  }
}

/*
 * Connect controller buttons to robot functions
 */
void registerRobotFunctions() {
  controller.registerCallback(0, driveForward);
  controller.registerCallback(1, driveBackward);
  controller.registerCallback(2, steerLeft);
  controller.registerCallback(3, steerRight);
  controller.registerCallback(4, clamp);
  controller.registerCallback(5, raise);
}

/*
 * Functions below this comment are generic and do not need to be modified.
 */

/*
 * Set up robot and controller.
 */
void init_everything() {
  // Initialize serial connection
  Serial.begin(9600);

  // Initialize controller
  controller.init(ROBOT_NAME);

  // Initialize robot
  robot.init();

  // Connect controller buttons to robot functions
  registerRobotFunctions();
  Serial.println("Robot ready for Bluetooth pairing and commands");
}

/*
 * Updates the robot by allowing the controller to check for
 * inputs and call the associated robot functions.
 */
void update() {
  controller.update();
  // if (Serial.available() > 0) {
  //   int receivedValue = Serial.parseInt();
  //   if (Serial.read() == '\n') {
  //     Serial.print("Received value: ");
  //     Serial.println(receivedValue);

  //     robot.Move_Arm(receivedValue);
  //   }
  //   Serial.flush();
  // }
}