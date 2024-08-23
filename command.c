#include "simple_shell.h"
#include <string.h>
/**
 * execute_command - Executes a command entered by the user.
 * @line: The command line entered by the user.
 *
 * Description: Calls specific functions based on the command entered.
 */
void execute_command(const char *line)
{
	char *cmd; /*pointer for store name of cmd*/
	char *args[2]; /*Array to store arguments*/
	pid_t pid; /*Process identifier to manage child processes.*/
	/* Copy the line to avoid modifying the original */
	char *line_copy = strdup(line);

	if (line_copy == NULL)
	{
		perror("strdup");
		return;
	}
	cmd = strtok(line_copy, " "); /* Extract the first part of the command */
	/* Prepare arguments for other commands */
	args[0] = cmd;
	args[1] = NULL;
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(line_copy);
		return;
	}
	else if (pid == 0)
	{
		/* Child process: execute the command */
		if (execve(args[0], args, environ) == -1)
		{
			_exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process: wait for the child process to finish */
		int status;

		do {
			waitpid(pid, &status, 0);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	free(line_copy);
}
