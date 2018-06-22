/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_check_coms.c                                    :+:      :+:    :+:   */
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

int li_check_coms(char **line, t_rooms **room, int *section)
{
	int j;

	j = 0;
	while ((*line)[j] && (*line)[j] == '#')
		j++;
	if (j == 1 || j == 2)
	{
		if ((j == 1 && !ft_str_isalnumsp(*line + 1)) ||
			(j == 1 && (*line)[ft_strlen(*line) - 1] == ' ') ||
			(j == 2 && !ft_str_isalnum(*line + 2)))
			return (li_free_error1(line, room));
		if (!ft_strcmp(*line, "##start") ||
			!ft_strcmp(*line, "##end"))
			return (li_free_error1(line, room));
		ft_printf("%s\n", *line);
	}
	else if (j == 0)
		(*section)++;
	else
		return (li_free_error1(line, room));
	return (1);
}
