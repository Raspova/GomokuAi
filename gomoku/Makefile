##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CPPFLAGS	=	-I include -Wall -Wextra -Wno-Wsign-compare

LDFLAGS = -lm

SRC		= src/EvalRes.cpp\
	src/GomokuAi.cpp\
	src/Gomoku.cpp\
	src/Player.cpp \
	src/Interface.cpp \
	main.cpp

OBJ		=	$(SRC:.cpp=.o)

NAME		=	pbrain-gomoku-ai



all: $(NAME)

clean:
	rm -f $(OBJ)

$(NAME):	$(OBJ)
		g++ -o $(NAME) $(OBJ) $(LDFLAGS)
		@echo -e "\e[92;5m       ====BULDING DONE====      \e[0m"

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
