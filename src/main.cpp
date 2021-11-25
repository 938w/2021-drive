// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// FrontLeft            motor         1               
// FrontRight           motor         2               
// BackLeft             motor         3               
// BackRight            motor         4               
// MobileLift           motor         5               
// Intake               motor         6               
// Controller1          controller                    
// MobileLift2          motor         21              
// BackLift             motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// FrontLeft            motor         1               
// FrontRight           motor         2               
// BackLeft             motor         3               
// BackRight            motor         4               
// MobileLift           motor         5               
// Intake               motor         6               
// Controller1          controller                    
// MobileLift2          motor         21              
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// FrontLeft            motor         1               
// FrontRight           motor         2               
// BackLeft             motor         3               
// BackRight            motor         4               
// MobileLift           motor         5               
// Intake               motor         6               
// Controller1          controller                    
// MobileLift2          motor         7               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// FrontLeft            motor         1               
// FrontRight           motor         2               
// BackLeft             motor         3               
// BackRight            motor         4               
// MobileLift           motor         5               
// Intake               motor         6               
// Controller1          controller                    
// MobileLift2          motor         7               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// FrontLeft            motor         1               
// FrontRight           motor         2               
// BackLeft             motor         3               
// BackRight            motor         4               
// MobileLift           motor         5               
// Intake               motor         6               
// Controller1          controller                    
// MobileLift2          motor         7               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// FrontLeft            motor         1               
// FrontRight           motor         2               
// BackLeft             motor         3               
// BackRight            motor         4               
// MobileLift           motor         5               
// Intake               motor         6               
// Controller1          controller                    
// MobileLift2          motor         7               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// FrontLeft            motor         1               
// FrontRight           motor         2               
// BackLeft             motor         3               
// BackRight            motor         4               
// MobileLift           motor         5               
// Intake               motor         6               
// Controller1          controller                    
// MobileLift2          motor         7               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// FrontLeft            motor         1               
// FrontRight           motor         2               
// BackLeft             motor         3               
// BackRight            motor         4               
// MobileLift           motor         5               
// Intake               motor         6               
// Controller1          controller                    
// MobileLift2          motor         7               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// FrontLeft            motor         1               
// FrontRight           motor         2               
// BackLeft             motor         3               
// BackRight            motor         4               
// MobileLift           motor         5               
// Intake               motor         6               
// Controller1          controller                    
// MobileLift2          motor         7               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// FrontLeft            motor         1               
// FrontRight           motor         2               
// BackLeft             motor         3               
// BackRight            motor         4               
// MobileLift           motor         5               
// Intake               motor         6               
// Controller1          controller                    
// MobileLift2          motor         7               
// ---- END VEXCODE CONFIGURED DEVICES ----
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// FrontLeft            motor         1               
// FrontRight           motor         2               
// BackLeft             motor         3               
// BackRight            motor         4               
// MobileLift           motor         5               
// Intake               motor         6               
// Controller1          controller                    
// MobileLift2          motor         7               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void setVelocity(int x) {
 MobileLift.setVelocity(x,percent);
  MobileLift.setMaxTorque(x,percent);
  MobileLift2.setVelocity(x,percent);
  MobileLift2.setMaxTorque(x,percent);
  BackLift.setVelocity(x,percent);
  BackLift.setMaxTorque(x,percent);
  FrontLeft.setVelocity(x,percent);
  FrontRight.setVelocity(x,percent);
  BackLeft.setVelocity(x,percent);
  BackRight.setVelocity(x,percent);
  Intake.setVelocity(x,percent);
  MobileLift.setPosition(0, degrees);
  MobileLift2.setPosition(0,degrees);
  MobileLift.setPosition(0, turns);
  MobileLift2.setPosition(0,turns);
}

void DriveTrainFunctions(int y, double x) {
  if (int y = 1) {
    FrontLeft.spin(forward);
    FrontRight.spin(forward);
    BackRight.spin(forward);
    BackLeft.spin(forward);
    wait (x, sec);
  }
  if (int y = 2) {
    FrontRight.spin(reverse);
    FrontLeft.spin(reverse);
    BackLeft.spin(reverse);
    BackRight.spin(reverse);
    wait (x, sec);
  }
  if (int y = 3) {
    FrontRight.spin(forward);
    FrontLeft.spin(reverse);
    BackRight.spin(forward);
    BackLeft.spin(reverse);
    wait (x, sec);
  }
  if (int y = 3) {
    FrontRight.spin(reverse);
    FrontLeft.spin(forward);
    BackRight.spin(reverse);
    BackLeft.spin(forward);
    wait (x, sec);
  }
}

void Stop (int y) {
  if (int y = 1) {
  FrontLeft.stop();
  FrontRight.stop();
  BackRight.stop();
  BackLeft.stop();
  }
  if (int y = 2) {
    MobileLift.stop();
    MobileLift2.stop();
  }
  if (int y = 3) {
    Intake.stop();
  }
}
void MobileLiftFunctions (int y, double x) {
  if (int y = 1) {
    MobileLift.spin(forward);
    MobileLift2.spin(forward);
    wait (x, sec);
  }
  if (int y = 2) {
    MobileLift.spin(reverse);
    MobileLift2.spin(reverse);
    wait (x, sec);
  }
}

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  // Motor Velocity Percent 
  setVelocity(100);
  //Move forward so won't crash into wall when turning
  DriveTrainFunctions(1, 0.5);
  Stop(1);
  //Turn to face goal and ramp
  DriveTrainFunctions(1, 1);
  Stop(1);
  //Lower lift into position
  MobileLiftFunctions (2,1.5);
  Stop (2);
  //Pick up goal and go up on ramp 
  MobileLift.spin(forward);
  MobileLift2.spin(forward);
  FrontLeft.spin(forward);
  FrontRight.spin(forward);
  BackLeft.spin(forward);
  BackRight.spin(forward);
  wait (0.2, sec);
  MobileLift.stop();
  MobileLift2.stop();
  wait (0.5, sec);
  FrontLeft.stop();
  FrontRight.stop();
  BackLeft.stop();
  BackRight.stop();
  
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
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

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.
    //Mobile Lift Coding
 if (Controller1.ButtonL1.pressing()) {
 MobileLift.spin(forward);
 MobileLift2.spin(forward);
 }
 
 if (Controller1.ButtonL2.pressing()) {
 MobileLift.spin(reverse);
 MobileLift2.spin(reverse);
 }
 
 if (!Controller1.ButtonL1.pressing() && !Controller1.ButtonL2.pressing()) {
 MobileLift.stop();
 MobileLift2.stop();
  if (MobileLift.position(degrees) > -300) {
    MobileLift.setStopping(hold);
    MobileLift2.setStopping(hold);
  }
 }
 Brain.Screen.clearScreen();
 Brain.Screen.print(MobileLift.position(degrees)+100);
 if (Controller1.ButtonR1.pressing()) {
 BackLift.spin(reverse);
 }
 
 if (Controller1.ButtonR2.pressing()) {
 BackLift.spin(forward);
 }
 
 if (!Controller1.ButtonR1.pressing() && !Controller1.ButtonR2.pressing()) {
BackLift.stop();
BackLift.setStopping(hold);
 }

 if (!Controller1.ButtonUp.pressing()) {
 Intake.spin(forward);
 }
 
 if (!Controller1.ButtonDown.pressing()) {
 Intake.spin(reverse); 
 }
 
 if (!Controller1.ButtonUp.pressing() && !Controller1.ButtonDown.pressing()) {
 Intake.stop();
 }
    FrontLeft.spin(vex::directionType::rev, Controller1.Axis3.position(), vex::velocityUnits::pct);
    FrontRight.spin(vex::directionType::rev, Controller1.Axis2.position(), vex::velocityUnits::pct);
    BackLeft.spin(vex::directionType::rev, Controller1.Axis3.position(), vex::velocityUnits::pct);
    BackRight.spin(vex::directionType::rev, Controller1.Axis2.position(), vex::velocityUnits::pct);
    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(10, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
