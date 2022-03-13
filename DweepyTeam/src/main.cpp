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
// Drivetrain           drivetrain    15, 16, 17, 18, 9
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
  MobileLift.setVelocity(x, percent);
  MobileLift.setPosition(0, degrees);
  MobileLift.setPosition(0, turns);
  BackLift.setVelocity(x, percent);
  BackLift.setPosition(0, degrees);  
  BackLift.setPosition(0, turns); 
}
void DriveVelocity(int x) {
  FrontLeft.setVelocity(x, percent);
  FrontRight.setVelocity(x, percent);
  BackLeft.setVelocity(x, percent);
  BackRight.setVelocity(x, percent); 
}
/*void drivefunctions(std::string dir, double x) {
  if (dir == "rev") {
    FrontLeft.spin(forward);
    FrontRight.spin(forward);
    BackRight.spin(forward);
    BackLeft.spin(forward);
    wait(x, sec);
  }
  if (dir == "fwd") {
    FrontRight.spin(reverse);
    FrontLeft.spin(reverse);
    BackLeft.spin(reverse);
    BackRight.spin(reverse);
    wait(x, sec);
  }
  if (dir == "rht") {
    FrontRight.spin(reverse);
    FrontLeft.spin(forward);
    BackRight.spin(reverse);
    BackLeft.spin(forward);
    wait(x, sec);
  }
  if (dir == "lft") {
    FrontRight.spin(forward);
    FrontLeft.spin(reverse);
    BackRight.spin(forward);
    BackLeft.spin(reverse);
    wait(x, sec);
  }
}
void Stop(std::string option) {
  if (option == "drivetrain") {
    FrontLeft.stop();
    FrontRight.stop();
    BackRight.stop();
    BackLeft.stop();
  }
  if (option == "frontlift") {
    MobileLift.stop();
  }
}
void FrontLift(std::string dir, double x) {
  if (dir == "up") {
    MobileLift.spin(forward);
    wait(x, sec);
  }
  if (dir == "down") {
    MobileLift.spin(reverse);
    wait(x, sec);
  }
}
*/
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
int drivetype = 1;

void changedrive() {
  if (drivetype == 1) {
    drivetype = 2;
  }
  if (drivetype == 2) {
    drivetype = 1;
  }
}
void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
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
  Drivetrain.setDriveVelocity(100, percent); 
  setVelocity(100);
  timer t1;
  //Neutral goal rush
  dig1.set(true);
  t1.reset(); 
  Drivetrain.drive(reverse); 
  wait (1.2, sec);
  Drivetrain.stop(); 
  dig1.set(false);
  Controller1.Screen.newLine();
  Controller1.Screen.print(t1.time(sec));
  t1.reset();
  //High branche
  Drivetrain.drive(forward, 200, rpm);
  wait (0.75, sec); 
  Drivetrain.stop();
  BackLift.spinFor(reverse, 150, degrees, false); 
  MobileLift.spinFor(reverse, 515, degrees, false); 
  //High branche turn
  //------------------------------------
  Drivetrain.turn(left);
  wait (1.7, sec);
  //------------------------------------ 
  Drivetrain.stop();
  Drivetrain.setDriveVelocity(85, percent); 
  Drivetrain.driveFor(38, inches, 100, rpm); 
  Drivetrain.stop();
  MobileLift.spinFor(forward, 250, degrees, 75, rpm);
  Drivetrain.drive(reverse, 200, rpm);
  wait (0.5, sec);  
  Drivetrain.stop();
  Drivetrain.turn(left);
  wait (0.25, sec); 
  Drivetrain.driveFor(forward, 10, inches);  
  Controller1.Screen.newLine();
  Controller1.Screen.print(t1.time(sec)); 
  

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
void detectY() {}
void usercontrol(void) {
  setVelocity(100);
  // User control code here, inside the loop
  while (true) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.
    // Mobile Lift Coding
    if (Controller1.ButtonR1.pressing()) {
      MobileLift.spin(forward);
    }
    if (Controller1.ButtonR2.pressing()) {
      MobileLift.spin(reverse);
    }
    if (!Controller1.ButtonR1.pressing() && !Controller1.ButtonR2.pressing()) {
      MobileLift.stop();
      MobileLift.setStopping(hold);
    }

    if (Controller1.ButtonL2.pressing()) {
      BackLift.spin(forward, 100, rpm);
    }
    if (Controller1.ButtonL1.pressing()) {
      BackLift.spin(reverse, 100, rpm);
    }
    if (!Controller1.ButtonL1.pressing() && !Controller1.ButtonL2.pressing()) {
      BackLift.stop();
      BackLift.setStopping(hold);
    }
    if (Controller1.ButtonY.pressing()) {
      dig1.set(true);
    }
    if (Controller1.ButtonB.pressing()) {
      dig1.set(false);
    }

    FrontLeft.spin(vex::directionType::rev, Controller1.Axis2.position(),
                   vex::velocityUnits::pct);
    FrontRight.spin(vex::directionType::rev, Controller1.Axis3.position(),
                    vex::velocityUnits::pct);
    BackLeft.spin(vex::directionType::rev, Controller1.Axis2.position(),
                  vex::velocityUnits::pct);
    BackRight.spin(vex::directionType::rev, Controller1.Axis3.position(),
                   vex::velocityUnits::pct);
    if (Controller1.ButtonA.pressing() && !last) {
      state = !state;
      last = true;
    } else if (!Controller1.ButtonA.pressing()) {
      last = false;
    }

    if (state) {
      if ((Controller1.Axis3.position() < 7) &&
          (Controller1.Axis2.position() < 7) &&
          (Controller1.Axis3.position() > -7) &&
          (Controller1.Axis2.position() > -7)) {
            Drivetrain.stop();
        FrontRight.setStopping(hold);
        FrontLeft.setStopping(hold);
        BackRight.setStopping(hold);
        BackLeft.setStopping(hold);
      }
    } else {
      if ((Controller1.Axis3.position() < 7) &&
          (Controller1.Axis2.position() < 7) &&
          (Controller1.Axis3.position() > -7) &&
          (Controller1.Axis2.position() > -7)) {
            Drivetrain.stop();
        FrontRight.setStopping(coast);
        FrontLeft.setStopping(coast);
        BackRight.setStopping(coast);
        BackLeft.setStopping(coast);
      }
    }
//jash lock is 4257
    wait(10, msec); // Sleep the task for a short amount of time to
  }                 // prevent wasted resources.
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
