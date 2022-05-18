#include "simpleShell.h"


/**
 * _command - splits a string into an array
 *
 * @shell: shell data
 * @command: command input
 * Return: 0 on success otherwise 1 for error
 * or another integer
 */
int _command(shell_t *shell, char *command)
{
	int flag;
	int (*handl)(shell_t *shell);

	shell->command = command;
	shell->argv = tokenize(command);

	/* Check for builtins */
	handl = handlerFunction(shell->argv[0]);
	if (handl)
		flag = handl(shell);
	else
		flag = 1;

	if (flag == 1)
		flag = executes(shell);

	free(shell->argv);
	free(shell->command);

	return (flag); /* Success */
}
