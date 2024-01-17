#include "vex.h"
using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;
/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */

controller controller1 = controller(primary);
motor LeftF = motor (PORT1, ratio18_1, true);
motor LeftB = motor (PORT2, ratio18_1, true);
motor RightF = motor (PORT3, ratio18_1, true);
motor RightB = motor (PORT4, ratio18_1, true);
motor_group L = motor_group(LeftF, LeftB);
motor_group R = motor_group(RightF, RightB);
bumper b = bumper(Brain.ThreeWirePort.A);

void vexcodeInit(void) {
 L.setPosition(0, rotationUnits::deg);
 R.setPosition(0, rotationUnits::deg);
}