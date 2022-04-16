##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CPPFLAGS	=	-I gomoku/include -Wall -Wextra -Wno-Wsign-compare  -g3

LDFLAGS = -lm -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

SRC		= gomoku/src/EvalRes.cpp\
	gomoku/src/GomokuAi.cpp\
	gomoku/src/Gomoku.cpp\
	gomoku/src/Player.cpp \
	gomoku/src/Interface.cpp \
	main.cpp

OBJ		=	$(SRC:.cpp=.o)

NAME		=	gomoku-ai-graph



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
