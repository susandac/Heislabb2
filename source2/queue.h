
/**
* @file
* @brief Contains functions for editing and checking the order queue
*and setting the order button lights
*/


/**
*@brief Insert an order into the order queue.
*
* @param[in] button Type of button (up, down, command).
* @param [in] floor Floor that button was pressed on.
*/
void queue_insert_order(int button, int floor);

/**
*@brief Deletes everyting in the order queue.
*/
void queue_delete_all();

/**
*@brief Determines direction of elevator, and wheter to stop when approaching a floor.
*
* @param[in] floors Floor the elevator was last on.
* @param[in] dir Direction the elavator is moving.
*/
void queue_check_floor(int floor, int dir);

/**
*@brief Deletes finished orders from the order queue.
*
* @param[in] button Button type belonging to the order.
* @param[in] floor Floor belonging to the order.
*/
void queue_order_done(int button, int floor);

/**
*@brief Sets button lights inside and outside the elevator.
*/
void queue_set_button_lights();

/**
*@brief Checks the orderqueue and sets the direction to the elevator
*/
void queue_check_orderqueue();
