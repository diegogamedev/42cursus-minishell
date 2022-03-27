/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:51:04 by dienasci          #+#    #+#             */
/*   Updated: 2022/03/27 20:50:59 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static char	*get_exec_path(char *path, char *name)
{
	char	*aux;

	aux = ft_calloc(sizeof(char), ft_strlen(path) + ft_strlen(name) + 1);
	aux = ft_strjoin(path, "/");
	aux = ft_strjoin(aux, name);
	if (access(aux, F_OK) == 0)
		return aux;
	free(aux);
	return NULL;
}

int try_run(char **argv)
{
	int		i;
	char	*aux;
	char	**paths;

	paths = ft_split(getenv("PATH"), ':');
	i = 0;
	while(paths[i])
	{
		aux = get_exec_path(paths[i], argv[0]);
		if(aux != NULL)
			if (execve(aux, (char *const *)argv, 0) != -1)
			{
				free(aux);
				return 1;
			}
		free(aux);
		i++;
	}
	return 0;
}
