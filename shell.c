#include "simple_shell.h"

/**
 * main - Point d'entrée du shell simple
 *
 * Description: Cette fonction implémente une boucle infinie
 *              qui affiche un prompt, lit une ligne de commande,
 *              et exécute la commande entrée par l'utilisateur.
 *
 * Return: Toujours 0 (succès).
 */
int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    char previous_directory[1024] = "";
    const char *home_directory = "/home"; /* Chemin par défaut pour HOME */

    while (1)
    {
        /* Afficher le prompt */
        printf("simple_shell> ");
        fflush(stdout); /* Assurer que le prompt est affiché */

        /* Lire la ligne de commande */
        nread = getline(&line, &len, stdin);

        /* Vérifier la fin de fichier ou une erreur de lecture */
        if (nread == -1)
        {
    /* Si getline renvoie -1, soit une fin de fichier (EOF) soit une erreur */
            if (line == NULL)
            {
                /* Fin de fichier ou erreur critique : sortir de la boucle */
                break;
            }
    /* Si erreur mais line=non NULL, libérer la mémoire et continuer */
            perror("");
            free(line);
            line = NULL;
            len = 0;
            break;
        }

        /* Retirer le saut de ligne de la commande */
        line[strcspn(line, "\n")] = '\0';

        /* Ignorer les lignes vides */
        if (strlen(line) == 0)
        {
            continue;
        }

        /* Exécuter la commande */
        execute_command(line, home_directory, previous_directory);
    }

    /* Libérer la mémoire allouée */
    free(line);

    return (0);
}
