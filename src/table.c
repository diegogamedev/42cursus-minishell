#include <minishell.h>

t_data	*find(const char *key)
{
	int	i;

	i = 0;
	while (shell_mem->table[i] != NULL)
	{
		if(ft_strncmp(key, shell_mem->table[i]->key, ft_strlen(key)) == 0)
			return shell_mem->table[i];
		i++;
	}
	return NULL;
}

static void	insert_table(shell_func func, char *name, int index)
{
	t_data *new_hash;

	new_hash = ft_calloc(sizeof(t_data *), 1);
	new_hash->key = name;
	new_hash->value = func;
	shell_mem->table[index] = new_hash;
}

void	init_table(void)
{
	printf("initializing table...\n");
	shell_mem->table = ft_calloc(sizeof(t_data *), 8);

	insert_table(&ft_echo, "echo", 0);
	insert_table(&ft_cd, "cd", 1);
	insert_table(&ft_pwd, "pwd", 2);
	insert_table(&example_func, "export", 3);
	insert_table(&example_func, "unset", 4);
	insert_table(&example_func, "env", 5);
	insert_table(&ft_exit, "exit", 6);

}
