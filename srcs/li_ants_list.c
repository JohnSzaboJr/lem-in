/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_ants_list.c                                     :+:      :+:    :+:   */
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

int li_ants_list(t_rooms **room, t_links **link)
{
	t_links *prev;

	prev = NULL;
	while (*link)
	{
		if (!prev)
		{
			((*link)->to)++;
			ft_printf("L%d-%s", (*link)->to, li_get_room((*link)->from, *room));
			if ((*link)->to == 1)
				break ;
			else
				ft_printf(" ");
		}
		else if (prev && prev->to > ((*link)->to) + 1)
		{
			((*link)->to)++;
			ft_printf("L%d-%s", (*link)->to, li_get_room((*link)->from, *room));
			if ((*link)->to != 1)
				ft_printf(" ");
		}
		prev = *link;
		*link = (*link)->next;
	}
	return (1);
}
