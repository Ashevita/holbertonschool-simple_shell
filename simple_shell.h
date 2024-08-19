#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/*
 * File: simple_shell.h
 * Auth: Votre Nom
 * Desc: Header file containing prototypes for all functions
 *       used in the simple shell project.
 */

extern char **environ;

/*
 * Function: execute_command
 * -------------------------
 * Exécute la commande entrée par l'utilisateur dans le shell.
 *
 * line: La ligne de commande entrée par l'utilisateur.
 * home_directory: Le chemin du répertoire HOME.
 * previous_directory: Le chemin du répertoire utilisé par la commande 'cd'.
 *
 * Return: Cette fonction ne retourne rien, effectue l'exécution la commande
 */
void execute_command
(const char *line, const char *home_directory, char *previous_directory);

#endif /* SIMPLE_SHELL_H */
