#include <minishell.h>

void	init_pipes()
{
	shell_mem->pipes = ft_calloc(1, sizeof(t_pipes));
	pipe(shell_mem->pipes->p_stdin);
	pipe(shell_mem->pipes->p_stdout);
	pipe(shell_mem->pipes->p_stderr);
}

void	set_pipes()
{
	dup2(shell_mem->pipes->p_stdin[0], STDIN_FILENO);
	dup2(shell_mem->pipes->p_stdout[1], STDOUT_FILENO);
	dup2(shell_mem->pipes->p_stderr[1], STDERR_FILENO);
}

void	close_pipes()
{
	close(shell_mem->pipes->p_stdin[0]);
	close(shell_mem->pipes->p_stdin[1]);
	close(shell_mem->pipes->p_stdout[0]);
	close(shell_mem->pipes->p_stdout[1]);
	close(shell_mem->pipes->p_stderr[0]);
	close(shell_mem->pipes->p_stderr[1]);
}
