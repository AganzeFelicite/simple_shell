#include "simpleShell.h"

/**
 * initiate - setup shell variables
 *
 * @shell: shell data
 */
void initiate(shell_t *shell)
{


	shell->argv = NULL;
	shell->command = NULL;

	manage(0);
}

/**
 * uninitiate - frees shell data
 *
 * @shell: struct holding the array we are freeing
 */
void uninitiate(shell_t *shell)
{
	(void)shell;
	manage(1);

	/**
	* for (i = 0; shell->argv[i]; i++)
	*	free(shell->argv[i]);
	*free(shell->argv);
	*/
}
