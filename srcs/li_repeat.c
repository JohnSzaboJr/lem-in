/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_repeat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 12:13:43 by jszabo            #+#    #+#             */
/*   Updated: 2018/06/20 12:13:45 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../lem_in.h"
#include "../libft/libft.h"

int li_repeat(int num, t_path *room_path)
{
	while (room_path)
	{
		if (room_path->room_num == num)
			return (1);
		room_path = room_path->parent;
	}
	return (0);
}
