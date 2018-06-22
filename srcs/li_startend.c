/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_startend.c                                      :+:      :+:    :+:   */
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

void	li_startend(int *start, int *end, t_rooms **room)
{
	if (*start && !(*end))
		(*room)->pos = 0;
	else if (!(*start) && *end)
		(*room)->pos = 2;
	else
		(*room)->pos = 1;
	*start = 0;
	*end = 0;
}
