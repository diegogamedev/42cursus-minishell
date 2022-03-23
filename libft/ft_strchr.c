/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:15:59 by dienasci          #+#    #+#             */
/*   Updated: 2022/03/23 20:44:25 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strchr(char const *s, int c)
{
	while (*(char *)s != '\0')
	{
		if (*(char *)s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*(char *)s == (char)c)
		return ((char *)s);
	return (NULL);
}
