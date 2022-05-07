/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       anuppilla                                                 */
/*    Created:      Mon Mar 07 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    1, 10, 13, 19, 9
// Motor2               motor         2               
// Rotation15           rotation      15              
// Motor12              motor         12              
// PotentiometerV2A     potV2         A               
// DigitalOutC          digital_out   C               
// DigitalOutD          digital_out   D               
// Motor4               motor         4               
// Motor14              motor         14              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "iostream"

using namespace vex;

competition Competition;

int Brain_precision = 0, Console_precision = 0, Controller1_precision = 0;

float myVariable;

bool pressed;

// "when started" hat block
int whenStarted1() {
  pressed = true;
  //Drivetrain.setDriveVelocity(100.0, percent);
  //Drivetrain.setTurnVelocity(100.0, percent);
  Drivetrain.setStopping(coast);
  Motor12.setStopping(hold);
  Brain.Screen.print("Wilton Robotics");
  DigitalOutC.set(false);
  while (true) {
    Motor2.setVelocity(65.0, percent);
    if (Rotation15.angle() > 50.0 && PotentiometerV2A.angle(percent) > 62.0) {
      Motor2.spin(forward);
    }
    else {
      Motor2.stop();
    }
  wait(5, msec);
  }
  return 0;
}

const char* printToBrain_numberFormat() {
  // look at the current precision setting to find the format string
  switch(Brain_precision){
    case 0:  return "%.0f"; // 0 decimal places (1)
    case 1:  return "%.1f"; // 1 decimal place  (0.1)
    case 2:  return "%.2f"; // 2 decimal places (0.01)
    case 3:  return "%.3f"; // 3 decimal places (0.001)
    default: return "%f"; // use the print system default for everthing else
  }
}

void IntakeAutomate(){
  while (true) {
    Motor2.setVelocity(65.0, percent);
    if (Rotation15.angle() > 50.0 && PotentiometerV2A.angle(percent) > 50.0) {
      Motor2.spin(forward);
    }
    else {
      Motor2.stop();
    }
  wait(5, msec);
  }
}

void BackLiftDown(){
  Motor12.setMaxTorque(100.0, percent);
  Motor12.setVelocity(80.0, percent);
  while ((Rotation15.angle() > 33.0)) {
    Motor12.spin(reverse);
  wait(5, msec);
  }
  Motor2.setStopping(brake);
  Motor12.stop();
}

void BackLiftUp(){
  Motor12.setMaxTorque(100.0, percent);
  Motor12.setVelocity(80.0, percent);
  while ((Rotation15.angle() < 65.0 || Rotation15.position(degrees) > 31.0)) {
    Motor12.spin(forward);
    if (Rotation15.angle() > 68.0) {
      break;
    }
  wait(5, msec);
  }
  Motor12.stop();
}

void onevent_Controller1Axis1Changed_0() {
  double velo1 = 10.0;
  for(double i = 1.0; i < 10.0; i++){
    velo1 = velo1 + (i*i);
    Drivetrain.setTurnVelocity(velo1, percent);
    wait(50, msec);
  }
  Drivetrain.setTurnVelocity(100.0, percent);
  Brain.Screen.setCursor(2, 1);
  Brain.Screen.print(printToBrain_numberFormat(), static_cast<float>(Controller1.Axis1.position()));
}

void onevent_Controller1Axis3Changed_0() {
  double velo2 = 10.0;
  for(double j = 1.0; j < 8.0; j++){
    velo2 = j*j;
    Drivetrain.setDriveVelocity(velo2, percent);
    wait(0.1, seconds);
  }
  Drivetrain.setDriveVelocity(70.0, percent);
  Brain.Screen.setCursor(3, 1);
  Brain.Screen.print(printToBrain_numberFormat(), static_cast<float>(Controller1.Axis3.position()));
}

void onevent_Controller1ButtonX_pressed_0() {
  Motor2.spin(forward);
  Motor2.setVelocity(65.0, percent);
}

void onevent_Controller1ButtonY_pressed_0() {
  Motor2.stop();
}

void onevent_Controller1ButtonA_pressed_0() {
  Motor4.setMaxTorque(100.0, percent);
  Motor14.setMaxTorque(100.0, percent);
  Motor4.setStopping(hold);
  Motor14.setStopping(hold);
  Motor4.setVelocity(50.0, percent);
  Motor14.setVelocity(-50.0, percent);
  Motor4.spin(forward);
  Motor14.spin(forward);
  waitUntil((PotentiometerV2A.angle(percent) < 75));
  Motor4.stop();
  Motor14.stop();
}

void onevent_Controller1ButtonL2_pressed_0() {
  Motor12.setMaxTorque(100.0, percent);
  Motor12.setVelocity(80.0, percent);
  while ((Rotation15.angle() > 29.0)) {
    Motor12.spin(reverse);
  wait(5, msec);
  }
  Motor2.setStopping(brake);
  Motor12.stop();
}

void onevent_Controller1ButtonL1_pressed_0() {
  Motor12.setMaxTorque(100.0, percent);
  Motor12.setVelocity(80.0, percent);
  while ((Rotation15.angle() < 68.0 || Rotation15.position(degrees) > 31.0)) {
    Motor12.spin(forward);
    if (Rotation15.angle() > 70.0) {
      break;
    }
  wait(5, msec);
  }
  Motor12.stop();
}

void onevent_Controller1ButtonR1_pressed_0() {
  Motor4.setMaxTorque(100.0, percent);
  Motor14.setMaxTorque(100.0, percent);
  Motor4.setStopping(hold);
  Motor14.setStopping(hold);
  Motor4.setVelocity(-75.0, percent);
  Motor14.setVelocity(75.0, percent);
  Motor4.spin(forward);
  Motor14.spin(forward);
  waitUntil((PotentiometerV2A.angle(percent) > 77));
  Motor4.stop();
  Motor14.stop();
}

void FrontLiftUp(){
  Motor4.setMaxTorque(100.0, percent);
  Motor14.setMaxTorque(100.0, percent);
  Motor4.setStopping(hold);
  Motor14.setStopping(hold);
  Motor4.setVelocity(-75.0, percent);
  Motor14.setVelocity(75.0, percent);
  Motor4.spin(forward);
  Motor14.spin(forward);
  waitUntil((PotentiometerV2A.angle(percent) > 80));
  Motor4.stop();
  Motor14.stop();
}

void FrontLiftDown() {
   Motor4.setMaxTorque(100.0, percent);
  Motor14.setMaxTorque(100.0, percent);
  Motor4.setStopping(hold);
  Motor14.setStopping(hold);
  Motor4.setVelocity(75.0, percent);
  Motor14.setVelocity(-75.0, percent);
  Motor4.spin(forward);
  Motor14.spin(forward);
  waitUntil((PotentiometerV2A.angle(percent) < 56.5));
  Motor4.stop();
  Motor14.stop();
}

void onevent_Controller1ButtonR2_pressed_0() {
   Motor4.setMaxTorque(100.0, percent);
  Motor14.setMaxTorque(100.0, percent);
  Motor4.setStopping(hold);
  Motor14.setStopping(hold);
  Motor4.setVelocity(75.0, percent);
  Motor14.setVelocity(-75.0, percent);
  Motor4.spin(forward);
  Motor14.spin(forward);
  waitUntil((PotentiometerV2A.angle(percent) < 56.5));
  Motor4.stop();
  Motor14.stop();
}

void onevent_Controller1ButtonRight_pressed_0() {
  DigitalOutC.set(false);
}

void onevent_Controller1ButtonUp_pressed_0() {
  DigitalOutC.set(true);
}

int ondriver_drivercontrol_0() {
  Controller1.Axis1.changed(onevent_Controller1Axis1Changed_0);
  Controller1.Axis3.changed(onevent_Controller1Axis3Changed_0);
  Controller1.ButtonX.pressed(onevent_Controller1ButtonX_pressed_0);
  Controller1.ButtonY.pressed(onevent_Controller1ButtonY_pressed_0);
  Controller1.ButtonA.pressed(onevent_Controller1ButtonA_pressed_0);
  Controller1.ButtonL2.pressed(onevent_Controller1ButtonL2_pressed_0);
  Controller1.ButtonL1.pressed(onevent_Controller1ButtonL1_pressed_0);
  Controller1.ButtonR1.pressed(onevent_Controller1ButtonR1_pressed_0);
  Controller1.ButtonR2.pressed(onevent_Controller1ButtonR2_pressed_0);
  Controller1.ButtonRight.pressed(onevent_Controller1ButtonRight_pressed_0);
  Controller1.ButtonUp.pressed(onevent_Controller1ButtonUp_pressed_0);
  return 0;
}

void VEXcode_driver_task() {
  // Start the driver control tasks....
  vex::task drive0(ondriver_drivercontrol_0);
  while(Competition.isDriverControl() && Competition.isEnabled()) {this_thread::sleep_for(10);}
  drive0.stop();
  return;
}

void VEXcode_auton_task() {
  // Start the auton control tasks....
  return;
}

int main() {
  vexcodeInit();

  vex::competition::bStopTasksBetweenModes = false;
  Competition.autonomous(VEXcode_auton_task);
  Competition.drivercontrol(VEXcode_driver_task);

  // register event handlers
  Controller1.Axis1.changed(onevent_Controller1Axis1Changed_0);
  Controller1.Axis3.changed(onevent_Controller1Axis3Changed_0);
  Controller1.ButtonX.pressed(onevent_Controller1ButtonX_pressed_0);
  Controller1.ButtonY.pressed(onevent_Controller1ButtonY_pressed_0);
  Controller1.ButtonA.pressed(onevent_Controller1ButtonA_pressed_0);
  Controller1.ButtonL2.pressed(onevent_Controller1ButtonL2_pressed_0);
  Controller1.ButtonL1.pressed(onevent_Controller1ButtonL1_pressed_0);
  Controller1.ButtonR1.pressed(onevent_Controller1ButtonR1_pressed_0);
  Controller1.ButtonR2.pressed(onevent_Controller1ButtonR2_pressed_0);
  Controller1.ButtonRight.pressed(onevent_Controller1ButtonRight_pressed_0);
  Controller1.ButtonUp.pressed(onevent_Controller1ButtonUp_pressed_0);

  wait(15, msec);
  // post event registration

  // set default print color to black
  printf("\033[30m");

  // wait for rotation sensor to fully initialize
  wait(30, msec);

  whenStarted1();
}
