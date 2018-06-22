/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_largest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 10:43:29 by jszabo            #+#    #+#             */
/*   Updated: 2018/06/21 10:43:31 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../lem_in.h"
#include "../libft/libft.h"

int	li_largest(int num, t_links *link)
{
	while (link)
	{
		if (num < link->to)
			return (0);
		link = link->next;
	}
	return (1);
}
