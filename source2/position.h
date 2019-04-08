

/**
*Sets global varable direction to the direction of the elevator
*@param[in] dir The floor the elevator is in. Must be 0-3.
*/

void position_set_dir(int dir);
/**
*get direction from global variable direction
*@return the value of the elevators direction represented by -1, 0 or 1.
*/

int position_get_dir();

/**
*Sets global varable current_floor to new floor
*@param[in] floor The floor the elevator is in or was last in if the elevator is between to floors. Must be 0-3.
*/
void position_set_floor(int floor);

/**
*return the value of the floor the elevator is in. Must be 0-3
*/
int position_get_floor();
/**
*return the value of the position the elevator is in.
*/
float position_get_position();

/**
* Polls order buttons and inserts orders into the queue.
*/
void position_check_buttons();

/**
* checks and updades current_floor and floor indicators.
*/
void position_update_floor();

/**
* sets floor lights
*/

/**
* sets door lamp
*/
void position_open_door();
/**
* sets door lamp to 0
*/
void position_close_door();
