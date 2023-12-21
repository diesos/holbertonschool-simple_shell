#include "main.h"

/**
 * _get_token - Splits a string into tokens
 * @input: The string to be split
 *
 * Return: An array of strings representing the tokens
 */
char	**_get_token(char *input)
{
	char *token;
	char **args = NULL;
	int argCount = 0;
	int argsSize = 10;

	args = calloc(argsSize, sizeof(char *));

	if (args == NULL)
	{
		perror("Memory allocation failed");
		exit(1);
	}

	token = strtok(input, " \t\n");

	if (token == NULL)
	{
		free(args);
		return (NULL);
	}

	while (token != NULL)
	{
		args[argCount++] = token;

		if (argCount >= argsSize)
		{
			argsSize *= 2;
			args = realloc(args, argsSize * sizeof(char *));
			if (args == NULL)
			{
				perror("Memory allocation failed");
				exit(1);
			}
		}
		token = strtok(NULL, " \t\n");
	}
	args[argCount] = NULL;

	return (args);
}
