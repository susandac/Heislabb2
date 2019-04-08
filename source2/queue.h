

/**
* Matrix containing 0 for buttons not pressed and 1 for buttons pressed
*/
// int orderqueue[N_FLOORS][N_BUTTONS] = {{0}};

/**
* Insert an order into the order queue.
*
* @param[in] button Type of button (up, down, command).
* @param [in] floor Floor that button was pressed on.
*/
void queue_insert_order(int button, int floor);

/**
* Deletes everyting in the order queue and turns off button lights.
*/
void queue_delete_all();

/**
* Determines direction of elevator, and wheter to stop when approaching floors.
*
* @param[in] floors Floor the elevator was last on.
* @param[in] dir Direction the elavator is moving.
*/
void queue_check_floor(int floor, int dir);

/**
* Deletes finished orders from the order queue.
*
* @param[in] button Button type belonging to the order.
* @param[in] floor Floor belonging to the order.
*/
void queue_order_done(int button, int floor);

/**
* sets button lights inside and outside the elevator.
*/
void queue_set_button_lights();
/**
* Checks the orderqueue and sets the direction to the elevator
*/
void queue_check_orderqueue();
