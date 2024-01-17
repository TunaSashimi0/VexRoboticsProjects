
#include "vex.h"

using namespace vex;

competition Competition;


controller Controller1;
motor FL (PORT6, false);
motor FR (PORT7, false);
motor RL (PORT5, true);
motor RR (PORT4, true);
motor intakeL (PORT2, true);
motor intakeR (PORT10 ,false);
motor_group intakes (intakeL, intakeR);
motor armF (PORT12, true);
motor armB (PORT9, true);

void pre_auton(void) {
  vexcodeInit();
}


void autonomous(void) {
  FL.spin (directionType::rev , 100 , velocityUnits::pct);
    RL.spin (directionType::rev , 100 , velocityUnits::pct);
    FR.spin (directionType::fwd , 100 , velocityUnits::pct);
    RR.spin (directionType::fwd , 100 , velocityUnits::pct);
    wait (1, seconds);
    FL.stop();
    FR.stop();
    RL.stop();
    RR.stop();
  armF.spin (directionType::fwd, 100, velocityUnits::pct);
  armB.spin (directionType::fwd, 100, velocityUnits::pct);
  wait (1.5, seconds);
  armF.stop();
  armB.stop();
   FL.spin (directionType::fwd , 100 , velocityUnits::pct);
    RL.spin (directionType::fwd , 100 , velocityUnits::pct);
    FR.spin (directionType::rev , 100 , velocityUnits::pct);
    RR.spin (directionType::rev , 100 , velocityUnits::pct);
    wait (1, seconds);
    FL.stop();
    FR.stop();
    RL.stop();
    RR.stop();
}


void usercontrol(void) {
  while (1) {
    int Ch1 = Controller1.Axis1.value();
    int Ch3 = Controller1.Axis3.value();
    int Ch4 = Controller1.Axis4.value();
    
    FL.spin (directionType::fwd , -(Ch3+Ch1+Ch4) , velocityUnits::pct);
    RL.spin (directionType::fwd , -(Ch3+Ch1-Ch4) , velocityUnits::pct);
    FR.spin (directionType::fwd , -(Ch1-Ch3+Ch4) , velocityUnits::pct);
    RR.spin (directionType::fwd , -(Ch1-Ch3-Ch4) , velocityUnits::pct);
    if (Controller1.ButtonL1.pressing()){
      intakes.spin(directionType::fwd, 90, velocityUnits::pct);
      armF.spin (directionType::rev, 100, velocityUnits::pct);
      armB.spin (directionType::rev, 100, velocityUnits::pct);
    }
    else if (Controller1.ButtonR1.pressing()){
      intakes.spin(directionType::rev, 90, velocityUnits::pct);
      armF.spin (directionType::fwd, 100, velocityUnits::pct);
      armB.spin (directionType::fwd, 100, velocityUnits::pct);
    }
    else {
      intakes.stop();
      armF.stop();
      armB.stop();
    }
    if (Controller1.ButtonB .pressing()){
      armF.spin (directionType::rev, 100, velocityUnits::pct);
      armB.spin (directionType::fwd, 100, velocityUnits::pct);
    }
    else {
      
    }
    wait(20, msec); 
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
