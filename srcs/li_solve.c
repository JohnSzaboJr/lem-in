/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_solve.c                                         :+:      :+:    :+:   */
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

int li_solve(long long ants, t_rooms **room, t_links **link)
{
	t_path      *room_path;
	t_path      *child_path;

	room_path = NULL;
	child_path = NULL;
	if (!li_find_path(room, link, &room_path, &child_path) ||
	!li_move_ants(ants, room, link))
	{
		li_room_free(room);
		li_link_free(link);
		return (throw_error());
	}
	return (1);
}
