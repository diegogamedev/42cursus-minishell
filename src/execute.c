#include <minishell.h>

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

void	try_run(t_cmd cmd)
{
	char	*aux;
	char	**hold;
	int		status;

	aux = get_exec_path(cmd.cmd_name);
	status = 0;
	if(aux != NULL)
	{
		if (!fork())
		{
			hold = ft_split(cmd.cmd_params, ' ');
			execve(aux, hold, 0);
		}
		else
			wait(&status);
		free(aux);
	}
}

void	example_func(t_cmd cmd)
{
	printf("example func called\n name: %s;\n", cmd.cmd_name);
}
