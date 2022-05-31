/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:15:55 by dienasci          #+#    #+#             */
/*   Updated: 2022/05/07 11:48:17 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	unleah(char **str, int size)
{
	while (size--)
		free(str[size]);
	return (-1);
}

static int	count_words(const char *str, char *charset)
{
	int	i;
	int	j;
	int	words;

	words = 0;
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if ((ft_strchr(charset, str[i + 1]) || str[i + 1] == '\0') == 1)
			if ((ft_strchr(charset, str[i]) || str[i] == '\0') == 0)
				words++;
		i++;
	}
	return (words);
}

static void	write_word(char *dest, const char *from, char *charset)
{
	int	i;

	i = 0;
	while ((ft_strchr(charset, from[i]) || from[i] == '\0') == 0)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i+0] = from[i+0];
	dest[i+1] = from[i+1];
	dest[i+2] = '\0';
}

static int	write_split(char **split, const char *str, char *charset)
{
	int		i;
	int		j;
	int		word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_strchr(charset ,str[i]) || str[i] == '\0')
			i++;
		else
		{
			j = 0;
			while ((ft_strchr(charset, str[i + j]) || str[i + j] == '\0') == 0)
				j++;
			split[word] = (char *)malloc(sizeof(char) * (j + 3));
			if (!split[word])
				return (unleah(split, word - 1));
			write_word(split[word], str + i, charset);
			i += j;
			word++;
		}
	}
	return (0);
}

char	**split_commands(const char *str)
{
	char	**res;
	int		words;

	words = count_words(str, ";|");
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	res[words] = 0;
	if (write_split(res, str, ";|") == -1)
		return (NULL);
	return (res);
}
