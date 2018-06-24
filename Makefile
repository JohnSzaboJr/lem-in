#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jszabo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/20 10:11:43 by jszabo            #+#    #+#              #
#    Updated: 2018/07/20 10:11:45 by jszabo           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =			lem-in
LIBFT = 		libft/libft.a
HEADER =		lem_in.h
COMPILE =		gcc -Wall -Werror -Wextra -c -o

OBJ_DIR =		objects/
SRC_DIR =		srcs/

SRC =			main li_check_ants li_check_coms li_check_links li_check_rooms \
li_check_spaces li_count_hash li_duplicate_coord li_duplicate_name \
li_free_error1 li_free_error2 li_get_links li_link_com li_link_free \
li_link_invalid li_new_room li_nostartend li_not_int_size li_parse \
li_pos_duplicate li_room_com li_room_coords li_room_free li_room_invalid \
li_room_number li_rooms_over li_rooms_size li_startend li_throw_error \
li_solve li_create_list li_make_child li_repeat li_path_end li_record_path \
li_find_path li_path_free li_move_ants li_ants_list li_ants_list2 li_get_room \
li_reverse_link li_largest li_new_child

OBJ =			$(patsubst %,%.o, $(SRC))

SRC_PATH =   	$(SRC:%=$(SRC_DIR)%.c)

OBJ_PATH =		$(addprefix $(OBJ_DIR), $(OBJ))

all:			make_libft $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)
				@echo '\033[0;32m'*** objects directory created ***'\033[0m'

$(NAME):		$(HEADER) $(OBJ_PATH)
				@gcc $(OBJ_PATH) $(LIBFT) -o $(NAME)
				@echo '\033[0;32m'*** lem_in: project compiled ***'\033[0m'


$(OBJ_PATH):	$(SRC_PATH)
				$(MAKE) $(OBJ)

$(OBJ):			$(LIBFT)
				@$(COMPILE) $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)

make_libft:
				@make -C ./libft

clean:			
				@/bin/rm -rf $(OBJ_DIR) $(LIBFT)
				@make -C ./libft clean
				@echo '\033[0;32m'*** project objects removed ***'\033[0m'

fclean:			clean
				@/bin/rm -f $(NAME) $(LIBFT)
				@make -C ./libft fclean
				@echo '\033[0;32m'*** project executables removed ***'\033[0m'

re: 			fclean all

.PHONY:			all clean fclean re