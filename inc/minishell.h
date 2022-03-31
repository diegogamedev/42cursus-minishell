#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include "libft.h"

typedef struct s_cmd
{
	char	*cmd_name;
	char	**cmd_argv;
	int		*is_pipe;
} t_cmd;

typedef struct s_shell
{
	t_cmd	*prev_input;
	char	*prev_output;
} t_shell;

extern t_shell shell_mem;

int		try_run(t_cmd *cmd);
char	*create_prompt(void);

#endif
