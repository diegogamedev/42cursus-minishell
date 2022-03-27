/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:02:20 by dienasci          #+#    #+#             */
/*   Updated: 2022/03/28 00:41:08 by coder            ###   ########.fr       */
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
		if (ft_strlen(str))
			add_history(str);
		tmp = ft_split(str, ' ');
		try_run(tmp);
	}
}
