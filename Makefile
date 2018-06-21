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

NAME = lem_in
LIBFT = libft/libft.a
FLAGS = -Wall -Werror -Wextra
SRCS = srcs/
SOURCES = li_check_ants li_check_coms li_check_links li_check_rooms \
li_check_spaces li_count_hash li_duplicate_coord li_duplicate_name \
li_free_error1 li_free_error2 li_get_links li_link_com li_link_free \
li_link_invalid li_new_room li_nostartend li_not_int_size li_parse \
li_pos_duplicate li_room_com li_room_coords li_room_free li_room_invalid \
li_room_number li_rooms_over li_rooms_size li_startend li_throw_error \
li_solve li_create_list li_make_child li_repeat li_path_end li_record_path \
li_find_path li_path_free li_move_ants li_ants_list li_ants_list2 li_get_room \
li_reverse_link
C_FILES = $(patsubst %,$(SRCS)%.c, $(SOURCES)) main.c
O_FILES = $(patsubst %,%.o, $(SOURCES)) main.o
OBJ = $(patsubst %,objects/%.o, $(SOURCES))

LIBFTSRC = libft/ft_strcpy.c \
libft/ft_strchr.c \
libft/ft_putchar.c \
libft/ft_putnbr.c \
libft/ft_memset.c \
libft/ft_putstr.c \
libft/ft_strlen.c \
libft/ft_isdigit.c \
libft/ft_atoi.c \
libft/ft_bzero.c \
libft/ft_strncpy.c \
libft/ft_strstr.c \
libft/ft_strcmp.c \
libft/ft_strncmp.c \
libft/ft_strcat.c \
libft/ft_strncat.c \
libft/ft_tolower.c \
libft/ft_toupper.c \
libft/ft_isprint.c \
libft/ft_isascii.c \
libft/ft_isalpha.c \
libft/ft_isalnum.c \
libft/ft_strnstr.c \
libft/ft_memcpy.c \
libft/ft_memccpy.c \
libft/ft_memmove.c \
libft/ft_strdup.c \
libft/ft_memchr.c \
libft/ft_memcmp.c \
libft/ft_strlcat.c \
libft/ft_strrchr.c \
libft/ft_memalloc.c \
libft/ft_memdel.c \
libft/ft_strnew.c \
libft/ft_strdel.c \
libft/ft_strclr.c \
libft/ft_striter.c \
libft/ft_striteri.c \
libft/ft_strmap.c \
libft/ft_strmapi.c \
libft/ft_strequ.c \
libft/ft_strnequ.c \
libft/ft_strsub.c \
libft/ft_strjoin.c \
libft/ft_strtrim.c \
libft/ft_strsplit.c \
libft/ft_itoa.c \
libft/ft_putendl.c \
libft/ft_putchar_fd.c \
libft/ft_putstr_fd.c \
libft/ft_putendl_fd.c \
libft/ft_putnbr_fd.c \
libft/ft_lstnew.c \
libft/ft_lstdelone.c \
libft/ft_lstdel.c \
libft/ft_lstadd.c \
libft/ft_lstiter.c \
libft/ft_lstmap.c \
libft/ft_any.c \
libft/ft_isspace.c \
libft/ft_count_if.c \
libft/ft_foreach.c \
libft/ft_map.c \
libft/ft_recursive_factorial.c \
libft/ft_recursive_power.c \
libft/ft_sqrt.c \
libft/ft_strrev.c \
libft/ft_swap.c \
libft/ft_itoa_base.c \
libft/ft_strchlen.c \
libft/ft_strdiv.c \
libft/ft_numlen.c \
libft/ft_stroneleft.c \
libft/ft_strnfill.c \
libft/ft_putwstr.c \
libft/ft_wstrlen.c \
libft/ft_wstrdup.c \
libft/ft_wstrcpy.c \
libft/ft_wstrnew.c \
libft/ft_wstrnfill.c \
libft/ft_wstrjoin.c \
libft/ft_longlongtoa.c \
libft/ft_uitoa_base.c \
libft/ft_putwchar.c \
libft/ft_addtoa.c \
libft/ft_ftoa.c \
libft/ft_round.c \
libft/ft_avany.c \
libft/ft_hasnondigits.c \
libft/ft_atoll.c \
libft/get_next_line.c \
libft/ft_printf.c \
libft/ft_strtablen.c \
libft/ft_freestrtab.c \
libft/ft_str_isalnumsp.c \
libft/ft_str_isalnum.c \
libft/ft_count_char.c \
libft/libft.h

all: $(NAME)

$(LIBFT):
	@make -C libft/ all

objects: $(LIBFT) $(LIBFTSRC) $(C_FILES) lem_in.h
	@gcc $(FLAGS) -c $(C_FILES)
	@mkdir objects/ 2> /dev/null || true
	@mv $(O_FILES) objects/
	@echo '\033[0;32m'*** project objects created ***'\033[0m'

$(NAME): objects
	@gcc -o $(NAME) ./libft/libft.a $(OBJ) ./objects/main.o
	@echo '\033[0;32m'*** lem_in compiled ***'\033[0m'

clean: 
	@/bin/rm -rf objects/
	@make -C libft/ clean
	@echo '\033[0;32m'*** project objects removed ***'\033[0m'

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean
	@echo '\033[0;32m'*** project executables removed ***'\033[0m'

re: fclean all