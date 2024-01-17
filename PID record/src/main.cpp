#include "main.h"



/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {

}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	while (1){
		int Ch1 = master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
		int Ch3 = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
		int Ch4 = master.get_analog(E_CONTROLLER_ANALOG_LEFT_X);
		FL = -(Ch3+Ch1+Ch4)/100*127;
		BL = -(Ch3+Ch1-Ch4)/100*127;
		FR = -(Ch1-Ch3+Ch4)/100*127;
		BR = -(Ch1-Ch3-Ch4)/100*127;

	 if(master.get_digital(E_CONTROLLER_DIGITAL_R1)) {
		 intakeR = 127;
		 intakeL = 127;
	 } else if(master.get_digital(E_CONTROLLER_DIGITAL_R2)) {
		 intakeR = -127;
		 intakeL = -127;
	 } else {
		 intakeR = 0;
		 intakeL = 0;
	 }
	 if(master.get_digital(E_CONTROLLER_DIGITAL_L1)) {
		 rollerH = -127;
		 rollerL = -127;
	 }else if(master.get_digital(E_CONTROLLER_DIGITAL_L2)) {
		 rollerH = 127;
		 rollerL = 127;
	 } else {
		 rollerH = 0;
		 rollerL = 0;
	 }
	}
}
