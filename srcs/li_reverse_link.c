/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_reverse_link.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/23 14:35:38 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../lem_in.h"
#include "../libft/libft.h"

int	li_reverse_link(t_links **link)
{
	t_links	*next;
	t_links	*tmp;
	t_links	*node;

	next = NULL;
	tmp = NULL;
	node = *link;
	while (node && node->next)
		node = node->next;
	while (*link)
	{
		next = (*link)->next;
		(*link)->next = tmp;
		tmp = *link;
		*link = next;
	}
	*link = node;
	return (1);
}
