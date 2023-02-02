
#include "cghs.h"

/**
 *
 *	Autonomous Routines
 *	- called by auton selector
 *	- given reference to chassis as paramater
 *
 */

namespace cghs::auton {

	/**
	 *
	 *	@brief Skills Autonomous Routine
	 *
		@details Gets ...
	 *
	 *	@param chassis  Reference to Chassis object
	 *
	 */
	void skills_Auto(Drive& chassis) {

		// Get Roller 1
		chassis.set_drive_pid(-4, 0.5 * 127.0, false);
		chassis.wait_drive();
		rollerForward(true, SPEED_ROLLER_AUTO);
		pros::delay(200);
		rollerForward(false, 0);
		chassis.set_drive_pid(8, 0.5 * 127.0, false);
		chassis.wait_drive();


		chassis.set_turn_pid(-45, SPEED_TURN_AUTO);
		chassis.wait_drive();

		intakeToggle(true);
		chassis.set_drive_pid(20, SPEED_DRIVE_AUTO);
		chassis.wait_drive();

		chassis.set_turn_pid(90, SPEED_TURN_AUTO);
		chassis.wait_drive();

		// Get Roller 2
		chassis.set_drive_pid(-9, 0.5 * 127.0, false);
		chassis.wait_drive();
		intakeToggle(false);
		rollerForward(true, SPEED_ROLLER_AUTO);
		pros::delay(200);
		rollerForward(false, 0);
		chassis.set_drive_pid(11, 0.5 * 127.0, false);
		chassis.wait_drive();

		chassis.set_turn_pid(0, SPEED_TURN_AUTO);
		chassis.wait_drive();

		chassis.set_drive_pid(46, SPEED_DRIVE_AUTO);
		chassis.wait_drive();

		chassis.set_turn_pid(-10, SPEED_TURN_AUTO);
		chassis.wait_drive();

		// Shoot First 3
		launchDisks_Auto(4500, 85.0);

		chassis.set_turn_pid(0, SPEED_TURN_AUTO);
		chassis.wait_drive();

		chassis.set_drive_pid(-14, SPEED_DRIVE_AUTO);
		chassis.wait_drive();

		intakeToggle(true);
		chassis.set_turn_pid(90, SPEED_TURN_AUTO);
		chassis.wait_drive();

		chassis.set_drive_pid(18, SPEED_DRIVE_AUTO);
		chassis.wait_drive();

		chassis.set_turn_pid(45, SPEED_TURN_AUTO);
		chassis.wait_drive();

		chassis.set_drive_pid(28, SPEED_DRIVE_AUTO);
		chassis.wait_drive();

		chassis.set_turn_pid(-45, SPEED_TURN_AUTO);
		chassis.wait_drive();

		// Shoot Second Three
		pros::delay(1000);
		intakeToggle(false);
		launchDisks_Auto(4000, 90.0);

		chassis.set_turn_pid(45, SPEED_TURN_AUTO);
		chassis.wait_drive();

		intakeToggle(true);
		chassis.set_drive_pid(64, SPEED_DRIVE_AUTO);
		chassis.wait_until(34);
		chassis.set_max_speed(SPEED_DRIVE_AUTO_INTAKE);
		chassis.wait_drive();

		chassis.set_turn_pid(-90, SPEED_TURN_AUTO);
		chassis.wait_drive();

		chassis.set_drive_pid(40, SPEED_DRIVE_AUTO_INTAKE);
		chassis.wait_drive();

		// Shoot Third Three
		intakeToggle(false);
		launchDisks_Auto(4000, SPEED_LAUNCHER);

		chassis.set_drive_pid(-52, SPEED_DRIVE_AUTO_INTAKE);
		chassis.wait_drive();

		chassis.set_turn_pid(-180, SPEED_TURN_AUTO);
		chassis.wait_drive();

		chassis.set_drive_pid(-6, 0.5 * 127.0, false);
		chassis.wait_drive();
		rollerForward(true, SPEED_ROLLER_AUTO);
		pros::delay(200);
		rollerForward(false, 0);
		chassis.set_drive_pid(8, 0.5 * 127.0, false);
		chassis.wait_drive();
	}

	/**
	 *	@brief Three Side Autonomous Routine
	 *
	 *	@details
	 *		Gets 1 roller, shoots two in low goal,
	 *	 	collects 3 and then fires three into highgoal
	 *
	 *	@param chassis  Reference to Chassis object
	 *
	 */
	void threeSide_Auto(Drive& chassis) {

		// Get Roller
		chassis.set_drive_pid(-4, 0.5 * 127.0, false);
		chassis.wait_drive();
		rollerForward(true, SPEED_ROLLER_AUTO);
		pros::delay(250);
		rollerForward(false, 0);
		chassis.set_drive_pid(4, 0.5 * 127.0, false);
		chassis.wait_drive();

		// Turn 90 Degrees and get 2 Low Goals
		chassis.set_turn_pid(90, SPEED_TURN_AUTO);
		chassis.wait_drive();
		chassis.set_drive_pid(4, SPEED_DRIVE_AUTO);
		chassis.wait_drive();
		launchDisksShort_Auto(2000, 80);

		// Turn 45 Degrees to the Right
		chassis.set_turn_pid(45, SPEED_TURN_AUTO);
		chassis.wait_drive();

		// Charge Forward and push disks
		chassis.set_drive_pid(65, SPEED_DRIVE_AUTO, true);
		chassis.wait_until(36);
		intakeToggle(true);
		chassis.set_max_speed(SPEED_DRIVE_AUTO_INTAKE);
		chassis.wait_drive();
		intakeToggle(false);

		intakeReverse(true);
		pros::delay(250);
		intakeReverse(false);

		intakeToggle(true);
		chassis.set_turn_pid(-47, SPEED_TURN_AUTO);
		chassis.wait_drive();

		chassis.set_drive_pid(4, SPEED_DRIVE_AUTO, true);
		chassis.wait_drive();
		intakeToggle(false);

		launchDisksLong_Auto(8000);
	}

	/**
	 *	@brief Two Side Autonomous Routine
	 *
	 *	@details
	 *		Gets 1 roller, shoots two in low goal,
	 *	 	collects 3 and then fires three into highgoal
	 *
	 *	@param chassis  Reference to Chassis object
	 *
	 */
	void twoSide_Auto(Drive& chassis) {

		// Fire two low goals
		launchDisksShort_Auto(1500, 100);

		chassis.set_drive_pid(-24, SPEED_DRIVE_AUTO);
		chassis.wait_drive();
		chassis.set_turn_pid(90, SPEED_TURN_AUTO);
		chassis.wait_drive();
		chassis.set_drive_pid(-12, SPEED_DRIVE_AUTO);
		chassis.wait_drive();

		rollerForward(true, SPEED_ROLLER_AUTO);
		pros::delay(100);
		rollerForward(false, 0);

		chassis.set_drive_pid(2, SPEED_DRIVE_AUTO);
		chassis.wait_drive();

		chassis.set_turn_pid(45, SPEED_TURN_AUTO);
		chassis.wait_drive();

		intakeToggle(true);
		chassis.set_drive_pid(74, SPEED_DRIVE_AUTO);
		chassis.wait_drive();
		chassis.set_drive_pid(10, SPEED_DRIVE_AUTO);
		chassis.wait_drive();
		chassis.set_drive_pid(0, SPEED_DRIVE_AUTO);
		chassis.wait_drive();

		chassis.set_turn_pid(133, SPEED_TURN_AUTO);
		chassis.wait_drive();

		chassis.set_drive_pid(6, SPEED_DRIVE_AUTO);
		chassis.wait_drive();

		intakeToggle(false);
		launchDisksLong_Auto(8000);
	}

	/**
	 *	@brief The Whole Shebang Autonomous Routine
	 *
	 *	@details
	 *		Gets 2 roller, shoots two in low goal,
	 *	 	collects 3 and then fires three into highgoal
	 *
	 *	@param chassis  Reference to Chassis object
	 *
	 */
	void theWholeShebang_Auto(Drive& chassis) {
		launchDisks_Auto(2, 80);
	}

	/**
	 *	@brief Null Autonomous Routine
	 *
	 *	@details
	 *		Does Nothing
	 *
	 *	@param chassis  Reference to Chassis object
	 *
	 */
	void null_Auto(Drive& chassis) {
		// Do Nothing
	}
}

/**
 *
 *	Miscellaneous Auton Functions
 *
 */
namespace cghs::auton {

	// 	Launch Disks Autonomously
	void launchDisks_Auto(float time, float speed) {
		float currTime = 0;
		while (currTime < time) {
			launchDisks(true, speed);

			currTime += ez::util::DELAY_TIME;
			pros::delay(ez::util::DELAY_TIME);
		}

		launchDisks(false, 0);
	}

	//	Launch disks long distance autonomously
	void launchDisksLong_Auto(float time) {
		float currTime = 0;
		while (currTime < time) {
			launchDisksLong(cghs::SPEED_LAUNCHER_LONG);

			currTime += ez::util::DELAY_TIME;
			pros::delay(ez::util::DELAY_TIME);
		}

		launchDisks(false, 0);
	}

	//	Launch disks short distance autonomously
	void launchDisksShort_Auto(float time, float speed) {
		float currTime = 0;
		while (currTime < time) {
			launchDisksShort(speed);

			currTime += ez::util::DELAY_TIME;
			pros::delay(ez::util::DELAY_TIME);
		}

		launchDisks(false, 0);
	}

	int autonIndex = 0;

	// Updates auton selection and prints to screen
	void updateAutonSelection() {
		if (autonIndex < 0)
		{
			autonIndex += numAutons;
		}
		if (autonIndex >= numAutons)
		{
			autonIndex -= numAutons;
		}

		std::string str = autonArray[autonIndex];

		master.set_text(2, 0, str.c_str());

		printf("\n Auton Changed To: %s", str.c_str());
	}

	void checkAutonButtons() {

		if (master.get_digital_new_press(BUTTON_AUTON_INCREASE))
		{
			autonIndex++;
			updateAutonSelection();
		}
		if (master.get_digital_new_press(BUTTON_AUTON_DECREASE))
		{
			autonIndex--;
			updateAutonSelection();
		}
	}
}