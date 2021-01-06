using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor LMech;
extern motor RMech;
extern motor BackOmni;
extern controller Controller1;
extern motor Goliath;
extern motor Shooter;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );