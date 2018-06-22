/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_path_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 10:43:29 by jszabo            #+#    #+#             */
/*   Updated: 2018/06/20 10:43:31 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../lem_in.h"
#include "../libft/libft.h"

int	li_path_end(t_path *child_path, t_rooms *room)
{
	while (room->pos != 2)
		room = room->next;
	while (child_path)
	{
		if (child_path->room_num == room->num)
			return (room->num);
		child_path = child_path->next;
	}
	return (0);
}
