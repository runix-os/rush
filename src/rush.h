/*
 * rush.h
 * Contains declarations and constants for use throughout
 * rush
 *
 * Callum Ward, 2019
 */

/* Error codes */
#define EEXIT -1

/* Variables */
#define RUSH_MAX_CMD_SIZE 2048

/*
 * Print the configured prompt and then read user input
 * into the passed line string
 *
 * :param:
 * String to read the user input into
 * :param:
 * Last result of the shell to change prompt color
 */
void rush_prompt(char *line, int result);

/*
 * Main loop of the shell, exit from this function indicates
 * user has triggered exit of the shell process (logout)
 */
int rush_loop (void);
