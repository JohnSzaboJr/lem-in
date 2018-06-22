/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_duplicate_name.c                                :+:      :+:    :+:   */
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

int	li_duplicate_name(t_rooms *room)
{
	char	*name;

	name = room->name;
	room = room->next;
	while (room)
	{
		if (!ft_strcmp(room->name, name))
			return (1);
		room = room->next;
	}
	return (0);
}
