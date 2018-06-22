/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_new_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 11:56:54 by jszabo            #+#    #+#             */
/*   Updated: 2018/06/20 11:56:55 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../lem_in.h"
#include "../libft/libft.h"

int	li_new_child(t_path **new, t_path *room_path, t_path **child_path)
{
	if (!(*new = (t_path *)malloc(sizeof(**new))))
		return (0);
	(*new)->next = *child_path;
	*child_path = *new;
	(*child_path)->parent = room_path;
	return (1);
}
