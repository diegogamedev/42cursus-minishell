#include "../inc/minishell.h"

static char	*get_exec_path(char *name)
{
	int		i;
	char	*aux;
	char	**paths;

	paths = ft_split(getenv("PATH"), ':');
	i = 0;
	while (paths[i])
	{
		aux = ft_calloc(sizeof(char), ft_strlen(paths[i]) + ft_strlen(name) + 1);
		aux = ft_strjoin(paths[i], "/");
		aux = ft_strjoin(aux, name);
		if (access(aux, F_OK) == 0)
			return aux;
		free(aux);
		i++;
	}
	return NULL;
}

void	try_run(t_cmd *cmd)
{
	char	*aux;
	int		status;

	aux = get_exec_path(cmd->cmd_name);
	status = 0;
	if(aux != NULL)
	{
		if (!fork())
			execve(aux, (char * const *)cmd->cmd_argv, 0);
		else
			wait(&status);
		free(aux);
	}
}

void	example_func(t_cmd *cmd)
{
	int i;
	printf("example func called\n name: %s;\n args: ", cmd->cmd_name);
	i = 0;
	while(cmd->cmd_argv[i])
	{
		printf("%s, ", cmd->cmd_argv[i]);
		i++;
	}
	printf("\b\b.\noperators: %d\n", cmd->fwrd_op);
}
