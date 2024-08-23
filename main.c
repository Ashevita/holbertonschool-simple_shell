#include "simple_shell.h"

/**
 * main - Entry point of the simple shell
 *
 * Description: Implements an infinite loop that displays a prompt,
 *              reads a command line, and executes the entered command.
 *
 * Return: Always 0 (success).
 */
int main(void)
{
	char *line = NULL; /*pointer for stock line read*/
	size_t len = 0; /*lenght of memory for cmd line*/
	ssize_t nread; /*number of char read*/

	while (1)
	{
		{
			if (isatty(STDIN_FILENO))
				printf("$ "); /* Display the prompt */
			fflush(stdout); /* Ensure the prompt is displayed */
		}
		/* Read the command line */
		nread = getline(&line, &len, stdin);
		/* Check for end of file or an error */
		if (nread == -1)
		{
			if (line == NULL) /* End of file or critical error */
				break;
			/* Error, free memory and continue */
			free(line);
			line = NULL;
			len = 0;
			break;
		}
		/* Remove the newline character */
		line[nread - 1] = '\0';
		/* Ignore empty lines */
		if (strlen(line) == 0)
			continue;
		if (strcmp(line, "exit") == 0)
		{
			free(line);
			exit(0); /* Exit the program with return code 0 */
		}
		/* Execute the command */
		execute_command(line);
	}
	/* Free the memory */
	free(line);
	return (0);
}
