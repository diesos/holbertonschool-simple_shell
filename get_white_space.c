#include "main.h"

/**
* purge_whiteSpace - remove leading and trailing whitespace
* @input: input string
* Return: string without leading and trailing whitespace
*/

char *purge_whiteSpace(char *input)
{
	char *isWhiteSpace = input;

	while (*isWhiteSpace == ' ' || *isWhiteSpace == '\t')
		isWhiteSpace++;

	if (*isWhiteSpace == '\n' || *isWhiteSpace == '\0')
		return (NULL);

	return (isWhiteSpace);
}
