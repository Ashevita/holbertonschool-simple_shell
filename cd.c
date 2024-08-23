#include "simple_shell.h"

/**
 * execute_cd - Handles the "cd" command.
 * @line: The command line entered by the user.
 * @home_directory: The path to the HOME directory.
 * @previous_directory: The path to the directory used by the 'cd' command.
 */
void execute_cd(const char *line, const char *home_directory,
		char *previous_directory)
{
	char *path = strtok((char *)line + 3, " ");
	char current_directory[1024];

	if (path == NULL || strcmp(path, "~") == 0)
		path = (char *)home_directory; /* Go to the HOME directory by default */
	else if (strcmp(path, "-") == 0)
	{
		if (strlen(previous_directory) == 0)
		{
			printf("simple_shell: cd: OLDPWD not set\n");
			return;
		}
		path = previous_directory; /* Go to the previous directory */
	}

	/* Update the previous directory before changing the directory */
	if (getcwd(current_directory, sizeof(current_directory)) != NULL)
		strncpy(previous_directory, current_directory,
			sizeof(previous_directory) - 1);

	/* Change the directory */
	if (chdir(path) != 0)
		perror("cd");
}
