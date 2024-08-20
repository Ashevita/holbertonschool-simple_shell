#include "simple_shell.h"

/**
 * main - Point d'entrée du shell simple
 *
 * Description: Implémente une boucle infinie qui affiche un prompt,
 *		read une ligne de commande, et exécute la commande entrée.
 *
 * Return: Toujours 0 (succès).
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		{
		if (isatty(STDIN_FILENO))
		printf("$ ");/* affiche le prompt*/

		fflush(stdout); /* Assurer que le prompt est affiché */
		}
		/* Lire la ligne de commande */
		nread = getline(&line, &len, stdin);

		/* Vérifier la fin de fichier ou une erreur */
		if (nread == -1)
		{
			/* Fin de fichier ou erreur critique */
			if (line == NULL)
				break;

			/* Erreur, libérer la mémoire et continuer */
			free(line);
			line = NULL;
			len = 0;
			break;
		}
		/* Retirer le saut de ligne */
		line[nread - 1] = '\0';
		/* Ignorer les lignes vides */
		if (strlen(line) == 0)
			continue;
		/* Exécuter la commande */
		execute_command(line);
	}
	/* Libérer la mémoire */
	free(line);
	return (0);
}
