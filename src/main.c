#include <minishell.h>
#include "stdio.h"

t_shell *shell_mem;

int main(int argc, const char *argv[], char *envp[])
{
	char		*str;
	char		prompt[256];
	char		**tmp;
	shell_func	*hold;
	int			i;

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
			i++;
		}
		free(tmp);
		free(hold);
		if(shell_mem->exit_flag == 1)
			break ;
	}
	//free routines
}
