#include "simple_shell.h"

/**
 * execute_cd - Gère la commande "cd".
 * @line: La ligne de commande entrée par l'utilisateur.
 * @home_directory: Le chemin du répertoire HOME.
 * @previous_directory: Le chemin du répertoire utilisé par la commande 'cd'.
 */
void execute_cd(const char *line, const char *home_directory,
		char *previous_directory)
{
	char *path = strtok((char *)line + 3, " ");
	char current_directory[1024];

	if (path == NULL || strcmp(path, "~") == 0)
		path = (char *)home_directory; /* Aller au répertoire HOME par défaut */
	else if (strcmp(path, "-") == 0)
	{
		if (strlen(previous_directory) == 0)
		{
			printf("simple_shell: cd: OLDPWD not set\n");
			return;
		}
		path = previous_directory; /* Aller au répertoire précédent */
	}

	/* Mettre à jour répertoire précédent avant de changer de répertoire */
	if (getcwd(current_directory, sizeof(current_directory)) != NULL)
	strncpy(previous_directory, current_directory,
	sizeof(previous_directory) - 1);

	/* Changer de répertoire */
	if (chdir(path) != 0)
		perror("cd");
}
