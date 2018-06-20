/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_link_com.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/07/20 14:35:38 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../lem_in.h"
#include "../libft/libft.h"

int li_link_com(char **line)
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
		if (!ft_str_isalnum(*line + 2) ||
		!ft_strcmp(*line, "##start") ||
		!ft_strcmp(*line, "##end"))
			return (0);
		ft_printf("%s\n", *line);
	}
	else if (li_count_hash(*line) != 1 && li_count_hash(*line) != 2)
		return (0);
	return (1);
}
