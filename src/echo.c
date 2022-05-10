#include <minishell.h>

void	ft_echo(t_cmd *cmd)
{
	int	i;
	int	eof;

	i = 1;
	if(!ft_strncmp(cmd->cmd_argv[i], "-n", 2))
	{
		eof = 1;
		i++;
	}
	while(cmd->cmd_argv[i])
	{
		ft_putstr_fd(cmd->cmd_argv[i], 1);
		if(cmd->cmd_argv[i + 1] != NULL && (i + eof != 3 || i != 1))
			ft_putchar_fd(' ', 1);
		i++;
	}
	if(!eof)
		ft_putchar_fd('\n', 1);
}
