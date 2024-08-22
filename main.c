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
		fflush(stdout); /* Assurer que le prompt es affiché */
		}
		/* Lire la ligne de commande */
		nread = getline(&line, &len, stdin);
		/* Vérifier la fin de fichier ou une erreur */
		if (nread == -1)
		{
			if (line == NULL) /* Fin de fichier ou erreur critique */
				break;
			/* Erreur, libérer la mémoire continuer */
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
		if (strcmp(line, "exit") == 0)
		{
			free(line);
			exit(0); /* Quitter le programme avec un code de retour 0 */
		}
		/* Exécuter la commande */
		execute_command(line);
	}
	/* Libérer la mémoire */
	free(line);
	return (0);
}
