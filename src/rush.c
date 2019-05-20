/*
 * The Runix OS shell
 * Callum Ward, 2019
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "rush.h"
#include "rush_input.h"

void
rush_prompt (char *line, int result) {
    char *color_code;
    if (result != 0) {
        color_code = "\x1b[31m"; // RED
    } else {
        color_code = "\x1b[32m"; // GREEN
    }
    printf("%s~> \x1b[0m", color_code);
    rush_getline(line, RUSH_MAX_CMD_SIZE);
}

int
rush_loop (void) {
    int result = 0;
    bool running = true;
    char cmd[RUSH_MAX_CMD_SIZE];

    while (running) {
        rush_prompt(cmd, result);
        result = system(cmd);
        if (result != 0)
            running = false;
    }

    return result;
}

int
main (int    argc,
      char **argv) {
    int result = 0;
    /* Enter loop */
    result = rush_loop();
    return result;
}

