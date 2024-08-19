#include "simple_shell.h"

/**
 * execute_command - Exécute une commande entrée par l'utilisateur.
 * @line: La ligne de commande entrée par l'utilisateur.
 * @home_directory: Le chemin du répertoire HOME.
 * @previous_directory: Le chemin du répertoire utilisé par la commande 'cd'.
 *
 * Description: gère les commandes "cd", "pwd", et "ls" de manière spéciale.
 * Pour les autres commandes, elle crée un processus enfant pour les exécuter
 *en utilisant `execve`. Elle gère également les erreurs liées aux commandes.
 */
void execute_command(const char *line, const char *home_directory,
char *previous_directory)
{
    char *args[3];
    pid_t pid;
    int status;

    /* Traiter la commande "cd" séparément */
    if (strncmp(line, "cd", 2) == 0)
    {
        char *path = strtok((char *)line + 3, " ");
        char current_directory[1024];

        /* Gérer le cas où aucun chemin n'est fourni ou "~" est utilisé */
        if (path == NULL || strcmp(path, "~") == 0)
        {
        path = (char *)home_directory; /* Aller répertoire HOME par défaut */
        }
        else if (strcmp(path, "-") == 0)
        {
            /* Gérer la commande "cd -" pour revenir au répertoire précédent */
            if (strlen(previous_directory) == 0)
            {
                printf("simple_shell: cd: OLDPWD not set\n");
                return;
            }
            path = previous_directory; /* Aller au répertoire précédent */
        }

    /* Mettre à jour le répertoire précédent avant de changer de répertoire */
		if (getcwd(current_directory, sizeof(current_directory)) != NULL)
        {
            strncpy
(previous_directory, current_directory, sizeof(previous_directory) - 1);
        }

        /* Changer de répertoire */
        if (chdir(path) != 0)
        {
            perror("cd");
        }
        return;
    }

    /* Traiter la commande "pwd" séparément */
    if (strcmp(line, "pwd") == 0)
    {
        char cwd[1024];

        /* Obtenir et afficher le répertoire de travail actuel */
        if (getcwd(cwd, sizeof(cwd)) != NULL)
        {
            printf("%s\n", cwd);
        }
        else
        {
            perror("pwd");
        }
        return;
    }

    /* Préparer les arguments pour la commande "ls" */
    if (strcmp(line, "ls") == 0)
    {
        args[0] = "/bin/ls";  /* Chemin absolu pour "ls" */
        args[1] = NULL;       /* Pas d'arguments supplémentaires */
    }
    else
    {
        /* Préparer les arguments pour les autres commandes */
        args[0] = (char *)line;
        args[1] = NULL;
    }

    /* Créer un processus enfant pour exécuter la commande */
    pid = fork();
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
        do {
            waitpid(pid, &status, 0);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}
