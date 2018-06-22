/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_move_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 10:43:29 by jszabo            #+#    #+#             */
/*   Updated: 2018/06/21 10:43:31 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../lem_in.h"
#include "../libft/libft.h"

int li_move_ants(long long ants, t_rooms **room, t_links **link)
{
	t_links *node;
	int     ants_b;

	node = (*link)->next;
	ants_b = ants;
	free(*link);
	(*link) = node;
	li_reverse_link(link);
	node = *link;
	ft_printf("\n");
	while (ants)
	{
		ants--;
		li_ants_list(room, link);
		ft_printf("\n");
		*link = node;
	}
	while (((*link)->to) < ants_b)
	{
		li_ants_list2(room, link, ants_b);
		ft_printf("\n");
		*link = node;
	}
	return (1);
}
