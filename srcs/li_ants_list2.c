/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_ants_list2.c                                    :+:      :+:    :+:   */
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

int li_ants_list2(t_rooms **room, t_links **link, int ants, int last)
{
	while (*link)
	{
		if ((*link)->to != 0 && (*link)->to < ants)
		{
			((*link)->to)++;
			ft_printf("L%d-%s", (*link)->to, li_get_room((*link)->from, *room));
			if ((*link)->from != last)
				ft_printf(" ");
		}
		else if ((*link)->to != 0 && (*link)->to >= ants)
			(*link)->to = 0;
		*link = (*link)->next;
	}
	return (1);
}
