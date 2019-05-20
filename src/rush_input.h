/*
 * rush_input.h
 * Contains declarations and constants for routines
 * involving retrieving user input
 *
 * Callum Ward, 2019
 */

/*
 * Retrieve a line of user input, up to a newline,
 * EOL/EOF or the maximum read length, ensuring that
 * line is valid string (null terminated)
 *
 * :param:
 * String to put the user input in
 * :param:
 * Size of the available buffer
 */
void rush_getline (char *line, int size);
