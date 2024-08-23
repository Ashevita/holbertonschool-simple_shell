#include "shell.h"

/**
 * handle_eof - Handle EOF (End-of-File) condition on stdin.
 *
 * Return: 0 if EOF is not encountered, or if EOF handling is successful.
 */
int handle_eof(void)
{
    if (feof(stdin) || _ferror(stdin))
    {
        exit(EXIT_SUCCESS);
    }
    return (0);
}

