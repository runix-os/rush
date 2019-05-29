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

/* Error Macros */
typedef int rerrno;
#define RERR_IS_OK(err) ((err) == 0)
#define RERR_IS_NOTOK(err) ((err) != 0)

/*
 * Print the configured prompt and then read user input
 * into the passed line string
 *
 * :param:
 * String to read the user input into
 * :param:
 * Last result of the shell to change prompt color
 */
rerrno rush_prompt (char *line,
                    int   result);

/*
 * Take the input command, run it through any parsing to find
 * the steps that need to be taken to run it, then open any
 * needed processes, run and return the results
 *
 * :param:
 * String declaring the command to be run
 */
rerrno rush_runcmd(char *cmd);

/*
 * Main loop of the shell, exit from this function indicates
 * user has triggered exit of the shell process (logout)
 */
rerrno rush_loop (void);
