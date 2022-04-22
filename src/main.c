#include "../inc/minishell.h"
#include "stdio.h"

t_shell *shell_mem;

int main(int argc, const char *argv[], char *envp[])
{
	char		*str;
	char		*prompt;
	char		**tmp;
	shell_func	*hold;
	int			i;

	shell_mem = ft_calloc(sizeof(t_shell *), 1);
	prompt = create_prompt();
	init_table();
	i = 0;
	while (str = readline(prompt))
	{
		if (ft_strlen(str))
			add_history(str);
		else
			continue;
		tmp = ft_split_str(str, ";>|<&");
		hold = get_exec_list(tmp);
		while(hold[i])
			hold[i](tmp[i]);
		free(tmp);
		free(hold);
	}
}
