#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"

/**
 * get_execvp - Search for an executable file in PATH and execute it
 * @file: The name of the file to execute
 * @argv: Array of pointers to arguments for the executable
 * @env: The environment
 * Return: Upon success, execvp() does not return. On failure, -1 is returned,
 * and errno is set appropriately.
 */
int _execvp(const char *file, char *as[], char *env[])
{
	size_t path_len;
	size_t token_len;
	size_t file_len;
	char *path, *path_copy, *token, *full_path;

	path = _getenv("PATH", env);
	if (path == NULL)
		return (-1);
	path_len = strlen(path);
	path_copy = malloc(path_len + 1);
	if (path_copy == NULL)
		return (-1);
	strcpy(path_copy, path);
	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		token_len = strlen(token);
		file_len = strlen(file);

		full_path = malloc(token_len + file_len + 2);
		if (full_path == NULL)
		{
			fprintf(stderr, "Memory allocation error.\n");
			free(path_copy);
			return (-1);
		}
		sprintf(full_path, "%s/%s", token, file);
		if (access(full_path, X_OK) == 0)
		{
			execve(full_path, as, env);
			perror("execve");
			free(full_path);
			free(path_copy);
			exit(EXIT_FAILURE);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	fprintf(stderr, "./shell: '%s' No such file or directory \n", file);
	exit(EXIT_FAILURE);
}
