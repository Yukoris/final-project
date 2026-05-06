#include <BleGamepad.h>
#define BUTTON_PIN1 12  // GPIO12
#define BUTTON_PIN2 14  // GPIO14
#define BUTTON_PIN3 26  // GPIO26
#define BUTTON_PIN4 27  // GPIO27
#define NUM_BUTTONS 4
BleGamepad bleGamepad ("Yuko's Gamepad", "Yuko", 100);

//joysticks; switch the pin values if you change INVERT_Y/INVERT_X bools.
#define VRX_JOYSTICK 15
#define VRY_JOYSTICK 4

#define INVERT_Y true
#define INVERT_X true

int buttonPins[NUM_BUTTONS] = { BUTTON_PIN1, BUTTON_PIN2, BUTTON_PIN3, BUTTON_PIN4 };
int buttons[NUM_BUTTONS] = { BUTTON_1, BUTTON_2, BUTTON_4, BUTTON_5 };

int VrxReading = 0;
int VryReading = 0;
int VrxValue = 0;
int VryValue = 0;

void setup() {
  Serial.begin(115200);
  // initialize the push-button pins as pull-up input
  pinMode(BUTTON_PIN1, INPUT_PULLUP);
  pinMode(BUTTON_PIN2, INPUT_PULLUP);
  pinMode(BUTTON_PIN3, INPUT_PULLUP);
  pinMode(BUTTON_PIN4, INPUT_PULLUP);
  bleGamepad.begin();
}

void loop() {
  if (bleGamepad.isConnected()) {

    VrxReading = analogRead(VRX_JOYSTICK);
    VryReading = analogRead(VRY_JOYSTICK);

    VrxValue = map(VrxReading, 4095, 0, 0, 32737);
    VryValue = map(VryReading, 4095, 0, 0, 32737);

    int VrxCenter = 32737 / 2;
    int VryCenter = 32737 / 2;

    if (VrxValue < VrxCenter + 2000 && VrxValue > VrxCenter - 2000) {
      VrxValue = VrxCenter;
    }
      if (VryValue < VryCenter + 2000 && VryValue > VryCenter - 2000) {
      VryValue = VryCenter;
    }

    if (INVERT_Y) {
      VryValue = 32737 - VryValue;
      if (VryValue < 0) {
        VryValue = -VryValue;
      }
    }
    if (INVERT_X) {
      VrxValue = 32737 - VrxValue;
      if (VrxValue < 0) {
        VrxValue = -VrxValue;
      }
    }

    bleGamepad.setLeftThumb(VrxValue, VryValue);

    for (int i = 0; i < NUM_BUTTONS; i++) {
      if (!digitalRead(buttonPins[i])) {
        bleGamepad.press(buttons[i]);
        }
      else {
        bleGamepad.release(buttons[i]);
      }
    }
  }
}
