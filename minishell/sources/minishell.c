/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:35:00 by fherbine          #+#    #+#             */
/*   Updated: 2018/02/15 20:47:51 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
/*
int			launch_cmd(int argc, char **argv, char **envp)
{
}
*/
void		exec_cmd_line(void)
{
	t_commands	*cmds;
	char		*ln;
	int			n;

	n = get_next_line(0, &ln);
	if (n > 0)
	{
		cmds = get_all_cmds(ln);
		free(ln);
	}
}

void		prompt_get_cmd_line(char **envp)
{
	char	*prompt;

	while (1)
	{
		prompt = ms_get_prompt(envp);
		ft_prints("%s $ ", prompt);
		exec_cmd_line();
		free(prompt);
	}
}
