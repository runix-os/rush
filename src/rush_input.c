/*
 * rush_input.c
 * Functions for retrieving user input for RUSH
 *
 * Callum Ward, 2019
 */

#include <stdio.h>
#include "rush_input.h"

void rush_getline (char *line, int size) {
    fgets(line, size, stdin);
}
