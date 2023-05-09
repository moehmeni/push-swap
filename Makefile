# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmomeni <mmomeni@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 22:09:31 by mmomeni           #+#    #+#              #
#    Updated: 2023/05/07 21:12:20 by mmomeni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=		push_swap
CFLAGS=		-Wall -Wextra -Werror
FUNC=		algo.c operations.c utils.c parse.c
SRCS=		main.c algo.c operations.c utils.c parse.c
LIBFT_DIR=	libft
LIBFT=		$(LIBFT_DIR)/libft.a

BONUS_DIR=	bonus
BONUS_NAME=	checker
BONUS_SRCS=	$(BONUS_DIR)/checker_bonus.c

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -L$(LIBFT_DIR) -lft -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(FUNC) $(BONUS_SRCS)
	$(CC) $(CFLAGS) $(FUNC) $(BONUS_SRCS) -L$(LIBFT_DIR) -lft -o $(BONUS_NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
