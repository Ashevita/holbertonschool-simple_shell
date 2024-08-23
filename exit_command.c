#include"shell.h"

/**
 * get_exit - permit to exit in the shell
 * @command: the command for check_out
 *
 * function terminates the shell with success
 */

void get_exit(char *command)
{
	if (_strncmp(command, "exit", _strlen(command)) == 0)
	{
		exit(EXIT_SUCCESS);
	}
}
