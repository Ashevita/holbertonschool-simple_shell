#include "shell.h"

/**
 * _atoi - Converts a string to an integer.
 *
 * @prmString: Pointer to the string to be converted.
 *
 * Return: The integer value of the converted string.
 */
int _atoi(char *prmString)
{
	char sign = 1, current;
	int size = _strlen(prmString), cLoop;
	unsigned int number = 0;

	for (cLoop = 0; cLoop < size; cLoop++)
	{
		current = prmString[cLoop];

		if (current >= '0' && current <= '9')
		{
			number *= 10;
			number += current - '0';
		}
		else if (current == '-')
		{
			sign = -sign;
		}
		else if (number > 0)
		{
			break;
		}
	}

	return (sign * number);
}
