/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_pos_duplicate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/07/17 14:35:38 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../lem_in.h"
#include "../libft/libft.h"

int li_pos_duplicate(t_rooms *room, int pos)
{
	while (room)
	{
		if (room->pos == pos)
			return (1);
		room = room->next;
	}
	return (0);
}
