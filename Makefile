# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atrujill <atrujill@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 17:31:44 by atrujill          #+#    #+#              #
#    Updated: 2022/06/21 17:47:43 by atrujill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= srcs/ft_printf.c srcs/ft_printf_utils.c

OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

CC			= gcc

RM			= rm -f

LIBFT		= libft

INCLUDE 	= include

CFLAGS		= -Wall -Wextra -Werror -I

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			@make -C ${LIBFT}
			@mv libft/libft.a ${NAME}
			ar -rc ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}
			@make clean -C ${LIBFT}

fclean:		clean
			${RM} ${NAME}
			${RM} ${LIBFT}/libft.a

re:			fclean all

.PHONY:		all clean fclean re
