##
## EPITECH PROJECT, 2017
## auto-Makefile
## File description:
## By Ndr
##

#Répertoire des libs
LIB_DIR=	$(realpath ./lib/my)

#Répertoire des includes
INC_DIR=	$(realpath ./include)

#Fichiers sources
SRC=		./src/builtins.c		\
		./src/cd_builtin.c		\
		./src/command_parsing.c		\
		./src/env_handling.c		\
		./src/error_handling.c		\
		./src/exec.c			\
		./src/main.c			\
		./src/shell_core.c		\
		./src/utils2.c			\
		./src/utils.c

#Libs à inclure
LIB=		my

#Fichiers objets (relicats de compilation)
OBJ=		$(SRC:.c=.o)

#Nom du projet
NAME=		mysh

#Arguments gcc
CFLAGS=	-L$(LIB_DIR) -l$(LIB) -I$(INC_DIR)
CFLAGS_DEBUG=	-L$(LIB_DIR) -l$(LIB) -I$(INC_DIR) -g3 -W -Wall -Wextra  -pedantic

#Règles
all:		$(NAME)

$(NAME):
		make -C ./lib/my
		make clean -C ./lib/my
		gcc -o $(NAME) $(SRC) $(CFLAGS)

debug:
		make -C ./lib/my
		make clean -C ./lib/my
		gcc -o $(NAME) $(SRC) $(CFLAGS_DEBUG)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)
		make fclean -C ./lib/my

re:		fclean all

arbo:
		mkdir lib
		mkdir lib/my
		mkdir include
		touch include/.gitignore
		mkdir tests
