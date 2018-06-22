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

int	li_ants_list(t_rooms **room, t_links **link)
{
	while (*link)
	{
		if (!((*link)->next))
		{
			((*link)->to)++;
			ft_printf("L%d-%s",
			(*link)->to, li_get_room((*link)->from, *room));
			if ((*link)->to == 1)
				break ;
		}
		else if ((*link)->next && (*link)->next->to > ((*link)->to))
		{
			((*link)->to)++;
			ft_printf("L%d-%s ",
			(*link)->to, li_get_room((*link)->from, *room));
		}
		*link = (*link)->next;
	}
	return (1);
}
