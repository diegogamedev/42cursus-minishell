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
		else
			continue;
		tmp = ft_split(str, ' ');
		try_run(tmp);
	}
}
