#include"shell.c"
/**
 * check_env - Check if an environment variable is set.
 * @variable: The name of the environment variable to check.
 *
 * Return: 1 if the variable is set and not empty, 0 if not set or empty.
 */
int check_env(const char *variable)
{
	char **env;
	for (env = environ; *env != NULL;env++)
	{
		if (_strncmp(*env, variable, strlen(variable)) == 0)
		{
			run_ls_l();
			return (true)
		}
	}
	return(false);
}
