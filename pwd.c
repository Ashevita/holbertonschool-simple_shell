#include "simple_shell.h"

/**
 * execute_pwd - Gère la commande "pwd".
 * @line: La ligne de commande entrée par l'utilisateur.
 */
void execute_pwd(const char *line)
{
	char cwd[1024];

	if (strcmp(line, "pwd") == 0)
	{
		/* Obtenir et afficher le répertoire de travail actuel */
		if (getcwd(cwd, sizeof(cwd)) != NULL)
			printf("%s\n", cwd);
		else
			perror("pwd");
	}
}
