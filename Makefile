NAME = so_long
CC = cc
RM = rm -f
CFLAGS= -Wall -Wextra -Werror
SRC =  main.c move.c parsing1.c parsing2.c parsing3.c parsing4.c render.c utils.c ./get_next_line42/get_next_line.c ./get_next_line42/get_next_line_utils.c 
OBJ = $(SRC:%.c=%.o)
all : $(NAME)
$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ)  -o $(NAME) -lmlx -framework OpenGL -framework AppKit
%.o : %.c so_long.h
	$(CC) $(CFLAGS)  -c $< -o $@
clean : 
	$(RM) $(OBJ)
fclean : clean
	$(RM) $(NAME)
re : fclean all
.phony : all clean fclean $(NAME)