/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_room_com.c                                      :+:      :+:    :+:   */
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

int	li_room_com(char **line, t_rooms **room, int *start, int *end)
{
	if (li_count_hash(*line) == 1)
	{
		if (!ft_str_isalnumsp(*line + 1) ||
		((*line)[ft_strlen(*line) - 1] == ' '))
			return (0);
		ft_printf("%s\n", *line);
	}
	else if (li_count_hash(*line) == 2)
	{
		if (!ft_str_isalnum(*line + 2) || !((*line)[2]))
			return (0);
		if (!ft_strcmp(*line, "##start"))
			*start = 1;
		if (!ft_strcmp(*line, "##end"))
			*end = 1;
		if ((*start) && (*end))
			return (0);
		if ((*start && li_pos_duplicate(*room, 0)) ||
			(*end && li_pos_duplicate(*room, 2)))
			return (0);
		ft_printf("%s\n", *line);
	}
	else
		return (0);
	return (1);
}
