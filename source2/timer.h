
/**
* @file
* @brief Timer module to keep track of how long the door has been open
*/

/**
*@brief Starts timer.
*/
void timer_start_timer();

/**
*@brief Checks if it is timeout (3 sek).
*@return 1 if timer has timed out and 0 if not.
*/
int timer_timeout();
