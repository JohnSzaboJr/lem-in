/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_room_coords.c                                   :+:      :+:    :+:   */
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

int	li_room_coords(char ***room_data, t_rooms **room)
{
	if ((*room_data)[1][0] == '-' || ft_hasnondigits((*room_data)[1]) ||
	ft_strlen((*room_data)[1]) > 18 || ft_atoll((*room_data)[1]) > 2147483647)
	{
		ft_printf("\n");
		ft_freestrtab(room_data);
		return (0);
	}
	(*room)->x = ft_atoll((*room_data)[1]);
	ft_printf(" %d", (*room)->x);
	if ((*room_data)[2][0] == '-' || ft_hasnondigits((*room_data)[2]) ||
	ft_strlen((*room_data)[2]) > 18 || ft_atoll((*room_data)[2]) > 2147483647)
	{
		ft_printf("\n");
		ft_freestrtab(room_data);
		return (0);
	}
	(*room)->y = ft_atoll((*room_data)[2]);
	if (li_duplicate_coord(*room))
	{
		ft_printf("\n");
		ft_freestrtab(room_data);
		return (0);
	}
	ft_printf(" %d\n", (*room)->y);
	return (1);
}
