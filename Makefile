# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agoodwin <agoodwin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/07 04:21:09 by agoodwin          #+#    #+#              #
#    Updated: 2020/07/07 18:16:10 by agoodwin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

SRCS		=	ft_printf.c \
				helpers_a.c \
				helpers_b.c \
				helpers_c.c \
				helpers_d.c \
				libft/ft_memset.c \
				libft/ft_bzero.c \
				libft/ft_memcpy.c \
				libft/ft_memccpy.c \
				libft/ft_memmove.c \
				libft/ft_memchr.c \
				libft/ft_memcmp.c \
				libft/ft_strlen.c \
				libft/ft_strlcpy.c \
				libft/ft_strlcat.c \
				libft/ft_strchr.c \
				libft/ft_strrchr.c \
				libft/ft_strnstr.c \
				libft/ft_strncmp.c \
				libft/ft_atoi.c \
				libft/ft_isspace.c \
				libft/ft_isupper.c \
				libft/ft_islower.c \
				libft/ft_isalpha.c \
				libft/ft_isdigit.c \
				libft/ft_isalnum.c \
				libft/ft_isascii.c \
				libft/ft_isprint.c \
				libft/ft_toupper.c \
				libft/ft_tolower.c \
				libft/ft_calloc.c \
				libft/ft_strdup.c \
				libft/ft_substr.c \
				libft/ft_strjoin.c \
				libft/ft_strtrim.c \
				libft/ft_split.c \
				libft/ft_split_charset.c \
				libft/ft_itoa.c \
				libft/ft_strmapi.c \
				libft/ft_putchar_fd.c \
				libft/ft_putstr_fd.c \
				libft/ft_putendl_fd.c \
				libft/ft_putnbr_fd.c \

OBJS		=	${SRCS:.c=.o}

LIB_PATH	=	-L. -lft

CC		=	gcc

FLAGS		=	-Wall -Wextra -Werror

${NAME}:		${OBJS}
			ar rc ${NAME} ${OBJS}

all:			${NAME}

.c.o:			${SRCS}
			${CC} ${FLAGS} -c $<  -o ${<:.c=.o}

clean:
			rm -f ${OBJS}

fclean:			clean
			rm -f ${NAME}

re:			fclean all

good:		all clean
