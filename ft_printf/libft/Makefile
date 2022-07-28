# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chukim <chukim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 14:06:01 by chukim            #+#    #+#              #
#    Updated: 2021/12/14 17:54:48 by chukim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAG = -Wall -Wextra -Werror

RM = rm -f

AR = ar
ARFLAGS = crs

INCLUDES = ./libft.h

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \

SRCS/BONUS = ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			ft_lstnew.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

ifdef WITHBONUS
	OBJS = $(SRCS:.c=.o) $(SRCS/BONUS:.c=.o)
else
	OBJS = $(SRCS:.c=.o)
endif

all : $(NAME)

bonus :
	@make WITHBONUS=1 all

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

clean :
	$(RM) $(SRCS:.c=.o) $(SRCS/BONUS:.c=.o)

fclean : clean
	$(RM) $(NAME)

re : fclean all

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $^

.PHONY : all clean fclean re bonus
