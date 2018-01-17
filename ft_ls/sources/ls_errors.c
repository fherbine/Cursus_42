/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:33:07 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/17 17:44:20 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void ls_usage(void)
{
	ft_prints_fd(2, "usage: ./ft_ls [-alrRt] [file ...]\n");
}

void	ft_not_found(char *elem)
{
	ft_prints_fd(2, "./ft_ls: %s: No such file or directory\n", elem);
}

void	ft_illegal_optn(char i_optn)
{
	ft_prints_fd(2, "./ft_ls: illegal option -- %c\n", i_optn);
	ls_usage();
	exit(EXIT_FAILURE);
}
