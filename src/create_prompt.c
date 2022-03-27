/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:14:03 by coder             #+#    #+#             */
/*   Updated: 2022/03/27 19:44:38 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*create_prompt(void)
{
	char	*prompt;
	char	buffer[256];

	prompt = ft_strjoin(getcwd(buffer, 256), "> ");
	return (prompt);
}
