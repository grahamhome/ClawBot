class Robot {
public:
  Robot();
  void init();
  void Move_Forward(int speed);
  void Move_Backward(int speed);
  void Rotate_Right(int speed);
  void Rotate_Left(int speed);
  void Clamp(int position);
  void Stop();
};