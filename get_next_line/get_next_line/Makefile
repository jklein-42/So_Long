# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jklein <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 19:53:24 by jklein            #+#    #+#              #
#    Updated: 2022/08/23 19:53:32 by jklein           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#***************************************************#
#                   DIRECTORIES                     #
#***************************************************#

SRCDIR	=	srcs
OBJDIR	=	objects
INCDIR	=	headers

#***************************************************#
#                   FILES                           #
#***************************************************#

SOURCES	:=	$(wildcard $(SRCDIR)/*.c)
INCLUDES:=	$(wildcard $(INCDIR)/*.h)
OBJECTS	:=	$(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
RM		=	rm -rf
MKDIR	=	mkdir -p

#***************************************************#
#                   COMPILER                        #
#***************************************************#

NAME 	=	get_next_line.ft
CC		=	clang

#***************************************************#
#                   FLAGS                           #
#***************************************************#
CFLAGS	=	-Wall -Wextra -Werror -I $(INCDIR)
LFLAGS	=	-Wall -Wextra -Werror -I $(INCDIR)

#***************************************************#
#                   COMMANDS                        #
#***************************************************#

all: dirs $(NAME)

dirs:
	@$(MKDIR) $(OBJDIR)
	@clear

$(NAME): $(OBJECTS)
	@ar -rcs $(NAME) $(OBJECTS)
	@clear
	@echo "CREATED"$(NAME)

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@clear
	@echo "COMPILED"$<"SUCCESSFULLY!"

clean:
	@$(RM) $(OBJDIR)
	@clear
	@echo $(OBJDIR)"DIRECTORY  REMOVED!"

fclean: clean
	@$(RM) $(NAME)
	@clear
	@printf "%s LIBRARY FILES CLEANED\n" $(NAME)

re: fclean all
	@clear
	@echo $(NAME) "FILES CLEANED AND REMADE SUCCESSFULLY!"
