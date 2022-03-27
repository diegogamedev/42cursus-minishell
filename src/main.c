/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:02:20 by dienasci          #+#    #+#             */
/*   Updated: 2022/03/27 16:15:25 by dienasci         ###   ########.fr       */
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
		try_run(tmp);
	}
}
