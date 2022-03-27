#include "../inc/minishell.h"

char	*create_prompt(void)
{
	char	*prompt;
	char	buffer[256];

	prompt = ft_strjoin(getcwd(buffer, 256), "> ");
	return (prompt);
}
