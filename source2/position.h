
/**
* @file
* @brief Keeps track of elevator position and direction and has functions
*for polling buttons and sensors
*/

/**
*@brief Sets global varable @p direction to the direction of the elevator
*@param[in] dir The direction of the elevator.
*/

void position_set_dir(int dir);

/**
*@brief Get direction from global variable @p direction
*@return the value of the elevator's direction represented by -1, 0 or 1.
*/

int position_get_dir();

/**
*@brief Get the value of the floor the elevator is in.
*@return the value 0-3 that represents the floor the elevator was last on.
*/
int position_get_floor();

/**
*@brief Returns the value of the position the elevator is in.
*@return  the value 0.0 - 3.0 that represents the position of the elevator.
*Decimal numbers represent that the elevator is between two floors.
*/
float position_get_position();


/**
*@brief Shifts state to EMERGENCY_STOP if emergency stop button is pushed
@return 1 if button is pushed, 0 if not.
*/
int position_check_emergency_stop();

/**
*@brief Polls order buttons and inserts orders into the queue.
*/
void position_check_buttons();

/**
*@brief Checks and updades current_floor and floor indicators.
*/
void position_update_floor();

/**
*@brief Checks that it is safe to open the door and sets door lamp to 1.
*/
void position_open_door();
/**
*@brief Sets door lamp to 0.
*/
void position_close_door();
