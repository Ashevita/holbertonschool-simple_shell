#include "simple_shell.h"

/**
 * execute_pwd - Handles the "pwd" command.
 * @line: The command line entered by the user.
 */
void execute_pwd(const char *line)
{
	char cwd[1024];

	if (strcmp(line, "pwd") == 0)
	{
		/* Get and display the current working directory */
		if (getcwd(cwd, sizeof(cwd)) != NULL)
			printf("%s\n", cwd);
		else
			perror("pwd");
	}
}
