# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jklein <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 17:59:25 by jklein            #+#    #+#              #
#    Updated: 2022/08/29 16:06:32 by jklein           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#***************************************************#
#					DIRECTORIES						#
#***************************************************#

SRCDIR	=	SpaceGame_logic
OBJDIR	=	objects
BINDIR	=	SpaceGame
INCDIR	=	headers
LIBDIR  =   get_next_line

TEMPDIR	=	$(BINDIR) $(OBJDIR)

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

NAME	=	so_long
CC		=	clang

#***************************************************#
#                   FLAGS                           #
#***************************************************#

LFLAGS	=	-Wall -Wextra -Werror -I $(INCDIR) -lm

MLXFLAGS=	-Lmlx_SpaceGame -lmlx -framework OpenGL -framework AppKit

LIBFLAGS=	$(MLXFLAGS)

#***************************************************#
#                   LIBRARIES                       #
#***************************************************#

GNLDIR	=	$(LIBDIR)/get_next_line
GNL		=	$(GNLDIR)/get_next_line.ft

LIBS	=	$(GNL) $(MLX)

#***************************************************#
#                   COMMANDS                        #
#***************************************************#

all: dirs makelib $(LIBS) $(BINDIR)/$(NAME)

dirs:
	@$(MKDIR) $(TEMPDIR)
	@printf "MADE DIRECTORIES: %s\n" $(TEMPDIR)

cleanlib:
	@$(MAKE) -C $(GNLDIR) re
	@clear
	@printf "CLEANED LIBRAIES: %s\n" $(LIBS)

makelib:
	@cp $(GNLDIR)/$(INCDIR)/*.h $(INCDIR)
	@$(MAKE) -C $(GNLDIR)
	@clear
	@printf "REMADE LIBRARIES: %s\n" $(LIBS)

$(BINDIR)/$(NAME): $(OBJECTS)
	@$(CC)  -g $(OBJECTS) $(LFLAGS) -o $@ $(LIBS) $(LIBFLAGS)
	@clear
	@printf "COMPILED %s SUCCESSFULLY\n" $@

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(CC) -g $(CFLAGS) -c $< -o $@
	@clear
	@printf "LINKED %s TO %s\n" $< $@

clean:
	@$(RM) $(TEMPDIR)
	@clear
	@printf "CLEANED DIRECTORIES: %s\n" $(TEMPDIR)

fclean: clean
	@rm -rf ./headers
	@clear

re: fclean all
	@printf "CLEANED AND REMADE ALL FILES!\n"
