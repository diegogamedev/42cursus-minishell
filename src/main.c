#include <minishell.h>
#include "stdio.h"

t_shell *shell_mem;

static void	init_seq()
{
	shell_mem = ft_calloc(sizeof(t_shell *), 1);
	shell_mem->pipe = ft_calloc(sizeof(int), 2);
	pipe(shell_mem->pipe);
	init_table();
	ft_signals();
}

static void	exec(shell_func *list)
{
	int i;

	while (list[i] != NULL)
	{
		list[i](shell_mem->curr_cmd_list[i]);
		if (shell_mem->exit_flag == 1)
			break;
		shell_mem->last_cmd = shell_mem->curr_cmd_list[i];
		i++;
	}
	free(list);
}

static void	finish()
{
	free(shell_mem->last_cmd);
	free(shell_mem->table);
	free(shell_mem->pipe);
}

int main(int argc, const char *argv[], char *envp[])
{
	init_seq();
	char *str;
	char prompt[256];
	char **tmp;

	init_seq();
	while (str = readline(ft_strjoin(getcwd(prompt, 256), "> ")))
	{
		if (ft_strlen(str))
			add_history(str);
		else
			continue;
		tmp = split_commands(str);
		exec(get_exec_list(tmp));
		free(tmp);
		if (shell_mem->exit_flag == 1)
			break;
	}
	finish();
}
