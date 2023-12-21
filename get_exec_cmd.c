#include "main.h"

/**
* exec_cmd - Executes a command
* @input: Input to be executed
* Return: 1 on success, -1 on failure
*/
int exec_cmd(char *input)
{
	int status;
	int exe;
	char *path, **args;
	pid_t pid;

	args = _get_token(input);
	if (args == NULL)
		return (-1);
	if (input[0] == '.' || input[0] == '/')
		path = strdup(input);
	else
		path = _get_env(args[0]);
	if (path == NULL)
	{
		free(args);
		return (-1);
	}
	pid = fork();
	if (pid < 0)
	{
		free_memory(args, path);
		return (-1);
	}
	else if (pid == 0)
	{
		exe = execve(path, args, environ);
		if (exe < 0)
		{
			free_memory(args, path);
			return (-1);
		}
		exit(1);
	}
	else
	{
		wait(&status);
		free_memory(args, path);
	}
	return (1);
}
