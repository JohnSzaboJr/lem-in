/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_check_links.c                                   :+:      :+:    :+:   */
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

int li_check_links(char **line, t_rooms **room, t_links **link)
{
	char    **links_data;
	t_links *new;

	if ((*line)[0] != '#' && (*line)[0] != 'L')
	{
		if (ft_count_char(*line, '-') != 1 || 
		!(links_data = ft_strsplit(*line, '-')) ||
		li_link_invalid(&links_data, &new))
			return (li_free_error2(line, room, link));
		new->next = *link;
		*link = new;
		if (!li_get_links(link, room, &links_data))
			return (li_free_error2(line, room, link));
		ft_freestrtab(&links_data);
		return (1);
	}
	if (!li_link_com(line) || !(*link))
		return (li_free_error2(line, room, link));
	return (1);
}
