# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/18 15:10:07 by dkhatri           #+#    #+#              #
#    Updated: 2019/10/30 19:03:33 by dkhatri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

MAIN = main.c

FLAGS = -Wall -Wextra -Werror

SRCDIR = ./src/

GNL = get_next_line.c

HELPER = ft_matrix.c ft_matrix_helper.c ft_create_win.c ft_transformation.c \
		 ft_pt_func.c ft_hook_func.c

PARSOR = ft_parse_file.c ft_file_matrix.c ft_draw_line.c

SRCO = $(addprefix $(SRCDIR), $(PARSOR:.c=.o)) \
		$(addprefix $(SRCDIR), $(GNL:.c=.o)) \
		$(addprefix $(SRCDIR), $(HELPER:.c=.o)) \
		$(MAIN:.c=.o)

DEPS = ./includes/fdf.h ./includes/get_next_line.h

%.o: %.c $(DEPS)
	gcc $(FLAGS) -I./minilibx_macos/ -o $@ -c $<

all: $(NAME)

$(NAME): $(SRCO)
	make -C libft
	gcc -o $(NAME) $(SRCO) -L libft/ -lft \
		-L./minilibx_macos -lmlx \
		-framework OpenGL -framework AppKit

clean :
	make -C libft clean
	/bin/rm -f $(SRCO)

fclean : clean
	make -C libft fclean
	/bin/rm -f $(NAME)

re : fclean all
