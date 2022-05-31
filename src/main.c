#include <minishell.h>
#include "stdio.h"

t_shell *shell_mem;

void	free_2dpointer(void **tmp)
{
	while(tmp)
		tmp++;
}

static void	init_seq()
{
	shell_mem = ft_calloc(sizeof(t_shell *), 1);
	shell_mem->prompt = ft_calloc(sizeof(char), 4100);
	init_table();
	ft_signals();
}

static void	exec(shell_func *list)
{
	int i;
	int child;

	i = 0;
	while (list[i] != NULL)
	{
		child = fork();
		if(!child)
		{
			list[i](shell_mem->curr_cmd_list[i]);
			if (shell_mem->exit_flag == 1)
				break; 
		}
		else
			wait(&child);
		shell_mem->last_cmd = shell_mem->curr_cmd_list[i];
		i++;
	}
	while(list)
		free(list++);
}

static void	finish()
{
	free(shell_mem->last_cmd);
	free_2dpointer((void **)shell_mem->table);
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
		free_2dpointer((void **)shell_mem->curr_cmd_list);
		if (shell_mem->exit_flag == 1)
			break;
	}
	finish();
}
