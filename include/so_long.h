/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:29:27 by mathou            #+#    #+#             */
/*   Updated: 2025/09/08 23:54:12 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

typedef struct s_pos
{
    int x;
    int y;
}       t_pos;

typedef struct  s_map
{
    char    *map;
    int     collectibles;
    int     exit;
    int     entry;
    char    **grid;
    int     x_max;
    int     y_max;
    t_pos   *p_pos;
    t_pos   *player_next;
    t_pos   *e_pos;
}           t_map;

typedef struct  s_context
{
    void    *mlx;
    void    *mlx_win;
    void    *img1;
    void    *img2;
    char    *addr;
    int     bits_ppix;
    int     line_len;
    int     endian;
}           t_context;

typedef struct s_hitbox
{
    t_pos   *down_left;
    t_pos   *top_right;
    t_pos   *top_left;
    t_pos   *down_right;
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

typedef struct s_text
{
    void        *img;
    char        *name;
}       t_text;

typedef struct s_sprite
{
    t_text      **text;
    t_hitbox    *hb;
}       t_sprite;

typedef struct s_spritess
{
    t_sprite        *empty;
    t_sprite        *walls;
    t_sprite        *player;
    t_sprite        *collectibles;
    t_sprite        *exit;
    t_instance      **instances;
}       t_spritess;

typedef struct s_instance
{
        t_spritess      *sprite_type;
        int             *collect_count;
        // t_recipe        *recipe;
        t_pos           *pos;
}       t_instance;
// d abord : on update sprites->hitbox, puis la map (si hitbox est en contact avec autre hitbox), puis sprites-> text, puis le context

typedef struct s_game
{
    t_context       *context;
    t_map           *map;
    t_spritess      *spritess;
    int             tile_size;
}       t_game;

#endif