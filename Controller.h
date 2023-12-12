#pragma once
#include <Arduino.h>

typedef void (*FunctionPointer)(bool);

class Controller {
public:
  Controller();
  void init(String robotName);
  void update();
  void registerCallback(int buttonIndex, FunctionPointer callback);

private:
  struct ButtonData {
    bool state;
    FunctionPointer callback;
  };
  ButtonData buttons[6];
  void setButtonState(int buttonIndex, bool newState);
  static void defaultCallback(bool newState);
};