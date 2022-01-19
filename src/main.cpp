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
// Drivetrain           drivetrain    7, 9, 10, 11    
// ---- END VEXCODE CONFIGURED DEVICES ----
           
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

  BackLift.setVelocity(x,percent);
  BackLift.setMaxTorque(x,percent);
  //FrontLeft.setVelocity(x,percent);
  //FrontRight.setVelocity(x,percent);
  //BackLeft.setVelocity(x,percent);
  //BackRight.setVelocity(x,percent);
  Intake.setVelocity(x,percent);
  MobileLift.setPosition(0, degrees);
  
  MobileLift.setPosition(0, turns);

}
void drivefunctions(std::string dir, double x) {
  if (dir == "rev") {
    FrontLeft.spin(forward);
    FrontRight.spin(forward);
    BackRight.spin(forward);
    BackLeft.spin(forward);
    wait (x, sec);
  }
  if (dir == "fwd") {
    FrontRight.spin(reverse);
    FrontLeft.spin(reverse);
    BackLeft.spin(reverse);
    BackRight.spin(reverse);
    wait (x, sec);

  }
  if (dir == "rht") {
    FrontRight.spin(reverse);
    FrontLeft.spin(forward);
    BackRight.spin(reverse);
    BackLeft.spin(forward);
    wait (x, sec);
  }
  if (dir == "lft") {
    FrontRight.spin(forward);
    FrontLeft.spin(reverse);
    BackRight.spin(forward);
    BackLeft.spin(reverse);
    wait (x, sec);
  }
}
void Stop (std::string option) {
  if (option == "drivetrain") {
  FrontLeft.stop();
  FrontRight.stop();
  BackRight.stop();
  BackLeft.stop();
  }
  if (option == "frontlift") {
    MobileLift.stop();
    
  }
  if (option == "backlift") {
    BackLift.stop();
    BackLift.setStopping(hold);
  }
  if (option == "intake") {
    Intake.stop();
  }
}

/*
void TestFrontLift (std::string dir, double x) {
  if (dir == "up") {
      MobileLift.spinFor(forward, x*5, degrees);
      MobileLift2.spinFor(forward, x*5, degrees);
  }
  if (dir == "down") {
    MobileLift.spinFor(reverse, x*5, degrees);
    MobileLift2.spinFor(reverse, x*5, degrees);
  }
}
void TestBakLift (std::string dir, double x) {
  if (dir == "up") {
    MobileLift.spinFor(reverse, x*5, degrees);
    MobileLift2.spinFor(reverse, x*5, degrees);
  }
  if (dir == "down") {
    MobileLift.spinFor(forward, x*5, degrees);
    MobileLift2.spinFor(forward, x*5, degrees);
  }
}
*/
void BakLift (std::string dir, double x) {
  if (dir == "up") {
    BackLift.spin(reverse);
    wait (x, sec);
  }
  if (dir == "down") {
    BackLift.spin(forward);
    wait (x, sec);
  }
}
int drivetype = 1;

void changedrive () {
  if (drivetype == 1) {
    drivetype = 2;
  }
  if (drivetype == 2) {
    drivetype = 1;
  }
}
void pre_auton(void) {
  vexcodeInit();
  
  // Initializing Robot Configuration. DO NOT REMOVE!
  
  //-------------------------------------------------------------------------
  // DRIVE FUNCTIONS : drivefunctions(direction, waittime) [fwd, rev, lft, rht]
  // STOP FUNCTIONS : Stop(option); [drivetrain, frontlift, backlift, intake]
  // FRONT LIFT FUNCTIONS : FrontLift(dir, waittime) [up, down]
  // BAK LIFT FUNCTIONS : BakLift(dir, waittime) [up, down]
  //-------------------------------------------------------------------------



  
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
  setVelocity(100);
  BackLift.spinFor(forward, 800, degrees, 100, rpm, false);
  Drivetrain.driveFor(reverse, 10, inches, 200, rpm);
  BackLift.spinFor(reverse, 200, degrees, 100, rpm);
  Drivetrain.turnFor(left, 90, degrees);
  Drivetrain.driveFor(reverse, 5, inches, 200, rpm);

  
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
bool state = false;
bool last = false;

void usercontrol(void) {
  setVelocity(100);
  // User control code here, inside the loop
  while (true) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.
    // Mobile Lift Coding
  if (Controller1.ButtonL1.pressing()) {
  MobileLift.spin(reverse);

  }
  if (Controller1.ButtonL2.pressing()) {
  MobileLift.spin(forward);

  }
  if (!Controller1.ButtonL1.pressing() && !Controller1.ButtonL2.pressing()) {
  MobileLift.stop();
  
  MobileLift.setStopping(hold);

  }
 
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
 
  FrontLeft.spin(vex::directionType::fwd, Controller1.Axis3.position(), vex::velocityUnits::pct);
  FrontRight.spin(vex::directionType::fwd, Controller1.Axis2.position(), vex::velocityUnits::pct);
  BackLeft.spin(vex::directionType::fwd, Controller1.Axis3.position(), vex::velocityUnits::pct);
  BackRight.spin(vex::directionType::fwd, Controller1.Axis2.position(), vex::velocityUnits::pct);
   if(Controller1.ButtonY.pressing() && !last) {
      state = !state;
      last = true;
   } else if(!Controller1.ButtonY.pressing()) {
      last = false;
   }

   if(state) {
    if ((Controller1.Axis2.position() < 7) && (Controller1.Axis3.position() < 7) && (Controller1.Axis2.position() > -7) && (Controller1.Axis3.position() > -7)) {
      Stop("drivetrain");
      FrontRight.setStopping(hold); 
      FrontLeft.setStopping(hold);
      BackRight.setStopping(hold);
      BackLeft.setStopping(hold);
    }
   } else {
      if ((Controller1.Axis2.position() < 7) && (Controller1.Axis3.position() < 7) && (Controller1.Axis2.position() > -7) && (Controller1.Axis3.position() > -7)) {
      Stop("drivetrain");
      FrontRight.setStopping(coast); 
      FrontLeft.setStopping(coast);
      BackRight.setStopping(coast);
      BackLeft.setStopping(coast);
      }
   }

    wait(10, msec); // Sleep the task for a short amount of time to 
  }                  // prevent wasted resources.
}
// Main will set up the competition functions and callbacks.
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
