NAME = test
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
HEADER = /include/so_long.h
SOURCE_MAIN = src/test.c
SOURCES_MAP = src/parsing_map/map.c src/parsing_map/map/map_char.c \
src/parsing_map/map/map_grid.c src/parsing_map/valid_map.c
SOURCES_INIT = src/init/init_game.c src/init/init_map/init_map.c src/init/init_context/init_context.c src/init/init_instances/init_instances.c \
src/init/init_instances/set_instance_anim.c src/init/init_cam/init_cam.c src/init/init_spritess/init_spritess.c src/init/init_spritess/init_sprite/init_sprite.c \
src/init/init_spritess/init_sprite/init_sprite_anims.c src/init/init_spritess/init_sprite/init_sprite_hb.c
SOURCES_FREE = src/free_game/free_game.c src/free_game/free_context.c src/free_game/free_map.c src/free_game/free_spritess.c
SOURCES_SIGNALS = src/signals_handling/signals.c src/signals_handling/cam_update.c src/signals_handling/signals_player_upd/signals_playerupd.c
SOURCES_RENDER = src/render/render.c src/render/render_/render_ground.c src/render/render_/render_instances.c
SOURCES = $(SOURCE_MAIN) $(SOURCES_FREE) $(SOURCES_INIT) $(SOURCES_MAP) $(SOURCES_SIGNALS) $(SOURCES_RENDER)

all : NAME

NAME : libft/libft.a minilibx-linux/libmlx.a minilibx-linux/libmlx_Linux.a
	$(CC) $(CFLAGS) -I $(HEADER) $(SOURCES) libft/libft.a minilibx-linux/libmlx_Linux.a minilibx-linux/libmlx.a -lXext -lX11 -o test

libft/libft.a :
	make -C libft/
	make -C libft/ clean

minilibx_linux/libmlx.a :
	make -C minilibx_linux/