#include <minishell.h>
#include "stdio.h"

t_shell *shell_mem;

static void	init_seq()
{
	shell_mem = ft_calloc(sizeof(t_shell *), 1);
	shell_mem->prompt = ft_calloc(sizeof(char), 4100);
	ft_signals();
}

static void	exec(shell_func *list)
{
	int i;

	i = 0;
	while (list[i] != NULL)
	{
		list[i](shell_mem->curr_cmd_list[i]);
		if (shell_mem->exit_flag == 1)
			break; 
		i++;
	}
}

static void	finish()
{
	free(shell_mem);
}

int main()
{
	char prompt[4096];
	char *str;
	char **tmp;

	init_seq();
	shell_mem->prompt = ft_strjoin(getcwd(prompt, 4096), "> ");
	while ((str = readline(shell_mem->prompt)))
	{
		if (ft_strlen(str))
			add_history(str);
		else
			continue;
		tmp = split_commands(str);
		exec(get_exec_list(tmp));
		free(str);
		free(shell_mem->last_cmd);
		if (shell_mem->exit_flag == 1)
			break;
	}
	finish();
}
