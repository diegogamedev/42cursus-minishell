/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:51:04 by dienasci          #+#    #+#             */
/*   Updated: 2022/03/27 16:07:05 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	try_run(char **argv)
{
	char	*aux;
	int		status;

	aux = get_exec_path(argv[0]);
	status = 0;
	if(aux != NULL)
	{
		if (!fork())
			execve(aux, argv, 0);
		else
			wait(&status);
		free(aux);
		return 1;
	}
	return 0;
}
