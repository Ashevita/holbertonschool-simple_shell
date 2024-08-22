#include "simple_shell.h"

/**
 * main - Point d'entrée du shell simple
 *
 * Description: Implémente une boucle infinie qui affiche un prompt,
 *              lit une ligne de commande, et exécute la commande entrée.
 *
 * Return: Toujours 0 (succès).
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char **environ_copy;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("($) "); /* affiche le prompt */
		fflush(stdout); /* Assurer que le prompt est affiché */

		/* Lire la ligne de commande */
		nread = getline(&line, &len, stdin);

		/* Vérifier la fin de fichier ou une erreur */
		if (nread == -1)
		{
			if (feof(stdin)) /* Fin de fichier (CTRL+D) */
			{
				break;
			}
			if (ferror(stdin)) /* Erreur de lecture */
			{
				perror("getline");
				free(line);
				exit(EXIT_FAILURE);
			}
		}

		/* Retirer le saut de ligne */
		if (nread > 0 && line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		/* Ignorer les lignes vides */
		if (strlen(line) == 0)
			continue;

		/* Quitter le shell si la commande est 'exit' */
		if (strcmp(line, "exit") == 0)
		{
			free(line);
			exit(EXIT_SUCCESS); /* Quitter le programme avec un code de retour 0 */
		}

		/* Afficher les variables d'environnement */
		if (strcmp(line, "env") == 0)
		{
			environ_copy = environ;
			while (*environ_copy)
			{
				printf("%s\n", *environ_copy);
				environ_copy++;
			}
			continue;
		}

		/* Exécuter la commande */
		execute_command(line);
	}

	/* Libérer la mémoire avant de quitter */
	if (line != NULL)
		free(line);

	return (0);
}
