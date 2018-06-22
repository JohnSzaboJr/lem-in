/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_check_spaces.c                                  :+:      :+:    :+:   */
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

int li_check_spaces(char **line, char ***room_data)
{
	if (ft_count_char(*line, ' ') != 2)
	{
		ft_freestrtab(room_data);
		return (0);
	}
	return (1);
}
