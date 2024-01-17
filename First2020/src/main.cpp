
#include "vex.h"

using namespace vex;

competition Competition;


controller Controller1;
motor FL (PORT15, false);
motor FR (PORT14, false);
motor RL (PORT13, true);
motor RR (PORT1, true);
motor intakeL (PORT9, false);
motor intakeR (PORT5 , true);
motor_group intakes (intakeL, intakeR);
motor armF (PORT7, false);
motor armB (PORT3, false);


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
  RL.stop();
  FR.stop();
  RR.stop();
  armF.spin (directionType::rev, 100, velocityUnits::pct);
  armB.spin (directionType::rev, 100, velocityUnits::pct);
  wait (2, seconds);
  armF.stop();
  armB.stop();
  Brain.Screen.clearLine(0,color::black);
  Brain.Screen.clearLine(1,color::black);
  Brain.Screen.setCursor(1,0);
  Brain.Screen.print("Good afternoon");
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
      intakes.spin(directionType::fwd, 100, velocityUnits::pct);
      armF.spin (directionType::rev, 100, velocityUnits::pct);
      armB.spin (directionType::rev, 100, velocityUnits::pct);
    }
    else if (Controller1.ButtonR1.pressing()){
      intakes.spin(directionType::rev, 100, velocityUnits::pct);
      armF.spin (directionType::fwd, 100, velocityUnits::pct);
      armB.spin (directionType::fwd, 100, velocityUnits::pct);
    }
    else {
      intakes.stop();
      armF.stop();
      armB.stop();
    }
    if (Controller1.ButtonB .pressing()){
      armF.spin (directionType::fwd, 100, velocityUnits::pct);
      armB.spin (directionType::rev, 100, velocityUnits::pct);
    }
    else {
      
    }
    wait(20, msec); 
  }
}


int main() {
  
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  
  pre_auton();

  
  while (true) {
    wait(100, msec);
  }
}
