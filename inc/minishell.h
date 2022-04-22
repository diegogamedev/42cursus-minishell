#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include "libft.h"

typedef enum operators
{
	redir_input = 0,
	delimiter = 1,
	redir_output = 2,
	append = 3,
	pipe_op = 4
} ops;

typedef struct s_cmd
{
	char	*cmd_name;
	char	**cmd_argv;
	ops	fwrd_op;
} t_cmd;

typedef void (*shell_func)(t_cmd *);

typedef struct s_data
{
	char *key;
	shell_func value;
} t_data;

typedef struct s_shell
{
	t_cmd	*prev_input;
	char	*prev_output;
	t_data	*table[10];
} t_shell;

extern t_shell *shell_mem;

void		try_run(t_cmd *cmd);
char		*create_prompt(void);
shell_func	*get_exec_list(char **args);
char		**ft_split_str(const char *str, char *s);
void		init_table();
t_data		*find(const char *key);

#endif
