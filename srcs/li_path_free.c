/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_path_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 14:31:23 by jszabo            #+#    #+#             */
/*   Updated: 2018/07/21 14:35:38 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../lem_in.h"
#include "../libft/libft.h"

int	li_path_free(t_path **path)
{
	t_path	*tmp;

	while (*path)
	{
		tmp = (*path)->next;
		free(*path);
		*path = tmp;
	}
	return (1);
}
