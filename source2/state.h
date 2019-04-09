
/**
* @file
* @brief A final state machine for the elevator
*/

typedef enum tag_state_elevator_states {
    EMERGENCY_STOP = 0,
    DRIVING = 1,
    ORDER_STOP = 2,
	IDLE = 3
} state_elevator_states_t;

/**
*@brief Shifts state to EMERGENCY_STOP if emergency stop button is pushed
*/
void state_check_emergency_stop();

/**
*@brief Controls the state of the elevator
*/
void state_elevator_FSM();

/**
*@brief Shifts the variable @c current_state to @p state
*
*@param[in] state next state for the elevator FSM
*/
void state_set_state(state_elevator_states_t state);
