#ifndef SIMPLESHELL-H
#define SIMPLESHELL_H

#define BUFSIZE 1024
#define TOKEN_BUFSIZE 128
#define TOKEN_DELIM " \t\r\n\a"
#define EXIT_IND 2

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <errno.h>


/**
 * struct shell - shell data for current session
 *
 * @argv: argument vector
 * @command: input command
 */
typedef struct shell
{
	char **argv;
	char *command;
} shell_t;


/**
 * struct builtin - builtins
 *
 * @name: value of builtin
 * @handl: builtin handler
 */
typedef struct builtin
{
	char *name;
	int (*handl)(shell_t *shell);
} builtin_t;

/**
 * struct env - contains addresses of all environment variables
 *
 * @name: name of variable
 * @content: content of variable
 * @next: next address of node
 */
typedef struct env
{
	char *name;
	char *content;
	struct env *next;
} list_env;

extern char **environ;

/* setup */
void initiate(shell_t *shell);
void uninitiate(shell_t *shell);
void handl_signint(int sig);
void repl(shell_t *shell);
void manage(int free_vars);
char **env_array(void);
void setEnv(const char *name, const char *value);
char *_getenv(const char *name, int var);
void free_arr(char **env);
int parse_command(shell_t *shell, char *command);
int executes(shell_t *shell);
int (*handlerFunction(const char *cmd))(shell_t *shell);
int shell_exit(shell_t *shell);
int shell_env(shell_t *shell);
int shell_setenv(shell_t *shell);
int shell_unsetenv(shell_t *shell);
int shell_cd(shell_t *shell);

/* utils */
void prompts(void);
char *readline(int *chr);
char **tokenize(char *s);

/* util.c */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_realloc2(char **ptr, unsigned int old_size, unsigned int new_size);

/* string functions */
char *_strdup(const char *s);
size_t _strlen(const char *s);
void *_memcpy(void *dest, const void *src, size_t n);
char *_strcat(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat2(char *dest, char *src, char *s);
char *shell_which(char *command);
#endif 
