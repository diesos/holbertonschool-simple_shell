#include "main.h"

/**
 * main - Entry point
 * @ac: argument count
 * @av: argument vector
 * Return: Always 0 (Success)
 */
int	main(int ac, char *av[])
{
	int exe;
	size_t len = 0;
	ssize_t read_input;
	char *input = NULL, *isWhiteSpace = NULL;

	if (ac != 1)
	{
		printf("Usage: %s\n", av[0]);
		return (EXIT_FAILURE);
	}

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("#Shell'Don$ ");
			fflush(stdout);
		}

		read_input = getline(&input, &len, stdin);
		if (read_input == -1)
			break;

		isWhiteSpace = purge_whiteSpace(input);

		if (isWhiteSpace == NULL)
			continue;

		if (strcmp(isWhiteSpace, "exit\n") == 0)
			break;

		exe = exec_cmd(isWhiteSpace);

		if (exe == -1)
			perror(av[0]);
	}
	free(input);

	return (0);
}
