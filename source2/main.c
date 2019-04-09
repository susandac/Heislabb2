#include "elev.h"
#include "state.h"
#include <stdio.h>

int main() {
    // Initialize hardware
    if (!elev_init()) {
        printf("Unable to initialize elevator hardware!\n");
        return 1;
    }
    state_initialize();
    while (1) {
        state_elevator_FSM();
    }
    return 0;
}
