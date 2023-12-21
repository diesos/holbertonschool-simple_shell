#include "main.h"

void free_memory(char **args, char *path)
{
	free(args);
	free(path);
}
