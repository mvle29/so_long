NAME = test
CC = cc
CFLAGS = -Wall -Werror -Wextra
HEADER = /include/so_long.h
SOURCES = src/test.c src/parsing_map/map.c src/parsing_map/map/map_char.c \
src/parsing_map/map/map_grid.c src/parsing_map/valid_map.c src/init/init_map/init_map.c \
src/free_game/free_game.c

all : NAME

NAME : libft/libft.a
	$(CC) $(CFLAGS) -I $(HEADER) $(SOURCES) libft/libft.a -o test

libft/libft.a :
	make -C libft/
	make -C libft/ clean
