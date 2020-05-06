# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lafontai <lafontai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/23 09:39:28 by lafontai          #+#    #+#              #
#    Updated: 2020/05/06 08:13:58 by lafontai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= $(addprefix $(FOLDER), \
			flag1.c \
			flag2.c \
			format1.c \
			format2.c \
			ft_printf.c \
			list.c \
			parse.c)

FOLDER	= printf/

OBJS	= $(SRCS:.c=.o)

NAME	= libftprintf.a

RM		= rm -f

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

ifeq ($(DEBUG), true)
	CFLAGS += -g -fsanitize=address
endif

all:		$(NAME)

$(NAME):	$(OBJS)
			cd libft && make bonus
			cp libft/libft.a ./$(NAME)
			ar rcs $(NAME) $(OBJS)

bonus:		$(NAME)

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			cd libft && make clean
			$(RM) $(OBJS)

fclean:		clean
			$(RM) libft/libft.a
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
