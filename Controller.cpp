// Import Dabble library
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>

#include "Controller.h"

/*
 * A class which allows custom functions to be called 
 * when buttons on a Dabble gamepad are pressed or released.
 * Does not require any modifications in order to be used in different projects.
 */
Controller::Controller(): buttons{{false, defaultCallback}, {false, defaultCallback}, {false, defaultCallback}, {false, defaultCallback}, {false, defaultCallback}, {false, defaultCallback}} {
  // Constructor implementation
}


/*
 * Default button action; intentionally does nothing.
 */
void Controller::defaultCallback(bool newState) {}

/*
 * Internal method used to update a button's state 
 * and trigger the associated function if the state has changed.
 */
void Controller::setButtonState(int buttonIndex, bool newState) {
    ButtonData& buttonData = buttons[buttonIndex];
    // Check if the button state has changed
    if (buttonData.state != newState) {
        buttonData.state = newState;
        // Call the button's callback with its state information
        buttonData.callback(newState);
    }
}

/*
 * Associates the given function with the given button.
 */
void Controller::registerCallback(int buttonIndex, FunctionPointer callback) {
    buttons[buttonIndex].callback = callback;
}

/*
 * Sets up the Dabble connection.
 */
void Controller::init(String robotName) {
  Dabble.begin(9600, 0, 1);
}

/*
 * Checks for input from the Dabble gamepad and updates internal states.
 */
void Controller::update() {
  Dabble.processInput();
  setButtonState(0, GamePad.isTrianglePressed());
  setButtonState(1, GamePad.isCrossPressed());
  setButtonState(2, GamePad.isLeftPressed());
  setButtonState(3, GamePad.isRightPressed());
  setButtonState(4, GamePad.isSelectPressed());
  setButtonState(5, GamePad.isUpPressed());
}