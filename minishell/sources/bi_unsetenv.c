#include "../includes/minishell.h"

char	**bi_unsetenv(char **envp, t_shvar **shvar, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		envp = ftsh_del_envar(shvar, argv[i], envp);
		i++;
	}
	return (envp);
}