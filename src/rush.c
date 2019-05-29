/*
 * The Runix OS shell
 * Callum Ward, 2019
 */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

#include "rush.h"
#include "rush_input.h"

extern rerrno errno;

rerrno
rush_prompt (char *line,
             int   result)
{
    rerrno rc = 0;
    int size;
    char *color_code;

    if (result != 0) {
        color_code = "\x1b[31m"; // RED
    } else {
        color_code = "\x1b[32m"; // GREEN
    }
    size = printf("%s~> \x1b[0m", color_code);
    if (size < 0) {
        rc = errno;
    }
    rush_getline(line, RUSH_MAX_CMD_SIZE);
    return rc;
}

rerrno
rush_runcmd (char *cmd)
{
    rerrno rc = 0;

    //char **tokens = NULL;
    //rc = rush_tokenize(cmd, &tokens);
    if (RERR_IS_OK(rc)) {
        rc = system(cmd);
    }

    return rc;
}

rerrno
rush_loop (void)
{
    rerrno rc = 0;
    char cmd[RUSH_MAX_CMD_SIZE];

    while (RERR_IS_OK(rc)) {
        rc = rush_prompt(cmd, rc);
        if (RERR_IS_OK(rc)) {
            rc = rush_runcmd(cmd);
        }
        if (RERR_IS_NOTOK(rc)) {
            printf("rush: error: %s\n", strerror(rc));
        }
    }
    return rc;
}

int
main (int    argc,
      char **argv)
{
    rerrno rc = 0;
    /* Enter loop */
    rc = rush_loop();
    return rc;
}

