#include "main.h"

/**
 * free_memory - Frees memory allocated for command arguments and path.
 *
 * @args: Double pointer to the array of command arguments.
 * @path: Pointer to the string representing the executable path.
 */

void	free_memory(char **args, char *path)
{
	free(args);
	free(path);
}
