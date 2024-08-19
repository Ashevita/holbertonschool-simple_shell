#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

// Prototype de la variable globale pour passer l'environnement à execve
extern char **environ;

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    char *args[3];
    pid_t pid;
    int status;
    char *home_directory = "/home"; // Chemin par défaut pour HOME
    char previous_directory[1024] = "";

    while (1) {
        // Afficher le prompt
        printf("simple_shell> ");
        fflush(stdout);

        // Lire la ligne de commande
        nread = getline(&line, &len, stdin);
        if (nread == -1) {
            if (errno == EINTR) {
                continue;
            }
            break;
        }

        // Retirer le saut de ligne de la commande
        line[strcspn(line, "\n")] = '\0';

        // Ignorer les lignes vides
        if (strlen(line) == 0) {
            continue;
        }

        // Traiter la commande "cd" séparément
        if (strncmp(line, "cd", 2) == 0) {
            char *path = strtok(line + 3, " ");
            char current_directory[1024];

            if (path == NULL || strcmp(path, "~") == 0) {
                path = home_directory; // Aller au répertoire HOME par défaut
            } else if (strcmp(path, "-") == 0) {
                if (strlen(previous_directory) == 0) {
                    fprintf(stderr, "simple_shell: cd: OLDPWD not set\n");
                    continue;
                }
                path = previous_directory; // Aller au répertoire précédent
            }

            if (getcwd(current_directory, sizeof(current_directory)) != NULL) {
                strncpy(previous_directory, current_directory, sizeof(previous_directory) - 1);
            }

            if (chdir(path) != 0) {
                perror("cd");
            }
            continue;
        }

        // Traiter la commande "pwd" séparément
        if (strcmp(line, "pwd") == 0) {
            char cwd[1024];
            if (getcwd(cwd, sizeof(cwd)) != NULL) {
                printf("%s\n", cwd);
            } else {
                perror("pwd");
            }
            continue;
        }

        // Préparer les arguments pour la commande "ls"
        if (strcmp(line, "ls") == 0) {
            args[0] = "/bin/ls";
            args[1] = NULL;
        } else {
            // Préparer les arguments pour les autres commandes
            args[0] = line;
            args[1] = NULL;
        }

        // Créer un processus enfant pour exécuter la commande
        pid = fork();
        if (pid == -1) {
            perror("fork");
            continue;
        } else if (pid == 0) {
            // Processus enfant : exécuter la commande
            if (execve(args[0], args, environ) == -1) {
                perror("execve");
                _exit(EXIT_FAILURE);
            }
        } else {
            // Processus parent : attendre que le processus enfant se termine
            do {
                waitpid(pid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
    }

    // Libérer la mémoire allouée
    free(line);

    return 0;
}
