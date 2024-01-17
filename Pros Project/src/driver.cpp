#include "main.h"


void Driver::drive() {
  int Ch1 = master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
  int Ch3 = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
  int Ch4 = master.get_analog(E_CONTROLLER_ANALOG_LEFT_X);
  FL = -(Ch3+Ch1+Ch4)/100*127;
  BL = -(Ch3+Ch1-Ch4)/100*127;
  FR = -(Ch1-Ch3+Ch4)/100*127;
  BR = -(Ch1-Ch3-Ch4)/100*127;
}

void Driver::intakeAndscore (bool in) {
  intakeL = in*127;
  intakeR = in*-127;
  rollerH = in*127;
  rollerL = in*127;
}

void Driver::outtakeAnddescore (bool in) {
  intakeL = in*-127;
  intakeR = in*127;
  rollerH = in*-127;
  rollerL = in*-127;
}

void Driver::intakeAnddescore (bool in) {
  intakeL = in*127;
  intakeR = in*-127;
  rollerH = in*-127;
  rollerL = in*127;
}

void Driver::descore (bool in) {
  rollerH = in*-127;
  rollerL = in*127;
}
