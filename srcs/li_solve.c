/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_solve.c                                         :+:      :+:    :+:   */
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

int li_solve(long long ants, t_rooms **room, t_links **link)
{
    t_path      *room_path;
    t_path      *child_path;
    t_list_num  *path;

    room_path = NULL;
    child_path = NULL;
    path = NULL;
    //ettol kezdve kell recursion
    li_create_list(*room, *link, room_path, child_path);
    // protect this with error exit
    if (li_path_end(&child_path, room))
        li_record_path(path, child_path);
    // else
    //     li_solve(ants, room, link);
    // idaig tart a recursion, utana free?
    ants = 0;
    return (1);
}