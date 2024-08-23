#ifndef _SHELL_H
#define _SHELL_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

extern char **environ;

#define MAX_COMMAND_LENGTH 100
#define MAX_PATH_LENGTH 1024
#define MAX_COMMAND_WITH_PATH_LENGTH (MAX_PATH_LENGTH + MAX_COMMAND_LENGTH + 2)
#define MAX_ARGS 10
#define MAX_INPUT_LENGTH 1024

typedef int pid_t;

int execute_command(char *command, char *env[])
int check_env(const char *variable)
int _execvp(const char *file, char *as[], char *env[])
void get_exit(char *command)
int handle_eof(void)
int main(int ac, char *av[], char *env[])
char *_fgets(char *str, int num, FILE *stream)
char *_strcat(char *dest, const char *src
int _strncmp(const char *s1, const char *s2, size_t n)
int _strlen(const char *s)
char *_strcpy(char *dest, const char *src)
char *_strdup(const char *str)
size_t _strcspn(const char *str, const char *reject)

#endif /* _SHELL_H */

