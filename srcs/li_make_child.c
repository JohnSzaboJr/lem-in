/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_make_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 11:56:54 by jszabo            #+#    #+#             */
/*   Updated: 2018/06/20 11:56:55 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../lem_in.h"
#include "../libft/libft.h"

int li_make_child(t_links *link, t_path *room_path, t_path **child_path)
{
	t_path  *new;

	while (link)
	{
		if (room_path->room_num == link->from &&
		!li_repeat(link->to, room_path))
		{
			if (!li_new_child(&new, room_path, child_path))
				return (0);
			(*child_path)->room_num = link->to;
		}
		else if (room_path->room_num == link->to &&
		!li_repeat(link->from, room_path))
		{
			if (!li_new_child(&new, room_path, child_path))
				return (0);
			(*child_path)->room_num = link->from;
		}
		link = link->next;
	}
	return (1);
}
