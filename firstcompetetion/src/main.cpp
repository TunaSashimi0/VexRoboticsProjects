/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Alex_                                            */
/*    Created:      Wed Oct 02 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;
using namespace vex;
vex::brain Brain;
vex::motor LeftMotorFront  (vex::PORT1, vex::gearSetting::ratio18_1, false);
vex::motor LeftMotorBack  (vex::PORT11, vex::gearSetting::ratio18_1, false);
vex::motor RightMotorBack (vex::PORT10, vex::gearSetting::ratio18_1, true);
vex::motor RightMotorFront (vex::PORT12, vex::gearSetting::ratio18_1, true);
vex::motor rightarm (vex::PORT3, vex::gearSetting::ratio36_1, true);
vex::motor leftarm (vex::PORT19, vex::gearSetting::ratio36_1, false);
vex::motor claw (vex::PORT18, vex::gearSetting::ratio18_1, true);
vex::motor rightintake(vex::PORT17, vex::gearSetting::ratio36_1, false);
vex::motor leftintake(vex::PORT2, vex::gearSetting::ratio36_1,true);

vex::controller Controller1 = vex::controller();

vex::competition Competition;

// define your global instances of motors and other devices here



void pre_auton( void ) {
  Brain.Screen.setFont(monoXL);
  Brain.Screen.print("");
  
}


/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous( void ) {
  leftarm.spin(directionType:: fwd, 100, percentUnits::pct);
  rightarm.spin(directionType:: fwd, 100, percentUnits::pct);
  leftintake.spin(directionType:: fwd, 100 , percentUnits::pct);
  rightintake.spin(directionType:: fwd, 100 , percentUnits::pct);
  wait(1 , timeUnits::sec);
  leftarm.spin(directionType:: rev, 100, percentUnits::pct);
  rightarm.spin(directionType:: rev, 100, percentUnits::pct);
  wait(1 , timeUnits::sec);
  leftintake.stop();
  rightintake.stop();
  LeftMotorBack.spin(directionType::fwd, 70 , percentUnits::pct);
  RightMotorBack.spin(directionType::fwd, 70 , percentUnits::pct);
  RightMotorFront.spin(directionType::fwd, 70 , percentUnits::pct);
  LeftMotorFront.spin(directionType::fwd, 70 , percentUnits::pct);
  wait( 1.2 , timeUnits::sec);
  LeftMotorBack.stop();
  RightMotorBack.stop();
  RightMotorFront.stop();
  LeftMotorFront.stop();
  wait(1, timeUnits::sec);
  LeftMotorBack.spin(directionType::rev, 70 , percentUnits::pct);
  RightMotorBack.spin(directionType::rev, 70 , percentUnits::pct);
  RightMotorFront.spin(directionType::rev, 70 , percentUnits::pct);
  LeftMotorFront.spin(directionType::rev, 70 , percentUnits::pct);
  wait( 1.5 , timeUnits::sec);
  LeftMotorBack.stop();
  RightMotorBack.stop();
  RightMotorFront.stop();
  LeftMotorFront.stop();
}


void usercontrol( void ) {
  
Brain.Screen.clearScreen();
Brain.Screen.setFont(monoXXL);
Brain.Screen.print("");
Brain.Screen.newLine();
Brain.Screen.print("");
    
    while(1) {

        LeftMotorFront.spin(vex::directionType::fwd, (Controller1.Axis3.value()+Controller1.Axis4.value()), vex::velocityUnits::pct); //(Axis3+Axis4)/2
        LeftMotorBack.spin(vex::directionType::fwd, (Controller1.Axis3.value()+Controller1.Axis4.value()), vex::velocityUnits::pct); //(Axis3+Axis4)/2
        RightMotorBack.spin(vex::directionType::fwd, (Controller1.Axis3.value()-Controller1.Axis4.value()), vex::velocityUnits::pct);//(Axis3-Axis4)/2
        RightMotorFront.spin(vex::directionType::fwd, (Controller1.Axis3.value()-Controller1.Axis4.value()), vex::velocityUnits::pct);//(Axis3-Axis4)/
        if(Controller1.ButtonX.pressing()){
         leftarm.spin(directionType::fwd);
         rightarm.spin(directionType::fwd);
        }
        else if(Controller1.ButtonB.pressing()){
          leftarm.spin(directionType::rev);
          rightarm.spin(directionType::rev);
        }
       else{
          rightarm.stop(brakeType::hold);
          leftarm.stop(brakeType::hold);
        }
        if(Controller1.ButtonR2.pressing()){
          claw.spin(directionType::fwd);
        }
        else if(Controller1.ButtonR1.pressing()){
          claw.spin(directionType::rev);
        }
        else{
          claw.stop(brakeType::hold);
        }
        
        if(Controller1.ButtonL1.pressing()){
          leftintake.spin(directionType::fwd, 100 , percentUnits::pct);
          rightintake.spin(directionType::fwd, 100 , percentUnits::pct);
          
        }
        else if(Controller1.ButtonL2.pressing()){
          leftintake.spin(directionType::rev, 100 , percentUnits::pct);
          rightintake.spin(directionType::rev, 100 , percentUnits::pct);
          
        }
        else{
          leftintake.stop();
          rightintake.stop();
        }

        vex::task::sleep(15); 
    }

}

int main() {
    //Set up callbacks for autonomous and driver control periods.
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );
    
    //Run the pre-autonomous function. 
    pre_auton();
       
    //Prevent main from exiting with an infinite loop.                        
    while(1) {
      vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
    }    
       
}