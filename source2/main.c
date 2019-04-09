#include "elev.h"
#include "position.h"
#include "state.h"
#include <stdio.h>


int main() {
    // Initialize hardware
    if (!elev_init()) {
        printf("Unable to initialize elevator hardware!\n");
        return 1;
    }
    // her gjør jeg masse kødd, sånn at heisen ikke tar imot bestillinger når den ikke er i en definert tilstand!!!!!
    if(elev_get_floor_sensor_signal()==-1){
        elev_set_motor_direction(DIRN_DOWN);///syns dette er litt sketshy
        while(elev_get_floor_sensor_signal()==-1){

        }
    }
    position_set_dir(DIRN_STOP);
    state_set_state(IDLE);

    while (1) {
        state_elevator_FSM();
    }
    return 0;
}
