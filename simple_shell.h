#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;

/* Fonction pour exécuter une commande */
void execute_command(const char *line, const char *home_directory, char *previous_directory);

#endif /* SIMPLE_SHELL_H */
