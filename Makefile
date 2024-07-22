# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/22 14:09:20 by astoll            #+#    #+#              #
#    Updated: 2024/07/22 15:33:40 by astoll           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	src/push_swap.c		\
		src/push.c			\
		src/radix_sort.c	\
		src/rotate.c		\
		src/sort.c			\
		src/stack_utils.c	\
		src/swap.c			\
		src/utils.c			\

NAME = push_swap
OBJS = ${SRCS:.c=.o}
CC = cc 
FLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT = ./libft/libft.a
RM = rm -rf

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME) -L./$(LIBFT_DIR) -lft

$(OBJS): $(SRCS)
	@$(CC) $(FLAGS) -c $? -I./$(LIBFT_DIR)
	@mv *.o src

clean:
	@$(RM) src/*.o
	@make -s -C $(LIBFT_DIR) clean

fclean:	clean
	@$(RM) $(NAME)
	@make -s -C $(LIBFT_DIR) fclean

re:	fclean all clean

.PHONY: all clean fclean test re