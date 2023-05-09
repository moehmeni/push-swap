# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmomeni <mmomeni@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 18:30:23 by mmomeni           #+#    #+#              #
#    Updated: 2023/05/07 19:43:34 by mmomeni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=		libft.a
CFLAGS=		-Wall -Wextra -Werror
SRCS= 		ft_atoi.c ft_bzero.c ft_calloc.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
 ft_isalnum.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c\
  ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c\
   ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c\
    ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c\
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_bubblesort.c ft_arrrev.c ft_free_split.c\
	get_next_line.c
	
BONUS_SRCS=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c\
ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstshift_right.c ft_lstshift_left.c
SRC_OBJS=	$(SRCS:.c=.o)
BONUS_OBJS=	$(BONUS_SRCS:.c=.o)
OBJS=		$(SRC_OBJS) $(BONUS_OBJS)
ARFLAGS=	crs

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	
bonus: $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
