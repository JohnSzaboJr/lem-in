/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_check_ants.c                                    :+:      :+:    :+:   */
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

int	li_check_ants(char **line, long long *ants, t_rooms **room, int *section)
{
	static int	done = 0;

	if (done)
	{
		(*section)++;
		return (1);
	}
	if ((*line)[0] == '-' || ft_hasnondigits(*line))
		return (li_free_error1(line, room));
	*ants = ft_atoll(*line);
	if (*ants > 2147483647 || !(*ants))
		return (li_free_error1(line, room));
	ft_printf("%lld\n", *ants);
	done = 1;
	return (1);
}
