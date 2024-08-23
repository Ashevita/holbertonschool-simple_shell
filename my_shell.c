#include "shell.h"

/**
 * main - Entry point of the shell program.
 * @ac: The number of arguments passed to the program.
 * @av: An array containing the arguments passed to the program.
 * @env: The environment variables.
 *
 * Return: The exit status of the shell program.
 */
int main(int ac, char *av[], char *env[])
{
	int cpt = 1, status = 0;
	char input[MAX_INPUT_LENGTH];
	char check[] = "/bin/ls";
	(void) av;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("cisfun$ ");

		if (_fgets(input, MAX_INPUT_LENGTH, stdin) == NULL)
		{
			if (_ferror(stdin))
				return (EXIT_FAILURE);
			else
			{
				/* Traitement de l'EOF ici si nécessaire */
				break;
			}
		}

		input[_strcspn(input, "\n")] = '\0';
		get_exit(input);

		status = execute_command(input, env);

		if (access(check, X_OK) != -1)
		{
			check_env(check);
		}
		else
		{
			printf("%s does not exist!\n", check);
		}
		cpt++;
	}

	(void) ac;
	return (status);
}

