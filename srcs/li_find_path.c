/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 10:43:29 by jszabo            #+#    #+#             */
/*   Updated: 2018/06/20 10:43:31 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../lem_in.h"
#include "../libft/libft.h"

int	li_find_path(t_rooms **room, t_links **link,
t_path **room_path, t_path **child_path)
{
	int		num;
	t_path	*new;

	new = NULL;
	if (!(li_create_list(*room, *link, *room_path, child_path)))
		return (0);
	if ((num = li_path_end(*child_path, *room)))
	{
		li_record_path(link, *child_path, num);
		li_path_free(child_path);
	}
	else
	{
		if (!li_find_path(room, link, child_path, &new))
		{
			li_path_free(child_path);
			return (0);
		}
		li_path_free(child_path);
	}
	return (1);
}
