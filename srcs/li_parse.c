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

int li_parse(char **line, long long *ants, t_rooms **room, t_links **link)
{
	int i;
	int section;

	i = 0;
	section = 0;
	*link = NULL;
	while (get_next_line(0, line))
	{
		if (!(*line) || !((*line)[0]) || (*line)[0] == ' ' || (*line)[0] == 'L')
			return (li_free_error1(line, room));
		if (section == 0 && !li_check_coms(line, room, &section))
			return (0);
		if (section == 1 && !li_check_ants(line, ants, room, &section))
			return (0);
		if (section == 2 && !li_check_rooms(line, room, &section))
			return (0);
		if (section == 3 && !li_check_links(line, room, link))
			return (0);
		free(*line);
		i++;
	}
	free(*line);
	if (!(*room))
		return (throw_error());
	return (1);
}
