/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_room_invalid.c                                  :+:      :+:    :+:   */
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

int	li_room_invalid(char ***room_data, t_rooms **new)
{
	if ((ft_strtablen(*room_data) != 3) ||
	!ft_str_isalnum((*room_data)[0]) ||
	!(*new = (t_rooms *)malloc(sizeof(**new))) ||
	!((*new)->name = ft_strnew(ft_strlen((*room_data)[0]))))
	{
		if (*new)
			free(*new);
		ft_freestrtab(room_data);
		return (1);
	}
	return (0);
}
