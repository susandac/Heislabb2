
/**
* @file
* @brief A finite state machine for the elevator
*/

typedef enum tag_state_elevator_states {
    EMERGENCY_STOP = 0,
    DRIVING = 1,
    ORDER_STOP = 2,
	IDLE = 3
} state_elevator_states_t;

/**
*@brief Moves the elevator down to a floor if no floor sensor
*is active at start.
*/
void state_initialize();

/**
*@brief Controls the state of the elevator
*/
void state_elevator_FSM();
