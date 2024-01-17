#include "main.h"
#include <fstream>
#include <iostream>

pros::Controller master (E_CONTROLLER_MASTER);

pros::Motor FR (FRPort, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
pros::Motor FL (FLPort, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
pros::Motor BR (BRPort, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
pros::Motor BL (BLPort, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
pros::Motor intakeL (intakeLPort, E_MOTOR_GEARSET_18, true , E_MOTOR_ENCODER_DEGREES);
pros::Motor intakeR (intakeRPort, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
pros::Motor rollerL (rollerLPort, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
pros::Motor rollerH (rollerHPort, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);

vector<vector<int>> vect( 15000 , vector<int> (8, 0));
Driver driver;
void on_center_button() {

}


/*
void tokenize(string str, char delim,
            vector<string> out)
{
    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
    {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
}

*/


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	Task recorder(record, (void*)"PROS", //Initialize multitask function
    TASK_PRIORITY_DEFAULT,
    TASK_STACK_DEPTH_DEFAULT,
    "Record auto"
  );


	/* FILE*file = fopen("vex/skills/15s.dat", "r");
	//read from files
  for (int i = 0; i < 15000; i++){
			 char temp[8];
			 fgets(temp, 8, file);
			 for (int j = 0 ; j < 8; j++){
				 vect [i][j] = temp [j];
			 }
	}
	fclose (file);
  */
	vect = read(vect);

}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {

}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {

	FR.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	BR.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	FL.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	BL.set_brake_mode(E_MOTOR_BRAKE_HOLD);

	intakeR.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	intakeL.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	rollerL.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	rollerH.set_brake_mode(E_MOTOR_BRAKE_HOLD);


}

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
void autonomous() {
 // read from array
 /* for (int i = 0; i < 15000; i ++){
		 FR.move_voltage(vect[i][0]);
		 FL.move_voltage(vect[i][1]);
		 BR.move_voltage(vect[i][2]);
		 BL.move_voltage(vect[i][3]);
		 intakeL.move_voltage(vect[i][4]);
		 intakeR.move_voltage(vect[i][5]);
		 rollerL.move_voltage(vect[i][6]);
		 rollerH.move_voltage(vect[i][7]);
		 pros::delay(1);
 }
*/
if (!pros::usd::is_installed()){
	master.clear();
	master.set_text(5, 5, "please plug in the SD card!");
}
}

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
 while (true){
	  /* int Ch1 = master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
    int Ch3 = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
    int Ch4 = master.get_analog(E_CONTROLLER_ANALOG_LEFT_X);
    FL = -(Ch3+Ch1+Ch4)/100*127;
    BL = -(Ch3+Ch1-Ch4)/100*127;
    FR = -(Ch1-Ch3+Ch4)/100*127;
    BR = -(Ch1-Ch3-Ch4)/100*127;
*/
		driver.drive();
		if (master.get_digital(E_CONTROLLER_DIGITAL_R1)){
			driver.intakeAndscore (master.get_digital(E_CONTROLLER_DIGITAL_R1));
		}
		else if (master.get_digital(E_CONTROLLER_DIGITAL_R2)){
			driver.outtakeAnddescore(master.get_digital(E_CONTROLLER_DIGITAL_R2));
		}
		else if (master.get_digital(E_CONTROLLER_DIGITAL_L1)){
			driver.intakeAnddescore(master.get_digital(E_CONTROLLER_DIGITAL_L1));
		}
		else if (master.get_digital(E_CONTROLLER_DIGITAL_B)){
			driver.descore(master.get_digital(E_CONTROLLER_DIGITAL_B));
		}


		/*
		if(master.get_digital(E_CONTROLLER_DIGITAL_R1)) {
			intakeL = 127;
		  intakeR = 127;
		  rollerH = 127;
		  rollerL = 127;
		} else if(master.get_digital(E_CONTROLLER_DIGITAL_R2)) {
			intakeL = -127;
		  intakeR = 127;
		  rollerH = -127;
		  rollerL = -127;
		}

	 else	if(master.get_digital(E_CONTROLLER_DIGITAL_L1)) {
			intakeL = 127;
		  intakeR = -127;
		  rollerH = -127;
		  rollerL = 127;
		}else if(master.get_digital(E_CONTROLLER_DIGITAL_L2)) {
			rollerH = 127;
			rollerL = 127;
		}
		else {
			intakeR = 0;
			intakeL = 0;
			rollerH= 0;
			rollerL= 0;
		}
		*/
		pros::delay(1); // don't know if neccesary
 }
}
