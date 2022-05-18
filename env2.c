#include "simpleShell.h"

/**
 * free_arr - frees created environment array
 *
 * @env: malloced environment array
 */
void free_arr(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
	{
		free(env[i]);
	}
	free(env);
}
