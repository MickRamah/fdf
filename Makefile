# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 14:34:25 by zramahaz          #+#    #+#              #
#    Updated: 2024/08/08 10:00:43 by zramahaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FRAEMWORKS = -lX11 -lm -lXext

CFLAGS = -Wall -Wextra -Werror

CC = cc

SRC = *.c get_next_line/*.c

INCLUDES = libft/libft.a minilibx-linux/libmlx.a

RM = rm -f

all:
	@make -C libft/ all
	@make -C minilibx-linux/ all
	$(CC) $(SRC) -o $(NAME) $(CFLAGS) $(INCLUDES) $(FRAEMWORKS)

clean:
	@make -C libft/ clean
	@make -C minilibx-linux/ clean

fclean: clean
	$(RM) $(NAME)
	@make -C libft/ fclean

re: fclean all

.PHONY:		all clean fclean re