/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:02:20 by dienasci          #+#    #+#             */
/*   Updated: 2022/03/26 18:26:08 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int main(int argc, const char *argv[], char *envp[])
{
	char	*str;
	char	**tmp;

	while (str = readline(">"))
	{
		tmp = ft_split(str, ' ');
		try_run(tmp);
	}
}
