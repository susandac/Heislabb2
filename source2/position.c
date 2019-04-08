#include "position.h"
#include "queue.h"
#include "elev.h"
#include <stdio.h>


int current_floor;
elev_motor_direction_t direction;
float current_position;

void position_set_dir(int dir){
	direction = dir;
}

elev_motor_direction_t position_get_dir(){
	return direction;
}

void position_set_floor(int floor){
	current_floor = floor;
}
float position_get_position(){
	return current_position;
}

int position_get_floor(){
	return current_floor;
}

void position_check_buttons() {
	for (int floor = 0; floor < N_FLOORS; floor++) {
		//fiks etterpå
		for (int button = 0; button < 3; button++) {
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


void position_update_floor() {
	int floor = elev_get_floor_sensor_signal();
	if (floor == -1) {
		if (direction == DIRN_UP){
			current_position = current_floor + 0.5;
		}
		else if (direction == DIRN_DOWN){
			current_position = current_floor - 0.5;
		}
		printf("current_position: %f\n", current_position);
		return;
	}
	position_set_floor(floor);
	elev_set_floor_indicator(floor);
	current_position = floor;
	printf("current_position: %f\n", current_position);
}

void position_open_door(){
	if(elev_get_floor_sensor_signal() >= 0){
		elev_set_door_open_lamp(1);
}
}

void position_close_door(){
	elev_set_door_open_lamp(0);
}
