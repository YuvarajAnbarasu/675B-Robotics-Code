

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

void cata_shoot(){
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_X)){
        catapult.move_velocity(-150);
        pros::delay(10);
    }
}

bool shooting = false;  // Variable to track if we're shooting or not

void skills_cata() {
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
        if (!shooting) {  // If we're not already shooting, start shooting
            shooting = true;
            catapult.move_velocity(-150);  // Start the catapult motor
        } else {  // If we're already shooting, stop shooting
            shooting = false;
            catapult.move_velocity(0);  // Stop the catapult motor
        }

        // Wait until the B button is released to avoid rapid toggling
        while (master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
            pros::delay(10);  // Small delay to prevent CPU hogging
        }
    }
}

void cata_sit(){
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)){
        catapult.move_velocity(-150);
        pros::delay(100);
        catapult.move_voltage(0);
    }
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
