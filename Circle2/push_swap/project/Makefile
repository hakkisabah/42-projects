# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/04 12:16:26 by hsabah            #+#    #+#              #
#    Updated: 2023/03/12 11:59:55 by hsabah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OS			= $(shell uname)
LIBFTPATH	= libft

NAME		= push_swap
BNAME 		= checker
HEADER		= push_swap.h

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

RM			= rm -f
ECHO		= echo

# For MacOS
CHECKER_EX	= ./checker_Mac
# For Linux
ifeq ($(OS),Linux)
    CHECKER_EX	= ./checker_linux
endif

ALLFILES 	= $(wildcard *.c)

MANDATORYFILES	= $(filter-out checker.c, $(ALLFILES))
BONUSFILES		= $(filter-out push_swap.c, $(ALLFILES))

MANDATORYOBJ	=	$(MANDATORYFILES:.c=.o)
BONUSOBJ		=	$(BONUSFILES:.c=.o)

all: $(NAME)

$(NAME): $(MANDATORYOBJ)
	@make -C $(LIBFTPATH)
	@cp $(LIBFTPATH)/libft.a .
	@$(CC) $(CFLAGS) $(MANDATORYOBJ) libft.a -o $(NAME)
	@echo "Push_swap is ready to use"

bonus: 
	@echo "not ready yet!"

clean: 
			@make clean -C $(LIBFTPATH)
			@$(RM) -r $(MANDATORYOBJ)
			@$(RM) -r $(NAME)
			@$(RM) -r $(BONUSOBJ)
			@$(RM) -r $(BNAME)
			@echo "Object files are deleted"

fclean: 	clean
			@$(RM) $(NAME)
			@$(RM) -rf $(LIBFTPATH)/libft.a
			@$(RM) -rf libft.a
			@echo "Push_swap is deleted"

re: 		fclean all
			@echo "Cleaned and rebuilt everything"

.PHONY:		all clean fclean re


