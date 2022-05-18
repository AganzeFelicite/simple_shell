#include "simpleShell.h"

/**
 * main - Runs the shell
 *
 * Return: 0
 */
int main(void)
{
	shell_t shell;

	initiate(&shell);
	signal(SIGINT, handl_signint);
	repl(&shell);
	uninitiate(&shell);
	return (0);
}
