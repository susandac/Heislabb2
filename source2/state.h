
typedef enum tag_state_elevator_states {
    EMERGENCY_STOP = 0,
    DRIVING = 1,
    ORDER_STOP = 2,
	IDLE = 3
} state_elevator_states_t;

/**
*shifts state to EMERGENCY_STOP if emergencybutton is pulled
*/
void state_check_emergency_stop();
/**
*Controls the state of the elevator .
*/
void elevator_state();
/**
*shifts the elevator state
*/
void state_set_state();
