#include "elev.h"
#include "position.h"
#include "io.h"
#include "queue.h"
#include "state.h"
#include <stdio.h>


int main() {
    // Initialize hardware
    if (!elev_init()) {
        printf("Unable to initialize elevator hardware!\n");
        return 1;
    }

    printf("Press STOP button to stop elevator and exit program.\n");


    //elev_set_motor_direction(DIRN_UP);

    //variabler??
    // elev_motor_direction_t dir = 0;
    // elev_motor_direction_t* dir_p = &dir;

    //
    // while(1){
    //
    //     position_check_buttons();
    //     queue_set_button_lights();
    //
    //
    //
    // }

    // her gjør jeg masse kødd, sånn at heisen ikke tar imot bestillinger når den ikke er i en definert tilstand!!!!!
    if(elev_get_floor_sensor_signal()==-1){
        elev_set_motor_direction(DIRN_DOWN);///syns dette er litt sketshy
        while(elev_get_floor_sensor_signal()==-1){

        }
    }
    position_set_dir(DIRN_STOP);
    state_set_state(IDLE);
    while (1) {
        //Change direction when we reach top/bottom floor
        // if (elev_get_floor_sensor_signal() == N_FLOORS - 1) {
        //     elev_set_motor_direction(DIRN_DOWN);
        //     position_set_dir(DIRN_DOWN);
        // } else if (elev_get_floor_sensor_signal() == 0) {
        //     elev_set_motor_direction(DIRN_UP);
        //     position_set_dir(DIRN_UP);
        // }

        elevator_state();

        // Stop elevator and exit program if the stop button is pressed
        // if (elev_get_stop_signal()) {
        //     elev_set_motor_direction(DIRN_STOP);
        //     break;
        // }
    }
    return 0;
}
