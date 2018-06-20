/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_get_links.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/07/20 14:35:38 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../lem_in.h"
#include "../libft/libft.h"

int li_get_links(t_links **link, t_rooms **room, char ***links_data)
{
	if (!((*link)->from = li_room_number(*room, (*links_data)[0])))
	{
		ft_freestrtab(links_data);
		return (0);
	}
	ft_printf("%s", (*links_data)[0]);
	if (!((*link)->to = li_room_number(*room, (*links_data)[1])))
	{
		ft_freestrtab(links_data);
		ft_printf("\n");
		return (0);
	}
	ft_printf("-%s\n", (*links_data)[1]);
	return (1);
}
