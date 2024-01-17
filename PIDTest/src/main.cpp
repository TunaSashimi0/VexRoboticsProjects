/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Alex_                                            */
/*    Created:      Thu Mar 11 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;



double KP = 0.0;
double KI = 0.0;
double KD = 0.0;

int error; //SensorValue - DesiredValue : Position
int prevError = 0; //Position 20 miliseconds ago
int derivative; // error - prevError : Speed
int totalError = 0; //totalError = totalError + error

int turnError; //SensorValue - DesiredValue : Position
int turnPrevError = 0; //Position 20 miliseconds ago
int turnDerivative; // error - prevError : Speed
int turnTotalError = 0; //totalError = totalError + error

void PID (double DesireValue){
  int Left = L.position(degrees);
  int Right = R.position(degrees);
  int averagePosition = (Left + Right)/2;
  
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  while (true){
    if (b.pressing()){
      vexcodeInit();
    }
    PID(300);
  }
}

