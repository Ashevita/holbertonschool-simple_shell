// simple_shell.c
#include "simple_shell.h"

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    char previous_directory[1024] = "";
    const char *home_directory = "/home"; // Chemin par défaut pour HOME

    while (1) {
        // Afficher le prompt
        printf("simple_shell> ");
        fflush(stdout); // Assurer que le prompt est affiché

        // Lire la ligne de commande
        nread = getline(&line, &len, stdin);

        // Vérifier la fin de fichier ou une erreur de lecture
        if (nread == -1) {
            // Si getline renvoie -1, cela indique soit une fin de fichier (EOF) soit une erreur
            if (line == NULL) {
                // Fin de fichier ou erreur critique : sortir de la boucle
                break;
            }
            // Si nous avons une erreur de lecture mais line est non NULL, libérer la mémoire et continuer
            perror("Sortie");
            free(line);
            line = NULL;
            len = 0;
            break;
        }

        // Retirer le saut de ligne de la commande
        line[strcspn(line, "\n")] = '\0';

        // Ignorer les lignes vides
        if (strlen(line) == 0) {
            continue;
        }

        // Exécuter la commande
        execute_command(line, home_directory, previous_directory);
    }

    // Libérer la mémoire allouée
    free(line);

    return 0;
}
