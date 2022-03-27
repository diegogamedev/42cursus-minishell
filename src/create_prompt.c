/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:14:03 by coder             #+#    #+#             */
/*   Updated: 2022/03/27 19:52:48 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*get_current_dir(void)
{
	char	*buffer;

	return (getcwd(buffer, 0));
}

char	*create_prompt(void)
{
	char	*current_dir;
	char	*prompt;

	current_dir = get_current_dir();
	prompt = ft_strjoin(current_dir, "> ");
	free(current_dir);
	return (prompt);	
}
