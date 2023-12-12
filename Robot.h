#include <Servo.h>
class Robot {
public:
  Robot();
  void init();
  void Move_Forward(int speed);
  void Move_Backward(int speed);
  void Rotate_Right(int speed);
  void Rotate_Left(int speed);
  void Clamp(bool open);
  void Move_Arm(int angle);
  void Rotate_Base(int angle);
  void Stop();
  // Constants
  static const int CLAW_CLOSED_POS = 135; // Servo position when claw is fully closed
  static const int CLAW_OPEN_POS = 20; // Servo position when claw is fully closed
  static const int ARM_LOW_POS = 90;  // Servo position when arm is fully lowered
  static const int BASE_CENTER_POS = 90;  // Servo position when the base is pointed straight forward

private:
  // Pins for servos - all are PWM
  const int ARM_SERVO_PIN = 9;
  const int CLAW_SERVO_PIN = 10;
  const int BASE_SERVO_PIN = 11;
  

  // Define pins used for motor
  // TODO add other motors
  const int MTR_A_DIR = 2; // Forward or reverse - Digital
  const int MTR_A_SPD = 5; // Speed - PWM
  const int MTR_B_DIR = 4; // Forward or reverse - Digital
  const int MTR_B_SPD = 6; // Speed - PWM
  // Servos
  Servo armServo;
  Servo clawServo;
  Servo baseServo;
};

