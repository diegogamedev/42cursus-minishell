#include <minishell.h>

void	ft_cd(t_cmd cmd)
{
	printf("%s -> %s\n", cmd.cmd_name, cmd.cmd_params);
}

void	ft_pwd(t_cmd cmd)
{
	printf("%s -> %s\n", cmd.cmd_name, cmd.cmd_params);
}

void ft_echo(t_cmd cmd)
{
	printf("%s -> %s\n", cmd.cmd_name, cmd.cmd_params);
}

void	ft_exit(t_cmd cmd)
{
	printf("%s -> %s\n", cmd.cmd_name, cmd.cmd_params);
}
