#include "simple_shell.h"

/**
 * execute_command - Exécute une commande entrée par l'utilisateur.
 * @line: La ligne de commande entrée par l'utilisateur.
 * @home_directory: Le chemin du répertoire HOME.
 * @previous_directory: Le chemin du répertoire utilisé par la commande 'cd'.
 *
 * Description: Appel les fonction spécifique de la commande entrée.
 */
void execute_command(const char *line, const char *home_directory,
						char *previous_directory)
{
	if (strncmp(line, "cd", 2) == 0)
	{
		execute_cd(line, home_directory, previous_directory);
	}
	else if (strcmp(line, "pwd") == 0)
	{
		execute_pwd(line);
	}
	else if (strcmp(line, "ls") == 0)
	{
		execute_ls(line);
	}
	else
	{
		/* Préparer les arguments pour les autres commandes */
		char *args[] = {(char *)line, NULL};
		pid_t pid = fork();

		if (pid == -1)
		{
			perror("fork");
			return;
		}
		else if (pid == 0)
		{
			if (execve(args[0], args, environ) == -1)
			{
				perror("execve");
				_exit(EXIT_FAILURE);
			}
		}
		else
		{
			int status;

			do {
				waitpid(pid, &status, 0);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
		}
}
