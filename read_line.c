#include "shell.h"

/**
 * _fgets - Implémentation personnalisée de fgets.
 * @str: Pointeur vers le tampon de destination.
 * @num: Nombre maximum de caractères à lire.
 * @stream: Pointeur vers l'objet FILE représentant le flux à lire.
 *
 * Return: Pointeur vers le tampon de destination en cas de succès, ou NULL en cas d'échec.
 */
char *_fgets(char *str, int num, FILE *stream)
{
    char *result;

    result = fgets(str, num, stream);

    if (result == NULL)
    {
        if (feof(stream))
        {
            /* Fin de fichier atteinte */
            printf("EOF reached\n");
        }
        else if (ferror(stream))
        {
            /* Erreur lors de la lecture */
            printf("Error reading input\n");
        }
    }

    return (result);
}

