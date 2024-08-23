#include "simple_shell.h"

/**
 * execute_ls - Handles the "ls" command.
 * @line: The command line entered by the user.
 */
void execute_ls(const char *line)
{
	char *args[2];
	pid_t pid = fork();

	if (strcmp(line, "ls") == 0)
	{
		args[0] = "/bin/ls";  /* Absolute path for "ls" */
		args[1] = NULL;       /* No additional arguments */

		/* Create a child process to execute the command */
		if (pid == -1)
		{
			perror("fork");
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
	}
}
