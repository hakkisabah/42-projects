# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/19 19:46:24 by hsabah            #+#    #+#              #
#    Updated: 2023/03/19 19:50:12 by hsabah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OS			= $(shell uname)
LIBFTPATH	= libft

NAME		= philo
HEADER		= philo.h

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

RM			= rm -f
ECHO		= echo

ALLFILES 	= $(wildcard *.c)

MANDATORYOBJ	=	$(ALLFILES:.c=.o)

all: $(NAME)

$(NAME): $(MANDATORYOBJ)
	@$(CC) $(CFLAGS) $(MANDATORYOBJ) -o $(NAME)
	@echo "philo is ready to use"

clean: 
			@$(RM) -r $(MANDATORYOBJ)
			@$(RM) -r $(NAME)
			@echo "Object files are deleted"

fclean: 	clean
			@$(RM) $(NAME)
			@echo "philo is deleted"

re: 		fclean all
			@echo "Cleaned and rebuilt everything"

.PHONY:		all clean fclean re