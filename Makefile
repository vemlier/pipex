# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chukim <chukim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 09:34:51 by chukim            #+#    #+#              #
#    Updated: 2022/07/07 10:54:55 by chukim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex
PRINTFDIR	= ./ft_printf
PRINTFFILE	= libftprintf.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f

SRCS	= pipex.c \
		print_error.c \

OBJS	= $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -I.	

$(NAME) : $(OBJS)
	make -C $(PRINTFDIR)
	cp $(PRINTFDIR)/$(PRINTFFILE) $(NAME)
	$(AR) $@ $?
	gcc -o $(NAME) $(NAME)

all : $(NAME)

clean :
	make -C $(PRINTFDIR) clean
	$(RM) $(OBJS)

fclean : clean
	make -C $(PRINTFDIR) fclean
	$(RM) $(NAME)

re : fclean all

.PHONY	:	all clean fclean re