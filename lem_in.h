/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 15:20:40 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/23 15:01:07 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

typedef struct				s_list_num
{
	int						num;
	struct s_list_num		*next;
}							t_list_num;

typedef struct				s_rooms
{
	int						num;
	char					*name;
	long long				x;
	long long				y;
	int						pos;
	struct s_rooms			*next;
}							t_rooms;

typedef struct				s_links
{
	int						from;
	int						to;
	struct s_links			*next;
}							t_links;

typedef struct				s_path
{
	int						room_num;
	struct s_path			*parent;
	struct s_path			*next;
}							t_path;

int							throw_error(void);
int							li_free_error1(char **line,
t_rooms **room);
int							li_free_error2(char **line,
t_rooms **room, t_links **link);
int							li_parse(char **line,
long long *ants, t_rooms **room, t_links **link);
int							li_not_int_size(char *str);
int							li_check_ants(char **line,
long long *ants, t_rooms **room, int *section);
int							li_check_rooms(char **line,
t_rooms **room, int *section);
int							li_room_free(t_rooms **room);
int							li_check_coms(char **line,
t_rooms **room, int *section);
int							li_rooms_size(t_rooms *room);
int							li_duplicate_coord(t_rooms *room);
int							li_pos_duplicate(t_rooms *room, int pos);
int							li_duplicate_name(t_rooms *room);
int							li_rooms_over(char ***room_data,
t_rooms **room, int *section);
int							li_nostartend(t_rooms *room);
int							li_room_invalid(char ***room_data,
t_rooms **new);
int							li_new_room(t_rooms **new,
char ***room_data, t_rooms **room);
void						li_startend(int *start, int *end,
t_rooms **room);
int							li_room_coords(char ***room_data,
t_rooms **room);
int							li_count_hash(char *line);
int							li_room_com(char **line, t_rooms **room,
int *start, int *end);
int							li_check_links(char **line, t_rooms **room,
t_links **link);
int							li_link_free(t_links **link);
int							li_room_number(t_rooms *room,
char *name);
int							li_check_spaces(char **line,
char ***room_data);
int							li_link_invalid(char ***links_data,
t_links **new);
int							li_get_links(t_links **link,
t_rooms **room, char ***links_data);
int							li_link_com(char **line);
int							li_solve(long long ants, t_rooms **room,
t_links **link);
int							li_create_list(t_rooms *room,
t_links *link, t_path *room_path, t_path **child_path);
int							li_make_child(t_links *link,
t_path *room_path, t_path **child_path);
int							li_repeat(int num, t_path *room_path);
int							li_path_end(t_path *child_path,
t_rooms *room);
int							li_record_path(t_links **link,
t_path *child_path, int num);
int							li_find_path(t_rooms **room, t_links **link,
t_path **room_path, t_path **child_path);
int							li_path_free(t_path **path);
int							li_move_ants(long long ants, t_rooms **room,
t_links **link);
int							li_ants_list(t_rooms **room, t_links **link);
char						*li_get_room(int num, t_rooms *room);
int							li_ants_list2(t_rooms **room, t_links **link,
int ants);
int							li_reverse_link(t_links **link);
int							li_largest(int num, t_links *link);
int							li_new_child(t_path **new, t_path *room_path,
t_path **child_path);

#endif
