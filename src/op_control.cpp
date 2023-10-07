

#include "main.h"

void op_control(){
    intake_control();
    cata_control();
    wing_control();
}

void intake_control(){
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
        intake.move_velocity(-600);
    }

    else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
        intake.move_velocity(600);
    }

    else{
        intake.move_velocity(0);
    }  
}

void cata_control(){
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
        while(LSwitch.get_value() == false){
        catapult.move_velocity(-150);}
    }
    catapult.move_velocity(0);
}

void wing_control(){
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_A)){
        pistonWingA.set_value(true);
        pistonWingB.set_value(true);
    }

    else{
        pistonWingA.set_value(false);
        pistonWingB.set_value(false);
    }
}