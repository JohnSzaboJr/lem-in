/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_free_error2.c                                   :+:      :+:    :+:   */
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

int	li_free_error2(char **line, t_rooms **room, t_links **link)
{
	li_link_free(link);
	li_room_free(room);
	free(*line);
	return (throw_error());
}
