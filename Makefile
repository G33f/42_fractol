# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/27 10:34:56 by wpoudre           #+#    #+#              #
#    Updated: 2020/01/27 10:35:01 by wpoudre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fractol

SOURSE_DIRS		:= srcs srcs/cl srcs/dce srcs/fractol_init srcs/main srcs/mlx_and_inparams

FLAGS			= -Wall -Werror -Wextra

framework		= -L minilibx -lmlx -framework OpenCL -framework OpenGL -framework AppKit -L libft -lft

SEARCH_WILDCARDS:= $(addsuffix /*.c, $(SOURSE_DIRS))

OBJECTS			= $(notdir $(patsubst %.c,%.o, $(wildcard $(SEARCH_WILDCARDS))))

LIB_DIR		= ./libft/

LIB_OBJS		= $(addprefix $(LIB_DIR), $(LIB_OBJ))

LIB_OBJ			= *.o

FDF_INC			= header/fractol.h

LIB_INC			= header/libft.h

all: $(NAME)

$(NAME): $(LIB_OBJS) $(OBJECTS)
	gcc $(OBJECTS) -o $@ $(framework)

VPATH := $(SOURSE_DIRS)

$(LIB_DIR)%.o: $(LIB_DIR)%.c $(LIB_INC)
	make -C $(LIB_DIR)

%.o: %.c $(FDF_INC)
	gcc $(FLAGS) -c $< -I header/

clean:
	make clean -C libft
	rm -rf *.o

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
