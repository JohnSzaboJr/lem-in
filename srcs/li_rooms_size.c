/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_rooms_size.c                                    :+:      :+:    :+:   */
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

int	li_rooms_size(t_rooms *room)
{
	int i;

	i = 0;
	while (room)
	{
		room = room->next;
		i++;
	}
	return (i);
}
