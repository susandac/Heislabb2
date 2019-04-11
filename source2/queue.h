
/**
* @file
* @brief Contains functions for editing and checking the order queue,
* polling and setting the order button lights
*/


/**
* @brief Insert an order into the order queue.
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
* @brief Determines direction of elevator, and wheter to stop when approaching a floor.
*
* @param[in] floors Floor the elevator was last on.
* @param[in] dir Direction the elavator is moving.
* @return 1 if order_stop and 0 if continue driving.
*/
int queue_check_floor(int floor, int dir);

/**
* @brief Deletes finished orders from the order queue.
*
* @param[in] floor The floor that the elevator is stopping on.
*/
void queue_order_done(int floor);

/**
* @brief Polls order buttons and inserts orders into the queue.
*/
void queue_check_buttons();

/**
* @brief Sets button lights inside and outside the elevator.
*/
void queue_set_button_lights();

/**
* @brief Checks the orderqueue and decides which way the elevator should drive.
* @param[in] current_floor Floor the elevator was last on.
*Decimal numbers represent that the elevator is between two floors.
* @return 1 if driection is up, -1 if direction is down, 0 if order stop and 2 if do nothing.
*/
int queue_check_orderqueue(int current_floor);
