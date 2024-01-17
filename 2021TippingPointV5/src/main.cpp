
#include "vex.h"

using namespace vex;

competition Competition;


controller Controller1;

motor FL (PORT12, false);
motor FR (PORT9, true);
motor RL (PORT13, false);
motor RR (PORT20, true);

motor intake (PORT19, false);
motor arm (PORT1, true);
motor arm1 (PORT7, false);
//motor bar (PORT15, false);
motor_group arms (arm, arm1);
motor_group leftDrive (FL, RL);
motor_group rightDrive (FR, RR);

int driveType = 1;

void pre_auton(void) {
  vexcodeInit();
}


void autonomous(void) {
  arms.spin(directionType::fwd, 80, velocityUnits::pct);
  wait(1, sec);
  arms.stop();
  leftDrive.spin(directionType::fwd, 80, velocityUnits::pct);
  rightDrive.spin(directionType::fwd, 80, velocityUnits::pct);
  wait(1, sec);
  leftDrive.stop();
  rightDrive.stop();
  arms.spin(directionType::rev, 80, velocityUnits::pct);
  wait(1, sec);
  arms.stop();
  leftDrive.spin(directionType::rev, 40, velocityUnits::pct);
  rightDrive.spin(directionType::rev, 40, velocityUnits::pct);
  wait(1.5, sec);
  leftDrive.stop();
  rightDrive.stop();
  intake.spin(directionType::rev, 80, velocityUnits::pct);
  wait(2, sec);
  intake.stop();
  arms.spin(directionType::fwd, 80, velocityUnits::pct);
  wait(1, sec);
  arms.stop();
  leftDrive.spin(directionType::rev, 50, velocityUnits::pct);
  rightDrive.spin(directionType::rev, 50, velocityUnits::pct);
  wait(1, sec);
  leftDrive.stop();
  rightDrive.stop();
}


void usercontrol(void) {
  while (1) {
    
    FL.spin(vex::directionType::fwd, (Controller1.Axis3.value()*driveType + Controller1.Axis4.value()*0.7), vex::velocityUnits::pct);
    RL.spin(vex::directionType::fwd, (Controller1.Axis3.value()*driveType + Controller1.Axis4.value()*0.7), vex::velocityUnits::pct);
    FR.spin(vex::directionType::fwd, (Controller1.Axis3.value()*driveType - Controller1.Axis4.value()*0.7), vex::velocityUnits::pct);
    RR.spin(vex::directionType::fwd, (Controller1.Axis3.value()*driveType - Controller1.Axis4.value()*0.7), vex::velocityUnits::pct);
    if (Controller1.ButtonR1.pressing()){
      intake.spin(directionType::rev, 90, velocityUnits::pct);
    }
    else if (Controller1.ButtonL1.pressing()){
      intake.stop();
    }
    else if (Controller1.ButtonR2.pressing()){
      intake.spin(directionType::fwd, 80, velocityUnits::pct);
    }
    
    if (Controller1.ButtonY.pressing()){
      arms.spin(directionType::fwd, 80, velocityUnits::pct);
    }
    else if (Controller1.ButtonA.pressing()){
      arms.spin(directionType::rev, 80, velocityUnits::pct);
    }
    else{
      arms.stop();
    }
    /*if (Controller1.ButtonUp.pressing()){
      bar.spin(directionType::fwd, 80, velocityUnits::pct);
    }
    else if (Controller1.ButtonDown.pressing()){
      bar.spin(directionType::rev, 80, velocityUnits::pct);
    }
    else{
      bar.stop();
    }*/
    if (Controller1.ButtonX.pressing()){
      driveType *= -1;
      wait(150,msec);
    }
    wait(3, msec); 
  }
}


int main() {
  pre_auton();
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  
  while (true) {
    wait(100, msec);
  }
}
