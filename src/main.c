#include <minishell.h>
#include "stdio.h"

t_shell *shell_mem;

static void	clean_cmds()
{
	int i;
	int j;

	i = 0;
	while(shell_mem->curr_cmd_list[i])
	{
		j = 0;
		free(shell_mem->curr_cmd_list[i]->cmd_name);
		while(shell_mem->curr_cmd_list[i]->cmd_argv[j])
		{
			free(shell_mem->curr_cmd_list[i]->cmd_argv[j]);
			j++;
		}
		free(shell_mem->curr_cmd_list[i]);
	}
}

static void	init_seq()
{
	shell_mem = ft_calloc(sizeof(t_shell *), 1);
	shell_mem->prompt = ft_calloc(sizeof(char), 4100);
	init_table();
	init_pipes();
	ft_signals();
}

static void	exec(shell_func *list)
{
	int i;
	int child;

	i = 0;
	while (list[i] != NULL)
	{
		set_pipes();
		write(shell_mem->pipes->p_stdin[1], shell_mem->curr_cmd_list[i]->cmd_params, ft_strlen(shell_mem->curr_cmd_list[i]->cmd_params));
		child = fork();
		if(!child)
		{
			set_pipes();
			list[i](shell_mem->curr_cmd_list[i]);
			if (shell_mem->exit_flag == 1)
				break; 
		}
		shell_mem->last_cmd = shell_mem->curr_cmd_list[i];
		i++;
	}
}

static void	finish()
{
	int i = 0;
	close_pipes();
	free(shell_mem->last_cmd);
	while(shell_mem->table[i])
		free(shell_mem->table[i++]);
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
		clean_cmds();
		if (shell_mem->exit_flag == 1)
			break;
	}
	finish();
}
