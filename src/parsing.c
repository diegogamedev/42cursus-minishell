#include <minishell.h>

extern t_shell *shell_mem;

static ops get_cmd_operators(char *argv)
{
	int i;
	ops	ret;

	i = 0;
	ret = none;
	while(argv[i])
	{
		if (argv[i] == '>')
		{
			if (argv[i] != '>')
				ret |= redir_output;
			else
			{
				ret |= append;
				i++;
			}
		}
		else if (argv[i] == '<')
		{
			if (argv[i] != '<')
				ret |= redir_input;
			else
			{
				ret |= delimiter;
				i++;
			}
		}
		else if (argv[i] == '|')
			ret |= pipe_op;
		i++;
	}
	return ret;
}

static int	count_2d_array(char **args)
{
	int ret;

	ret = 0;
	while (args[ret])
		ret++;
	return ret;
}

static void	add_command(char *full, char **argv, int operator, int index)
{
	t_cmd cmd;

	cmd.cmd_name = ft_strdup(argv[0]);
	cmd.cmd_params = ft_strdup(full);
	cmd.fwrd_op = operator;
	shell_mem->curr_cmd_list[index] = cmd;
}

shell_func	*get_exec_list(char **args)
{
	t_data			hold;
	shell_func*		commands;
	int				i;
	char			**tmp;

	i = count_2d_array(args);
	commands = ft_calloc(sizeof(shell_func *), i + 1);
	shell_mem->curr_cmd_list = ft_calloc(sizeof(t_cmd *), i);
	i = 0;
	while(args[i])
	{
		tmp = ft_split(args[i], ' ');
		hold = find(tmp[0]);
		if(!hold.value)
			commands[i] = try_run;
		else
			commands[i] = hold.value;
		add_command(args[i], tmp, get_cmd_operators(args[i]), i);
		i++;
		free(args[i]);
	}
	commands[i] = NULL;
	return commands;
}
