# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 14:34:25 by zramahaz          #+#    #+#              #
#    Updated: 2024/08/08 15:04:16 by zramahaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FRAEMWORKS = -lX11 -lm -lXext

CFLAGS = -Wall -Wextra -Werror

CC = cc

SRCS = fdf.c ft_atoi_base.c \
		ft_draw.c \
		ft_get_color.c \
		ft_utils.c \
		ft_read_map.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c

OBJ = $(SRCS:.c=.o)

INCLUDES = libft/libft.a minilibx-linux/libmlx.a

RM = rm -f

LIBFT_A = libft/libft.a

MLX_A = minilibx-linux/libmlx.a

%.o : %.c
		$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJ) $(LIBFT_A) $(MLX_A) 
	$(CC) $(CFLAGS)  -o $(NAME) $(OBJ) $(INCLUDES)  $(FRAEMWORKS) 

$(LIBFT_A) :
	@make -C libft/ all

$(MLX_A) :
	@make -C minilibx-linux/ all

clean:
	$(RM) $(OBJ)
	@make -C libft/ clean
	@make -C minilibx-linux/ clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(OBJ)
	@make -C libft/ fclean

re: fclean all

.PHONY:		all clean fclean re