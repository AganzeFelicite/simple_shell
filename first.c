#include "simpleShell.h"


/**
 * handlerFunction - gets appropriate handler for a supported
 * builtin command
 *
 * @command: input command
 * Return: function pointer to the handler
 */
int (*handlerFunction(const char *command))(shell_t *shell)
{
	unsigned int i;
	builtin_t builtins[] = {
		{"exit", shell_exit},
		{"env", shell_env},
		{"setenv", shell_setenv},
		{"unsetenv", shell_unsetenv},
		{NULL, NULL}
	};

	for (i = 0; builtins[i].name; i++)
	{
		if (_strcmp(command, builtins[i].name) == 0)
			return (builtins[i].handl);
	}
	return (NULL);
}
