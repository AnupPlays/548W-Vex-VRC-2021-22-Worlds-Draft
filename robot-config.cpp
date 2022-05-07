#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor leftMotorA = motor(PORT1, ratio6_1, false);
motor leftMotorB = motor(PORT10, ratio6_1, false);
motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB);
motor rightMotorA = motor(PORT13, ratio6_1, true);
motor rightMotorB = motor(PORT19, ratio6_1, true);
motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB);
inertial DrivetrainInertial = inertial(PORT9);
smartdrive Drivetrain = smartdrive(LeftDriveSmart, RightDriveSmart, DrivetrainInertial, 319.19, 320, 444.5, mm, 0.42857142857142855);
motor Motor2 = motor(PORT2, ratio6_1, false);
rotation Rotation15 = rotation(PORT15, false);
motor Motor12 = motor(PORT12, ratio36_1, true);
potV2 PotentiometerV2A = potV2(Brain.ThreeWirePort.A);
digital_out DigitalOutC = digital_out(Brain.ThreeWirePort.C);
digital_out DigitalOutD = digital_out(Brain.ThreeWirePort.D);
motor Motor4 = motor(PORT4, ratio36_1, false);
motor Motor14 = motor(PORT14, ratio36_1, false);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  Brain.Screen.print("Device initialization...");
  Brain.Screen.setCursor(2, 1);
  // calibrate the drivetrain Inertial
  wait(200, msec);
  DrivetrainInertial.calibrate();
  Brain.Screen.print("Calibrating Inertial for Drivetrain");
  // wait for the Inertial calibration process to finish
  while (DrivetrainInertial.isCalibrating()) {
    wait(25, msec);
  }
  // reset the screen now that the calibration is complete
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1,1);
  wait(50, msec);
  Brain.Screen.clearScreen();
}
