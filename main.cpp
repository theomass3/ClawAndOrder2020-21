/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       theomass                                                  */
/*    Created:      Thu Dec 10 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LMech                motor         1               
// RMech                motor         2               
// BackOmni             motor         3               
// Controller1          controller                    
// Goliath              motor         4               
// Shooter              motor         5               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  int goliathSpeedpct = 50;
  int shooterSpeedpct = 100;
  Shooter.setVelocity(shooterSpeedpct,percent);

  while (true){
    
    Goliath.setVelocity(goliathSpeedpct,percent);

    if (Controller1.ButtonA.pressing() && goliathSpeedpct < 100) {goliathSpeedpct += 10;}
      else if (Controller1.ButtonB.pressing() && goliathSpeedpct > 10) {goliathSpeedpct -= 10;}

    Goliath.setVelocity(shooterSpeedpct,percent);

    if (Controller1.ButtonA.pressing() && shooterSpeedpct < 100) {shooterSpeedpct += 10;}
      else if (Controller1.ButtonB.pressing() && shooterSpeedpct > 10) {shooterSpeedpct -= 10;}
  
    double fwd = //fwd (back is negative)
    Controller1.Axis1.position();
    
    double side = // strafe
    Controller1.Axis2.position();
    
    double rot = // rotate
    Controller1.Axis3.position();
    
    LMech.setVelocity(fwd-side+rot,percent);
    
    RMech.setVelocity(fwd+side-rot,percent);
    
    BackOmni.setVelocity(side-rot,percent);
  }
  LMech.spin(forward); 
  RMech.spin(forward); 
  BackOmni.spin(forward);
  while ( Controller1.ButtonL1.pressing()==true ) { Goliath.spin(forward); }
  while ( Controller1.ButtonL2.pressing()==true ) { Goliath.spin(reverse); }
  while ( Controller1.ButtonR1.pressing()==true ) {Goliath.spin(forward);}
  while ( Controller1.ButtonR2.pressing()==true ) {Goliath.spin(reverse);}

  

}
