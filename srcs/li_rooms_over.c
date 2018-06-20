/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_rooms_over.c                                    :+:      :+:    :+:   */
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

int li_rooms_over(char ***room_data, t_rooms **room, int *section)
{
	if ((ft_strtablen(*room_data) != 3) && (*room))
		{
			ft_freestrtab(room_data);
			(*section)++;
			return (1);
		}
	return (0);
}
