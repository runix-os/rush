/*
 * The Runix OS shell
 * Callum Ward, 2019
 */

#include <stdlib.h>
#include <stdio.h>

#define EEXIT -1

int rush_prompt(void) {
    char input_ch = '\0';
    int reading_input = 0;
    char cmd[1024];
    size_t index = 0;
    int result = 0;

    reading_input = 1;
    while(reading_input) {
        /* Put out the configured prompt */
        printf(">> ");
        index = 0;
        for (size_t x = 0; x < 1024; x++) {
            cmd[x] = '\0';
        }
        /* Take in any user input until a newline character */
        do {
            input_ch = getchar();
            cmd[index] = input_ch;
            index++;
        } while (input_ch != '\n' && input_ch != '\0');
        result = system(cmd);
        if (result != 0) {
            reading_input = 0;
        }
    }
    return EEXIT;
}

int
main (int    argc,
      char **argv) {
    unsigned int exit = 0;
    int result = 1;
    /* Init */
    /* Enter loop */
    while(!exit) {
        result = rush_prompt();
        if (result == EEXIT) {
            exit = 1;
        }
    }
}

