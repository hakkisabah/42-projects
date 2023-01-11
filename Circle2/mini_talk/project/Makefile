# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 21:05:09 by hsabah            #+#    #+#              #
#    Updated: 2023/01/11 23:40:04 by hsabah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFTPATH		= libft

NAMECL		= client
NAMESRV		= server
NAMEBCL		= client_bonus
NAMEBSRV	= server_bonus
HEADERMT	= minitalk.h
HEADERMTB	= minitalk_bonus.h

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm
AR			=	ar rcs

ALLFILES = $(wildcard *.c)
BONUSF = $(wildcard *_bonus.c)
FILES = $(filter-out $(BONUSF), $(ALLFILES))
BONUSCLFILES = $(filter-out $(NAMECL).c $(NAMESRV).c, $(ALLFILES))
BONUSSRVFILES = $(filter-out $(NAMECL).c $(NAMESRV).c, $(ALLFILES))

CLFILES = $(filter-out $(NAMESRV).c, $(FILES))
SRVFILES = $(filter-out $(NAMECL).c, $(FILES))

BCLFILES = $(filter-out $(NAMEBSRV).c, $(BONUSCLFILES))
BSRVFILES = $(filter-out $(NAMEBCL).c, $(BONUSSRVFILES))

ALLOBJ			=	$(ALLFILES:.c=.o)
OBJCL			=	$(CLFILES:.c=.o)
OBJSRV			=	$(SRVFILES:.c=.o)
BOBJCL			=	$(BCLFILES:.c=.o)
BOBJSRV			=	$(BSRVFILES:.c=.o)

start:
			@make all

all:		
			@make -C $(LIBFTPATH)
			@make bonus -C $(LIBFTPATH)
			@cp $(LIBFTPATH)/libft.a .
			@make normal

normal:		$(NAMECL) $(NAMESRV)

bonus:		
			@make -C $(LIBFTPATH)
			@make bonus -C $(LIBFTPATH)
			@cp $(LIBFTPATH)/libft.a .
			@make allbonus

allbonus:	$(NAMEBCL) $(NAMEBSRV)

$(NAMECL): $(OBJCL)
	@echo $(OBJCL)
	@echo $(NAMECL) Objects build started..
	@$(CC) $(CFLAGS) $(OBJCL) $(HEADERMT) libft.a -o $(NAMECL)
	@echo $(NAMECL) Objects builded !

$(NAMESRV): $(OBJSRV)
	@echo $(OBJSRV)
	@echo $(NAMESRV) Objects build started..
	@$(CC) $(CFLAGS) $(OBJSRV) $(HEADERMT) libft.a -o $(NAMESRV)
	@echo $(NAMESRV) Objects builded !

$(NAMEBCL): $(BOBJCL)
	@echo $(BOBJCL)
	@echo $(NAMEBCL) Objects build started..
	@$(CC) $(CFLAGS) $(BOBJCL) $(HEADERMTB) libft.a -o $(NAMEBCL)
	@echo $(NAMEBCL) Objects builded !

$(NAMEBSRV): $(BOBJSRV)
	@echo $(BOBJSRV)
	@echo $(NAMEBSRV) Objects build started..
	@$(CC) $(CFLAGS) $(BOBJSRV) $(HEADERMTB) libft.a -o $(NAMEBSRV)
	@echo $(NAMEBSRV) Objects builded !

clean:
	@echo Minitalk Cleaning
	@$(RM) -rf $(ALLOBJ)
	@make clean -C $(LIBFTPATH)
	@echo Minitalk Cleanin end!

fclean: clean
	@echo Force cleaning..
	@$(RM) -rf $(LIBFTPATH)/libft.a
	@$(RM) -rf libft.a
	@$(RM) -rf $(NAMECL) $(NAMESRV) $(NAMEBCL) $(NAMEBSRV)
	@echo Force cleaning end!

re: fclean start

.PHONY: start all clean fclean re bonus