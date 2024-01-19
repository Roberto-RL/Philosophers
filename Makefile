# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrimonte <rrimonte@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/22 17:53:47 by rrimonte          #+#    #+#              #
#    Updated: 2024/01/16 13:06:56 by rrimonte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME			=	philo
HEADERS			=	philosophers.h
SRCS			=	ft_philosophers.c \
					ft_errors.c \
					ft_atoi.c \
					ft_free.c \
					ft_init.c \
					ft_modes.c \
					ft_threads.c \
					ft_time.c \
					ft_strchr.c 
					
OBJS			=	$(SRCS:.c=.o)
CC				=	gcc
AR				=	ar rcs
CFLAGS			=	-Wall -Wextra -Werror -g -fsanitize=address
RM				=	rm -rf

$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY:	clean fclean re