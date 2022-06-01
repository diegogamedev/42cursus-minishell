#include <minishell.h>

void	ft_cd(t_cmd *cmd)
{
	char prompt[4096];
	
	chdir(cmd->cmd_argv[1]);
	free(shell_mem->prompt);
	shell_mem->prompt = ft_strjoin(getcwd(prompt, 4096), "> ");
}

void	ft_pwd(t_cmd *cmd)
{
	char *tmp;

	(void)cmd;
	tmp = ft_calloc(sizeof(char), 512);
	getcwd(tmp, 512);
	ft_putendl_fd(tmp, 1);
	free(tmp);
}

void ft_echo(t_cmd *cmd)
{
	int i;
	int eof;

	eof = ft_strncmp(cmd->cmd_argv[0], "-n", 2);
	i = 1 + eof;
	while (cmd->cmd_argv[i])
	{
		ft_putstr_fd(cmd->cmd_argv[i], 1);
		if (cmd->cmd_argv[i + 1] != NULL && (i + eof != 3 || i != 1))
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (!eof)
		ft_putchar_fd('\n', 1);
}

void	ft_exit(t_cmd *cmd)
{
	(void)cmd;
	shell_mem->exit_flag = 1;
}
