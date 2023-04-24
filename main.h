#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <limits.h>

#define wexitstat(status) (((status) >> 8) & 0xff)

extern char **environ;

/*digit handling*/
int count_digits(int num);
void to_string(int num, char *str);
int _atoi(char *s);
int _isdigit(char *str);
int tokencount(char **tok);

/*String Handling Functions*/
int _strlen(char *str);
char *str_cpy(char *dest, char *src);
int _strncmp(const char *str1, const char *str2, size_t len);
char *_strcat(char *dest, char *source);
int _strcmp(char *s1, char *s2);

/*Custom Functions*/
char **splitstr(char *line, char *linecopy);
void exct(char *exe_name, char **line, char **cpy, char ***tok, int *ln);
void my_getline(char *argv[]);
void non_interactive_mode(char *argv[]);
char *_getenv(char *path);
char *find_path(char *cmd);
int check_path(char *cmd);
void forking(int r, char *nm, char **l, char **cp, char ***t, int *e, int *ln);

/*Built In Functions*/
int ch_builtin(char ***bcmd, char **cp, char **li, char *nm, int *es, int *ln);
void _printenv(void);
void exit_args(char ***bcmd, char **cp, char **li, char *nm, int *es, int *ln);
void echo_args(char **tok, int *es);

/*Memory management*/
void free_tokens(char **tokenarr);
void free_alloced_mem_on_exit(char **lineptr, char **copy, char ***tokenarr);
char *_strdup(char *str);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/*Error Handling*/
void malloc_checkptr(char *s);
void malloc_checkdptr(char **s);
void getret(ssize_t ret, char **line, char **cpy, char ***tokenarr, int *es);
void write_cmd_err(char *exec_name, char *err_name, int *ln);
void write_exec_err(char *exec_name, int *ln);
void write_exec_err2(char *exec_name, char *err_name, char *num, int *ln);

#endif /*_MAIN_H_*/
