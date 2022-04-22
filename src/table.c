#include "../inc/minishell.h"

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

void	print_table()
{
	int i;

	i = 0;
	printf("avaliable functions:\n");
	while(shell_mem->table[i] != NULL)
	{
		printf("[%d] = %p, %s\n", i, shell_mem->table[i]->value, shell_mem->table[i]->key);
		i++;
	}
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
	insert_table(&try_run, "echo", 0);
	insert_table(&try_run, "cd", 1);
	insert_table(&try_run, "pwd", 2);
	insert_table(&try_run, "export", 3);
	insert_table(&try_run, "unset", 4);
	insert_table(&try_run, "env", 5);
	insert_table(&try_run, "exit", 6);
	shell_mem->table[7] = NULL;
	print_table();
}
