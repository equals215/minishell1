##
## EPITECH PROJECT, 2017
## auto-libmy Makefile
## File description:
## By Ndr
##

#Répertoire du projet
SRC_DIR=	$(realpath .)

#Répertoire des libs
LIB_DIR=	$(realpath ..)

#Répertoire des includes
INC_DIR=	$(realpath ../../include)

#Fichiers sources
SRC=		$(SRC_DIR)/*.c

#Fichiers objets (relicats de compilation)
OBJ=		$(SRC:.c=.o) $(SRC_UT:.c=.o)

#Flags de compilation
CFLAGS=		-L$(LIB_DIR) -l$(LIB) -I$(INC_DIR) -W -Wall -Wextra -Werror -pedantic

#Nom du projet
NAME=		libmy.a
H_NAME=		$(wildcard *.h)

#Règles
all:		$(NAME)

$(NAME):
		gcc -c $(SRC) $(CFLAGS)
		ar rc $(NAME) $(OBJ)
		cp $(NAME) $(LIB_DIR)/$(NAME)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)
		rm -f $(LIB_DIR)/$(NAME)

re:		fclean all
