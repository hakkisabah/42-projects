# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 13:50:54 by hsabah            #+#    #+#              #
#    Updated: 2023/01/22 17:34:53 by hsabah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OS			= $(shell uname)
LIBFTPATH		= libft

NAME		= so_long
HEADER		= so_long.h

# For MacOS
MINILIBX	= minilibx/
# For Linux
ifeq ($(OS),Linux)
    MINILIBX = minilibx-linux/
endif

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g
FSANITIZE	= -fsanitize=address -g3
RM			= rm -f
ECHO		= echo


# For MacOS
OPENGL		= -framework OpenGL -framework AppKit

# For MacOS
MINILIBXCC	= -I mlx -L lib/minilibx -lmlx
# For Linux
ifeq ($(OS),Linux)
    MINILIBXCC	= -lmlx -lXext -lX11 -lm -lbsd
endif

COMPILEPRM	= $(MINILIBXCC) $(OPENGL)
ifeq ($(OS),Linux)
COMPILEPRM	= $(MINILIBXCC)
endif

ALLFILES = $(wildcard *.c)

ALLOBJ			=	$(ALLFILES:.c=.o)

start:
			@make all

all:		$(NAME)

$(NAME):	$(ALLOBJ)
			@make -s -C $(MINILIBX)
			@make -C $(LIBFTPATH)
			@make bonus -C $(LIBFTPATH)
			@cp $(LIBFTPATH)/libft.a .
			@$(CC) $(CFLAGS) $(ALLOBJ) $(HEADER) $(COMPILEPRM) libft.a -o $(NAME)


clean:
			@$(RM) -r $(ALLOBJ)
			@make clean -C $(MINILIBX)
			@make clean -C $(LIBFTPATH)

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) -rf $(LIBFTPATH)/libft.a
			@$(RM) -rf libft.a


re:			fclean all
			@$(ECHO) -n "$(GREEN)Cleaned and rebuilt everything for [so_long]!$(DEF_COLOR)\n"

.PHONY:		all clean fclean re norm
