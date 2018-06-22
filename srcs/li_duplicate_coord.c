/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_duplicate_coord.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/07/18 14:35:38 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../lem_in.h"
#include "../libft/libft.h"

int	li_duplicate_coord(t_rooms *room)
{
	int	x;
	int	y;

	x = room->x;
	y = room->y;
	room = room->next;
	while (room)
	{
		if (room->x == x && room->y == y)
			return (1);
		room = room->next;
	}
	return (0);
}
