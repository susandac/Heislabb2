#include "queue.h"
#include "elev.h"
#include "position.h"

#include <stdio.h>

int orderqueue[N_FLOORS][N_BUTTONS] = {{0}};

void queue_insert_order(int button, int floor){
	orderqueue[floor][button] = 1;
}

void queue_delete_all(){
	for(int floor=0; floor<N_FLOORS; floor++){
		for(int button=0; button<N_BUTTONS; button++){
			orderqueue[floor][button]=0;
		}
	}
	queue_set_button_lights();
}

void queue_order_done(int floor){
	for (int button = 0; button < N_BUTTONS; button++){
		orderqueue[floor][button] = 0;
	}
}

void queue_check_buttons() {
	for (int floor = 0; floor < N_FLOORS; floor++) {
		for (int button = 0; button < N_BUTTONS; button++) {
			if (! ((floor == 3) & (button == 0))) {
				if (! ((floor == 0) & (button == 1))) {
					if (elev_get_button_signal(button,floor)) {
						queue_insert_order(button,floor);
					}
				}
			}
		}
	}
}

//return 1 for order stop, 0 for continue
int queue_check_floor(int floor_var, elev_motor_direction_t dir){
	if (elev_get_floor_sensor_signal() == -1) {
		return 0;
	}
	if(dir == DIRN_UP){
		if(orderqueue[floor_var][BUTTON_CALL_UP] || orderqueue[floor_var][BUTTON_COMMAND]){
			return 1;
		}
		int orders_above = 0;
		for(int floor = (floor_var+1); floor < N_FLOORS; floor++){
			if(orderqueue[floor][BUTTON_CALL_UP] || orderqueue[floor][BUTTON_COMMAND] || orderqueue[floor][BUTTON_CALL_DOWN]){
				orders_above += 1;
			}
		}
		if (orders_above == 0){
			position_set_dir(DIRN_STOP);
			return 1;
		}
	}
	if(dir == DIRN_DOWN){
		if(orderqueue[floor_var][BUTTON_CALL_DOWN] || orderqueue[floor_var][BUTTON_COMMAND]){
			return 1;
		 }
		int orders_below = 0;
		for(int floor = (floor_var-1); floor >= 0; floor--){
			if(orderqueue[floor][BUTTON_CALL_UP] || orderqueue[floor][BUTTON_COMMAND] || orderqueue[floor][BUTTON_CALL_DOWN]){
				orders_below += 1;
			}
		}
		if (orders_below == 0){
			position_set_dir(DIRN_STOP);
			return 1;
		}
	}
	return 0;
}

int queue_check_orderqueue(int current_floor){
	int orders_above = 0;
	int extra_floors_to_check_above = 0;

	if(position_get_position() < current_floor){
		extra_floors_to_check_above = 1;
	}
	if (current_floor + 1 - extra_floors_to_check_above <= N_FLOORS){
		for(int floor = current_floor + 1 - extra_floors_to_check_above; floor < N_FLOORS; floor++){
			if(orderqueue[floor][BUTTON_CALL_UP]|| orderqueue[floor][BUTTON_COMMAND] || orderqueue[floor][BUTTON_CALL_DOWN]){
				orders_above += 1;
			}
		}
			if(orders_above > 0){
				return 1;
			}
		}
	int orders_below = 0;
    int extra_floors_to_check_below = 0;
	if(position_get_position() > current_floor){
		extra_floors_to_check_below = 1;
	}
	for(int floor=0; floor < current_floor + extra_floors_to_check_below; floor++){
		if(orderqueue[floor][BUTTON_CALL_UP]|| orderqueue[floor][BUTTON_COMMAND] || orderqueue[floor][BUTTON_CALL_DOWN]){
			orders_below += 1;
		}
	}
	if(orders_below > 0){
		return -1;
	}
	if (orderqueue[current_floor][BUTTON_CALL_UP]|| orderqueue[current_floor][BUTTON_COMMAND] || orderqueue[current_floor][BUTTON_CALL_DOWN]){
		return 0;
	}
	return 2;
}

void queue_set_button_lights(){
	for(int floor=0; floor<N_FLOORS; floor++){
		for(int button=0; button<N_BUTTONS; button++){
			if (! ((floor == 3) & (button == 0))) {
				if (! ((floor == 0) & (button == 1))) {
					elev_set_button_lamp(button, floor, orderqueue[floor][button]);
				}
			}
		}
	}
}
