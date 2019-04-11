#include "elev.h"
#include "position.h"
#include "queue.h"
#include "state.h"
#include "timer.h"
#include <stdio.h>

state_elevator_states_t current_state;

void state_set_state(state_elevator_states_t state){
	current_state = state;
}

void state_initialize(){
	if(elev_get_floor_sensor_signal()==-1){
		elev_set_motor_direction(DIRN_DOWN);
		while(elev_get_floor_sensor_signal()==-1){ };
	}
	position_set_dir(DIRN_STOP);
	state_set_state(IDLE);
	position_update_floor();
}

void state_elevator_FSM(){
	switch (current_state) {
		case EMERGENCY_STOP:
		elev_set_motor_direction(DIRN_STOP);
		queue_delete_all();
		if(elev_get_floor_sensor_signal()==-1){
			state_set_state(IDLE);
		}
		else{
			position_open_door();
			state_set_state(ORDER_STOP);
		}
		elev_set_stop_lamp(1);
		while(elev_get_stop_signal()){ };
		elev_set_stop_lamp(0);
		break;

		case DRIVING:
		queue_check_buttons();
		queue_set_button_lights();
		position_update_floor();
		if (queue_check_floor(position_get_floor(), position_get_dir())){
			state_set_state(ORDER_STOP);
		}
		if(elev_get_stop_signal()) {
			state_set_state(EMERGENCY_STOP);
		}
		break;

		case ORDER_STOP:
		elev_set_motor_direction(DIRN_STOP);
		queue_order_done(position_get_floor());
		position_open_door();
		timer_start_timer();

		while (!timer_timeout()){
			queue_check_buttons();
			queue_set_button_lights();
			if (elev_get_stop_signal()){
				state_set_state(EMERGENCY_STOP);
				break;
			}
		}
		position_close_door();
		if (position_get_dir() == DIRN_STOP){
			state_set_state(IDLE);
		}
		else {
			state_set_state(DRIVING);
			elev_set_motor_direction(position_get_dir());
		}
		break;

		case IDLE:
		elev_set_motor_direction(DIRN_STOP);
		queue_check_buttons();
		queue_set_button_lights();
		if (queue_check_orderqueue(position_get_floor(), position_get_position()) == 1){
			elev_set_motor_direction(DIRN_UP);
			position_set_dir(DIRN_UP);
			state_set_state(DRIVING);
		}
		else if (queue_check_orderqueue(position_get_floor(), position_get_position()) == -1){
			elev_set_motor_direction(DIRN_DOWN);
			position_set_dir(DIRN_DOWN);
			state_set_state(DRIVING);
		}
		else if (queue_check_orderqueue(position_get_floor(), position_get_position()) == 0){
			state_set_state(ORDER_STOP);
		}

		if(elev_get_stop_signal()) {
			state_set_state(EMERGENCY_STOP);
		}
		break;
	}
}
