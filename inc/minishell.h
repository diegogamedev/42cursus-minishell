#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <libft.h>
# include <signal.h>

typedef enum operators
{
	none = 0,
	redir_input = 1 << 0,
	delimiter = 1 << 1,
	redir_output = 1 << 2,
	append = 1 << 3,
	pipe_op = 1 << 4
} ops;

typedef struct s_cmd
{
	char	*cmd_name;
	char	**cmd_argv;
	ops		fwrd_op;
} t_cmd;

typedef void (*shell_func)(t_cmd *);

typedef struct s_data
{
	char		*key;
	shell_func	value;
} t_data;

typedef struct s_shell
{
	int		*pipe;
	t_data	**table;
	t_cmd	**curr_cmd_list;
	int		exit_flag;
} t_shell;

extern t_shell *shell_mem;

void		ft_signals(void);
void		try_run(t_cmd *cmd);
char		*create_prompt(void);
shell_func	*get_exec_list(char **args);
char		**split_commands(const char *str);
void		init_table();
t_data		*find(const char *key);
void		ft_echo(t_cmd *cmd);
void		ft_cd(t_cmd *cmd);
void		ft_pwd(t_cmd *cmd);
void		ft_exit(t_cmd *cmd);
void		example_func(t_cmd *cmd);
#endif
