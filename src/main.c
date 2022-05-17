#include <minishell.h>
#include "stdio.h"

t_shell *shell_mem;

void	init_shell_mem()
{
	shell_mem = ft_calloc(sizeof(t_shell *), 1);
	shell_mem->pipe = ft_calloc(sizeof(int), 2);
	pipe(shell_mem->pipe);
	init_table();
}

int main(int argc, const char *argv[], char *envp[])
{
	char		*str;
	char		prompt[256];
	char		**tmp;
	shell_func	*hold;
	int			i;

	init_shell_mem();
	ft_signals();
	shell_mem = ft_calloc(sizeof(t_shell *), 1);
	init_table();
	while (str = readline(ft_strjoin(getcwd(prompt, 256), "> ")))
	{
		i = 0;
		if (ft_strlen(str))
			add_history(str);
		else
			continue;
		tmp = split_commands(str);
		hold = get_exec_list(tmp);
		while (hold[i] != NULL)
		{
			hold[i](shell_mem->curr_cmd_list[i]);
			if (shell_mem->exit_flag == 1)
				break;
			i++;
		}
		free(tmp);
		free(hold);
	}
	//free routines
}
