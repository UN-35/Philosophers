# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/25 21:27:42 by yoelansa          #+#    #+#              #
#    Updated: 2023/08/02 16:40:08 by yoelansa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC_MAN = philo.c parsing.c initialising.c check_end.c

CFLAGS = -Wextra -Werror -Wall -pthread #-fsanitize=thread -g3

all : $(NAME)

$(NAME) : $(SRC_MAN)
		cc $(CFLAGS) $(SRC_MAN) -o $(NAME)

clean :
		rm -rf $(OBJS)

fclean : clean
		rm -rf $(NAME)

re : fclean all
