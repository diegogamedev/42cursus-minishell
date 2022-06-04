#include <minishell.h>

t_data	find(const char *key)
{
	int	i;
	t_data ret;

	ret.key = "";
	ret.value = NULL;
	i = 0;
	while (i < 1)
	{
		if(ft_strncmp(key, get_table()[i].key, ft_strlen(key)) == 0)
			return get_table()[i];
		i++;
	}
	return ret;
}

t_data	*get_table(void)
{
	static t_data table[4];
	if(table[0].value == NULL)
	{
		table[0].key = ft_strdup("echo");
		table[0].value = &ft_echo;
		table[1].key = ft_strdup("cd");
		table[1].value = &ft_cd;
		table[2].key = ft_strdup("exit");
		table[2].value = &ft_exit;
		table[3].key = ft_strdup("pwd");
		table[3].value = &ft_pwd;
	}
	return table;
}
