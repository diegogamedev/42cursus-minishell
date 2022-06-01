#include <minishell.h>

void    init_pipes()
{
    shell_mem->pipes = ft_calloc(1, sizeof(t_pipes));
    pipe(shell_mem->pipes->p_stdin);
    pipe(shell_mem->pipes->p_stdout);
    pipe(shell_mem->pipes->p_stderr);
}