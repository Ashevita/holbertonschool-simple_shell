#include "simple_shell.h"
#include <string.h>

/**
 * execute_command - Exécute une commande entrée par l'utilisateur.
 * @line: La ligne de commande entrée par l'utilisateur.
 *
 * Description: Appel les fonctions spécifiques en fonction de la commande entrée.
 */
void execute_command(const char *line)
{
	char *cmd;
	char *args[2];
	pid_t pid;

	/* Copier la ligne pour éviter de modifier l'originale */
	char *line_copy = strdup(line);

	if (line_copy == NULL)
	{
		perror("strdup");
		return;
	}

	/* Extraire la première partie de la commande */
	cmd = strtok(line_copy, " ");

	/* Préparer les arguments pour les autres commandes */
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
		if (execve(args[0], args, environ) == -1)
		{
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

	/* Libérer la mémoire allouée */
	free(line_copy);
}
