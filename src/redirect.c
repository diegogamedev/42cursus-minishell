#include <minishell.h>

void	redirect_to_file(char *content, int fd)
{
	if(!fcntl(fd, F_GETFD))
		fwrite(content, ft_strlen(content), sizeof(char), fd);
}

char	*exec_delimiter(const char *prompt)
{
	char	*str;
	char	*ret;
	char	*tmp;

	ret = ft_calloc(sizeof(char), 1);
	while (str = readline(prompt))
	{
		tmp = ft_strdup(ret);
		free(ret);
		ret = ft_strjoin(tmp, str);
		free(tmp);
	}
	return ret;
}


