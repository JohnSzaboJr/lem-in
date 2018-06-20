/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_new_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/07/19 14:35:38 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../lem_in.h"
#include "../libft/libft.h"

int li_new_room(t_rooms **new, char ***room_data, t_rooms **room)
{
	(*new)->next = *room;
	*room = *new;
	ft_strcpy((*room)->name, (*room_data)[0]);
	if (li_duplicate_name(*room))
	{
		ft_freestrtab(room_data);
		return (0);
	}
	ft_printf("%s", (*room)->name);
	(*room)->num = li_rooms_size(*room);
	return (1);
}
