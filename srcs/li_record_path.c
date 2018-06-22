/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_record_path.c                                   :+:      :+:    :+:   */
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

int	li_record_path(t_links **link, t_path *child_path, int num)
{
	t_links	*new;

	li_link_free(link);
	*link = NULL;
	while (child_path->room_num != num)
		child_path = child_path->next;
	while (child_path)
	{
		if (!(new = (t_links *)malloc(sizeof(*new))))
			return (0);
		new->next = *link;
		*link = new;
		(*link)->from = child_path->room_num;
		(*link)->to = 0;
		child_path = child_path->parent;
	}
	return (1);
}
