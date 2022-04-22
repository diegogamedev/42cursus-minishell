#include "../inc/minishell.h"

extern t_shell *shell_mem;

static int	count_2d_array(char **args)
{
	int ret;

	ret = 0;
	while (args[ret])
		ret++;
	return ret;
}

shell_func	*get_exec_list(char **args)
{
	t_data			*hold;
	shell_func*		commands;
	int				i;
	char			**tmp;

	commands = ft_calloc(sizeof(shell_func *), count_2d_array(args));
	i = 0;
	while(args[i])
	{
		tmp = ft_split(args[i], ' ');
		hold = find(tmp[0]);
		if(!hold)
			commands[i] = try_run;
		else
			commands[i] = hold->value;
		i++;
	}
	return commands;
}
