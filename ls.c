#include "simple_shell.h"

/**
 * execute_ls - Gère la commande "ls".
 * @line: La ligne de commande entrée par l'utilisateur.
 */
void execute_ls(const char *line)
{
	char *args[2];
	pid_t pid = fork();

	if (strcmp(line, "ls") == 0)
	{
		args[0] = "/bin/ls";  /* Chemin absolu pour "ls" */
		args[1] = NULL;       /* Pas d'arguments supplémentaires */

		/* Créer un processus enfant pour exécuter la commande */
		if (pid == -1)
		{
			perror("fork");
			return;
		}
		else if (pid == 0)
		{
			/* Processus enfant : exécuter la commande */
			if (execve(args[0], args, environ) == -1)
			{
				perror("execve");
				_exit(EXIT_FAILURE);
			}
		}
		else
		{
			/* Processus parent : attendre que le processus enfant se termine */
			int status;

			do {
				waitpid(pid, &status, 0);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
	}
}
