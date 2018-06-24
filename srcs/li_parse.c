/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_parse.c                                         :+:      :+:    :+:   */
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

int	li_parse(char **line, long long *ants, t_rooms **room, t_links **link)
{
	int section;
	int	command;

	section = 0;
	command = 0;
	*link = NULL;
	while (get_next_line(0, line))
	{
		if (!(*line) || !((*line)[0]) || (*line)[0] == ' ' || (*line)[0] == 'L')
			return (li_free_error1(line, room));
		if ((section == 0 && !li_check_coms(line, room, &section)) ||
		(section == 1 && !li_check_ants(line, ants, room, &section)) ||
		(section == 2 && !li_check_rooms(line, room, &section)) ||
		(section == 3 && !li_check_links(line, room, link, &command)))
			return (0);
		free(*line);
	}
	free(*line);
	if (!(*room) || command)
		return (throw_error());
	return (1);
}
