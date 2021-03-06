/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:12:46 by fherbine          #+#    #+#             */
/*   Updated: 2018/01/15 17:07:42 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ch_includes/checker.h"

int		ft_check_piles(t_pile *pile_a, t_pile *pile_b)
{
	t_order	*orders;

	orders = ft_instructions();
	ft_debug(pile_a, pile_b);
	ft_do_actions(orders, &pile_a, &pile_b);
	ft_debug(pile_a, pile_b);
	free(orders);
	if ((pile_a && ft_pile_is_sorted(pile_a)) && !pile_b)
	{
		free(pile_a);
		free(pile_b);
		ft_kill(EXIT_SUCCESS);
	}
	return (0);
}
