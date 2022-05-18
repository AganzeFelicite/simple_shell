#include "shell.h"


/**
 * _which - find the file for a command
 *
 * @command: command input
 * Return: 0 on failure otherwise 1
 */
char *_which(char *command)
{
	char *path, *path_dup, *spath, *file;
	struct stat st;

	path = _getenv("PATH", 0);
	if (!path)
		return (NULL);

	if (command[0] == '/')
	{
		if (stat(command, &st) == 0)
			return (_strdup(command));
	}

	path_dup = _strdup(path);
	spath = strtok(path_dup, ":");
	while (spath != NULL)
	{
		file = _strcat2(spath, "/", command);
		if (!file)
		{
			free(path_dup);
			write(STDERR_FILENO, ": allocation error\n", 18);
			exit(EXIT_FAILURE);
		}
		if (stat(file, &st) == 0)
		{
			free(path_dup);
			return (file);
		}
		free(file);
		spath = strtok(NULL, ":");
	}
	free(path_dup);

	return (NULL);
}

/**
 * execute - executes a command
 *
 * @shell: shell data
 * Return: 0 on success otherwise 1
 */
int execute(shell_t *shell)
{
	pid_t pid;
	int sys;
	char *file, **env = env_to_array();

	file = _which(shell->argv[0]);
	if (!file)
	{
		error_message(shell);
		return (1);
	}

	pid = fork();
	if (pid == 0)
	{
		execve(file, shell->argv, env);
	}
	else if (pid < 0)
	{
		perror(shell->argv[0]);
		return (1);
	}
	else
		wait(&sys);

	free_env_arr(env);
	free(file);
	return (1);
}
