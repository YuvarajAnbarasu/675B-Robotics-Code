#include "main.h"

pros::Motor intake(2, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_ROTATIONS);
pros::Motor catapult(12, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_ROTATIONS);

pros::ADIDigitalOut pistonWingA('A', false);
pros::ADIDigitalOut pistonWingB('B', false);

pros::ADIDigitalIn LSwitch('A');
//change gearset depending on speed and torque needed