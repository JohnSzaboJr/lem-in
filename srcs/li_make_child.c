/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_make_child.c                                    :+:      :+:    :+:   */
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

int li_make_child(t_links *link, t_path *room_path, t_path **child_path)
{
    t_path *new;

    while (link)
    {
        if (room_path->room_num == link->from && !li_repeat(link->to, room_path))
        {
            if (!(new = (t_path *)malloc(sizeof(*new))))
                return (0);
            new->next = *child_path;
            *child_path = new;
            (*child_path)->parent = room_path;
            (*child_path)->room_num = link->to;
        }
        else if (room_path->room_num == link->to && !li_repeat(link->from, room_path))
        {
            if (!(new = (t_path *)malloc(sizeof(*new))))
                return (0);
            new->next = *child_path;
            *child_path = new;
            (*child_path)->parent = room_path;
            (*child_path)->room_num = link->from;
        }
        link = link->next;
    }
    return (1);
}