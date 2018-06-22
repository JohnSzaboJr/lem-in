/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 10:56:41 by jszabo            #+#    #+#             */
/*   Updated: 2018/06/20 10:56:42 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../lem_in.h"
#include "../libft/libft.h"

int li_create_list(t_rooms *room, t_links *link,
t_path *room_path, t_path **child_path)
{
	t_path  *new;

	if (!room_path)
	{
		if (!(new = (t_path *)malloc(sizeof(*new))))
			return (0);
		new->parent = room_path;
		new->next = *child_path;
		*child_path = new;
		while (room->pos != 0)
			room = room->next;
		(*child_path)->room_num = room->num;
	}
	else
	{
		while (room_path)
		{
			if (!li_make_child(link, room_path, child_path))
				return (0);
			room_path = room_path->next;
		}
	}
	if (!(*child_path))
		return (0);
	return (1);
}
