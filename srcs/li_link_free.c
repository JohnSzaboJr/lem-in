/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_link_free.c                                     :+:      :+:    :+:   */
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

int	li_link_free(t_links **link)
{
	t_links	*tmp;

	while (*link)
	{
		tmp = (*link)->next;
		free(*link);
		*link = tmp;
	}
	return (1);
}
