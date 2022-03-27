/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:02:20 by dienasci          #+#    #+#             */
/*   Updated: 2022/03/27 20:55:14 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include "stdio.h"

int main(int argc, const char *argv[], char *envp[])
{
	char	*str;
	char	**tmp;
	char	*prompt;

	prompt = create_prompt();
	while (str = readline(prompt))
	{
		tmp = ft_split(str, ' ');
		if(try_run(tmp))
			continue ;
		else
		{
			//other stuff
		}
	}
}
