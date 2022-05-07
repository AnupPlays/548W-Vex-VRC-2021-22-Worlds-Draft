using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern smartdrive Drivetrain;
extern motor Motor2;
extern rotation Rotation15;
extern motor Motor12;
extern potV2 PotentiometerV2A;
extern digital_out DigitalOutC;
extern digital_out DigitalOutD;
extern motor Motor4;
extern motor Motor14;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
