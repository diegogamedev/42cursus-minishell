#include <minishell.h>

void	redirect_to_file(char *content, const char *filepath, const char *mode)
{
	FILE	*file;

	file = fopen(filepath, mode);
	if(file)
	{
		fwrite(content, ft_strlen(content), sizeof(char), file);
		fclose(file);
	}
}

char	*exec_operator(ops operator)
{
	if(operator == redir_input)
		return shell_mem->prev_input;
	else if(operator == redir_output || operator == pipe)
		return shell_mem->prev_output;
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