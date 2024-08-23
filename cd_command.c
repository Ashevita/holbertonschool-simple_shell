#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * execute_command - Execute a command in a child process with a custom environment
 * @command: The command to execute
 * @env: The environment variables to pass to the command
 *
 * Return: The exit status of the command, or -1 on error
 */
int execute_command(char *command, char *env[])
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid < 0)
    {
        perror("Fork failed");
        return (-1);
    }
    else if (pid == 0)
    {
        if (execle("/bin/sh", "sh", "-c", command, NULL, env) == -1)
        {
            perror("execle failed");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        if (waitpid(pid, &status, 0) == -1)
        {
            perror("waitpid failed");
            return (-1);
        }

        if (WIFEXITED(status))
        {
            return (WEXITSTATUS(status));
        }
        else
        {
            return (-1);
        }
    }

    return (0);
}

