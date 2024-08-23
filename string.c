#include "shell.h"

/**
 * _strncmp - Performs lexicographic comparison of two strings.
 * @s1: The first string.
 * @s2: The second string.
 * @n: The maximum number of characters to compare.
 *
 * Return: Negative if s1 < s2, positive if s1 > s2, zero if s1 == s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
    while (*s1 && *s2 && n > 0)
    {
        if (*s1 != *s2)
            return (*s1 - *s2);
        s1++;
        s2++;
        n--;
    }
    if (n == 0 || (*s1 == '\0' && *s2 == '\0'))
        return (0);
    else
        return (*s1 < *s2 ? -1 : 1);
}

/**
 * _strlen - Returns the length of a string.
 * @s: The string whose length to check.
 *
 * Return: Integer length of the string.
 */
int _strlen(const char *s)
{
    int i = 0;

    if (!s)
        return (0);

    while (*s++)
        i++;
    return (i);
}

/**
 * _strcpy - Copies a string.
 * @dest: The destination.
 * @src: The source.
 *
 * Return: Pointer to the destination.
 */
char *_strcpy(char *dest, const char *src)
{
    int i = 0;

    if (dest == src || src == 0)
        return (dest);
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

/**
 * _strdup - Duplicates a string.
 * @str: The string to duplicate.
 *
 * Return: Pointer to the duplicated string or NULL if insufficient memory.
 */
char *_strdup(const char *str)
{
    int length = 0;
    char *ret;

    if (str == NULL)
        return (NULL);
    while (*str++)
        length++;
    ret = malloc(sizeof(char) * (length + 1));
    if (!ret)
        return (NULL);
    for (length++; length--;)
        ret[length] = *--str;
    return (ret);
}

/**
 * _strcat - Concatenates two strings.
 * @dest: The destination buffer.
 * @src: The source buffer.
 *
 * Return: Pointer to the destination buffer.
 */
char *_strcat(char *dest, const char *src)
{
    char *ret = dest;

    while (*dest)
        dest++;
    while (*src)
        *dest++ = *src++;
    *dest = '\0';
    return (ret);
}


/**
 * _strcspn - Calculates the length of the initial segment of str
 *           which does not contain any characters from reject.
 * @str: The string to search.
 * @reject: The characters to exclude.
 *
 * Return: The length of the initial segment of str.
 */
size_t _strcspn(const char *str, const char *reject)
{
	const char *p;
	const char *r;
	size_t count = 0;

	for (p = str; *p != '\0'; p++)
	{
		for (r = reject; *r != '\0'; r++)
		{
			if (*p == *r)
				return (count);
		}
		count++;
	}

	return (count);
}

