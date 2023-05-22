#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <errno.h>
#include <signal.h>

#define OUT STDOUT_FILENO
#define IN STDIN_FILENO
#define ERR STDERR_FILENO

extern char **environ;


/**
 * struct data - struct that contains all relevant data on runtime
 * @line: command line written by the user
 * @mytok: tokens of the command line
 * @argv: argument vector
 * @this_pid: process ID of the shell
 * @my_env: environment variable
 * @exitstat: last status of the shell
 * @linecount: lines counter
 */
typedef struct globals
{
	char **argv;
	char **my_env;
	int exitstat;
	char *line;
	char **mytok;
	char *this_pid;
	int linecount;
} globals_t;

/**
 * struct partition_s - single linked list
 * @parts: ; | &
 * @next: next node
 * Description: single linked list to store separators
 */
typedef struct partition_s
{
	char parts;
	struct partition_s *link;
} partition;

/**
 * struct cmd_s - single linked list
 * @cmd_args: command line
 * @next: next node
 * Description: single linked list to store command lines
 */
typedef struct cmd_s
{
	char *cmd_args;
	struct cmd_s *link;
} cmd_t;

/**
 * struct variable_s - single linked list
 * @len1: length of the variable
 * @myvalue: value of the variable
 * @len2: length of the value
 * @link: next node
 * Description: single linked list to store variables
 */
typedef struct variable_s
{
	int len1;
	int len2;
	char *myvalue;
	struct variable_s *link;
} variable_t;

/**
 * struct built_ins_s - Builtin struct for command mytok.
 * @exec_name: The exec_name of the command builtin i.e cd, exit, env
 * @f: data type pointer function.
 */
typedef struct built_ins_s
{
	char *exec_name;
	int (*call_func)(globals_t *globvar);
} my_built_ins;

/* aux_lists.c */
partition *partition_add_end(partition **h, char delim);
void free_partition(partition **h);
cmd_t *cmdln_add_end(cmd_t **h, char *line);
void free_cmd_t(cmd_t **h);

/* aux_lists2.c */
variable_t *varadd_node(variable_t **h, int lvar, char *var, int lval);
void free_variables(variable_t **h);

/* aux_str functions */
char *_strcat(char *destination, const char *source);
char *_strcpy(char *destination, char *source);
int _strcmp(char *str1, char *str2);
char *_strchr(char *str, char letter);
int _strspn(char *str, char *acpt);

/* aux_mem.c */
void _memcpy(void *nptr, const void *pptr, unsigned int sze);
void *_realloc(void *pptr, unsigned int o_sze, unsigned int n_sze);
char **dprllc(char **pptr, unsigned int o_sze, unsigned int n_sze);

/* aux_str2.c */
char *_strdup(const char *s);
int _strlen(const char *s);
int cmp_chars(char mystr[], const char *delim);
char *_strtok(char mystr[], const char *delim);
int num_detect(const char *str);

/* aux_str3.c */
void reverse_str(char *str);

/* check_syntax_error.c */
int rep_check(char *line, int idx);
int partition_err(char *line, int idx, char end);
int init_ind(char *line, int *idx);
void gen_syn_err(globals_t *globvar, char *line, int idx, int status);
int syn_err_ch(globals_t *globvar, char *line);

/* loop_parser.c */
char *ignore_comm(char *in);
void loop_parser(globals_t *globvar);
void display_prompt(void);
void display_err(char *message);
void display_out(char *message);

/* read_line.c */
char *line_buff(int *ret_eof);

/* split.c */
char *rep_sep(char *line, int stat);
void place_nds(partition **h_start, cmd_t **h_last, char *line);
void jump_to(partition **start_l, cmd_t **last_l, globals_t *globvar);
int process_cmd(globals_t *globvar, char *line);
char **split_to_arr(char *line);

/* rep_var.c */
void check_env(variable_t **h, char *in, globals_t *data);
int check_vars(variable_t **h, char *in, char *st, globals_t *data);
char *replaced_input(variable_t **h, char *line, char *n_in, int len);
char *rep_var(char *line, globals_t *globvar);

/* get_line.c */
void bring_line(char **lnptr, size_t *num, char *buf, size_t sze);
ssize_t get_line(char **lnptr, size_t *num, FILE *stream);

/* exec_line */
int exec_line(globals_t *globvar);

/* cmd_exec.c */
int is_cdir(char *path, int *idx);
char *_which(char *command, char **_environ);
int is_executable(globals_t *globvar);
int check_error_cmd(char *dir, globals_t *globvar);
int cmd_exec(globals_t *globvar);

/* env1.c */
char *_getenv(const char *exec_name, char **_environ);
int _env(globals_t *globvar);

/* env2.c */
char *copy_info(char *exec_name, char *value);
void set_env(char *exec_name, char *value, globals_t *globvar);
int _setenv(globals_t *globvar);
int _unsetenv(globals_t *globvar);

/* cd.c */
void cd_dot(globals_t *globvar);
void cd_to(globals_t *globvar);
void cd_previous(globals_t *globvar);
void cd_to_home(globals_t *globvar);

/* cd_shell.c */
int cd_shell(globals_t *globvar);

/* get_builtin */
int (*get_builtin(char *cmd))(globals_t *globvar);

/* _exit.c */
int exit_shell(globals_t *globvar);

/* aux_stdlib.c */
int get_len(int n);
char *aux_itoa(int n);
int _atoi(char *s);

/* aux_error1.c */
char *strcat_cd(globals_t *globvar, char *message, char *err, char *str);
char *error_get_cd(globals_t *globvar);
char *error_not_found(globals_t *globvar);
char *error_exit_shell(globals_t *globvar);

/* aux_error2.c */
char *error_get_alias(char **mytok);
char *error_env(globals_t *globvar);
char *error_syntax(char **mytok);
char *error_permission(char **mytok);
char *error_path_126(globals_t *globvar);


/* get_error.c */
int get_error(globals_t *globvar, int valuerr);

/* handle_C_sig.c */
void handle_C_sig(int sig);

/* aux_help.c */
void aux_help_env(void);
void aux_help_setenv(void);
void aux_help_unsetenv(void);
void aux_help_general(void);
void aux_help_exit(void);

/* aux_help2.c */
void aux_help(void);
void aux_help_alias(void);
void aux_help_cd(void);

/* get_help.c */
int get_help(globals_t *globvar);

void free_data(globals_t *globvar);

#endif
