/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/07/17 14:35:38 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lem_in.h"
#include "./libft/libft.h"

int main(void)
{
	char        *line;
    long long   ants;
    t_rooms     *room;
    t_links     *link;
    int         error;

    error = 0;
    ants = 0;
	line = NULL;
    room = NULL;
    link = NULL;
    if (!(li_parse(&line, &ants, &room, &link)) ||
    !li_solve(ants, &room, &link))
        error = 1;
    li_room_free(&room);
    li_link_free(&link);
	return (error) ? (-1) : (0);
}
