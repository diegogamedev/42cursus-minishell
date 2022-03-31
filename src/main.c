#include "../inc/minishell.h"
#include "stdio.h"

int main(int argc, const char *argv[], char *envp[])
{
	char	*str;
	char	**tmp;
	char	*prompt;
	t_cmd	*cur_cmd;
	static int (*const func_ptr[1])(t_cmd *) = {try_run};

	prompt = create_prompt();
	while (str = readline(prompt))
	{
		if (ft_strlen(str))
			add_history(str);
		else
			continue;
		cur_cmd = ft_calloc(1, sizeof(t_cmd));
		cur_cmd->cmd_argv= ft_split(str, ' ');
		cur_cmd->cmd_name = cur_cmd->cmd_argv[0];
		(func_ptr[0])(cur_cmd);
		free(cur_cmd);
	}
}
