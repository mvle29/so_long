/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:29:27 by mathou            #+#    #+#             */
/*   Updated: 2025/10/10 03:48:52 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "../libft/libft.h"

typedef struct s_pos
{
    int x;
    int y;
    int z;
}       t_pos;

typedef struct s_mlx
{
    void    *mlx;
    void    *win;
    int     win_w;
    int     win_h;
}   t_mlx;

typedef struct  s_context
{
    t_mlx   *mlx;
    void    *img;
    int     img_w;
    int     img_h;
    char    *addr;
    int     bpp;
    int     ll;
    int     endian;
}           t_context;

typedef struct s_hitbox
{
    int     w;
    int     h;
    t_pos   offset;
}       t_hitbox;


/*
typedef struct s_anim_player
{
    img     *static1;
    img     *static2;
    img     *walkleft1;
    img     *walkleft2;
    img     *walkright1;
    img     *walkright2;
    img     *exit;
    img     *collectible;
}       t_anim_player;*/

typedef struct s_anim
{
    struct s_anim      *head;
    t_context   *text;
    char        *name;
    int         fpt; //nb of frames occupied per texture, ca peut etre individualisé tt comme ça peut etre generalisé
    struct s_anim      *next;
}       t_anim;

typedef struct s_sprite
{
    t_anim      **anim;
    int         walkable;
    char        *name;
    t_hitbox    txt_hb;
    t_hitbox    feet_hb;
}       t_sprite;

typedef struct s_instance
{
    t_sprite        *sprite;
    t_anim          *cur;
    t_pos           txt_pos;
    t_pos           feet_pos;
}       t_instance;
// d abord : on update sprites->hitbox, puis la map (si hitbox est en contact avec autre hitbox), puis sprites-> text, puis le context

/*typedef struct s_instances_org
{
    t_instance  **instances
    t_sprite    *sprite;
}       t_instances_org;*/

typedef struct s_spritess
{
    t_sprite        *empty;
    t_sprite        *walls;
    t_sprite        *player;
    t_sprite        *collectibles;
    t_sprite        *exit;
}       t_spritess;

typedef struct  s_map
{
    char        *map;
    int         collectibles;
    int         exit;
    int         entry;
    t_pos       p;
    char        **grid;
    int         x_max;
    int         y_max;
    t_instance  *player;
    t_instance  ***instances;
}           t_map;

typedef struct s_game
{
    t_context       *cur;
    t_context       *on_screen;
    t_map           *map;
    t_spritess      *spritess;
    t_hitbox        *cam;
    int             tile;
}       t_game;

//t_pos   pix_pos(t_game *game, t_pos map_pos, int offset_w, int offset_h);
//t_pos   img_pos(t_hitbox *cam, t_pos pix_pos);

// INIT

t_map   *init_map(void);
int     init_map_grid(t_map *map);;

// FREE

void    free_map(t_map *map);
void    free_grid(t_map *map, char **grid);

// PARSING MAP :

t_map   *map(char *av_map);
void    map_grid(t_map *map, char *ber_file);
char    *map_char(char *ber_file, t_map *map);
int     original_value(t_map *map, int x, int y);
int     valid_grid_info(t_map *map, int x, int y);
int     map_grid_playable(t_map *map, int x, int y);

#endif