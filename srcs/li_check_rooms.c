/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_check_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/07/17 14:35:38 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../lem_in.h"
#include "../libft/libft.h"

int li_check_rooms(char **line, t_rooms **room, int *section)
{
    static int  start = 0;
    static int  end = 0;
    t_rooms     *new;
    char        **room_data;

    new = NULL;
    if ((*line)[0] != '#' && (*line)[0] != 'L')
    {
        if (!(room_data = ft_strsplit(*line, ' ')))
            return (li_free_error1(line, room));
        if (li_rooms_over(&room_data, room, section))
            return (li_nostartend(*room)) ? (li_free_error1(line, room)) : 1;
        if (!li_check_spaces(line, &room_data))
            return (li_free_error1(line, room));
        if (li_room_invalid(&room_data, &new) ||
            !li_new_room(&new, &room_data, room) ||
            !li_room_coords(&room_data, room))
            return (li_free_error1(line, room));
        li_startend(&start, &end, room);
        ft_freestrtab(&room_data);
        return (1);
    }
    if (!li_room_com(line, room, &start, &end))
        return (li_free_error1(line, room));
    return (1);
}
