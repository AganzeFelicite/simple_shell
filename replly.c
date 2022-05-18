#include "shell.h"

/**
 * replly - Read-Eval-Print-Loop for the shell
 *
 * @shell: shell data
 */
void replly(shell_t *shell)
{
	char *cmd;
	int chr, flag, isLoop;

	do {
		isLoop = 1;
		prompt();

		cmd = readline(&chr);
		if (chr == -1)
		{
			free(cmd);
			manage(1);	/* free list */
			write(STDOUT_FILENO, "\n", 2);
			exit(EXIT_SUCCESS);
		}

		if (cmd == NULL)
			continue;

		flag = parse_command(shell, cmd);
		if (flag == EXIT_IND)
			isLoop = 0;
	} while (isLoop);
}
