#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
 * File: simple_shell.h
 * Auth: Your Name
 * Desc: Header file containing prototypes for all functions
 *       used in the simple shell project.
 */

extern char **environ;

/*
 * Function: execute_command
 * -------------------------
 * Executes the command entered by the user in the shell.
 *
 * line: The command line entered by the user.
 * home_directory: The path to the HOME directory.
 * previous_directory: The path to the directory used by the 'cd' command.
 *
 * Return: This function does not return anything.
 */
void execute_command(const char *line);

/*
 * Function: command_exists
 * ------------------------
 * Checks if a command exists in the system's PATH.
 *
 * cmd: The command to check.
 *
 * Return: 1 if the command exists, 0 otherwise.
 */
int command_exists(const char *cmd);

/*
 * Function: getenv
 * ----------------
 * Gets the value of an environment variable.
 *
 * name: The name of the environment variable.
 *
 * Return: The value of the environment variable if found,
 *         NULL otherwise.
 */
char *getenv(const char *name);

#endif /* SIMPLE_SHELL_H */
