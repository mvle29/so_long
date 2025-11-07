/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathvall <mathvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:29:27 by mathou            #+#    #+#             */
/*   Updated: 2025/11/07 13:38:33 by mathvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"
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
typedef struct s_anim t_anim;

typedef struct s_anim
{
    t_context       *text;
    char            *name;
    struct timeval  *tv;
    int             fpus; //nb of frames occupied per texture, ca peut etre individualisé tt comme ça peut etre generalisé
    t_anim          *next;
}       t_anim;

typedef struct s_sprite
{
    t_anim      **anims;
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
    t_pos       e;
    char        **grid;
    int         x_max;
    int         y_max;
    t_instance  *player;
    t_instance  ***instances;
}           t_map;

typedef struct s_game
{
    t_mlx           *mlx;
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

t_game      *init_game(t_map *map);

t_map       *init_map(void);
int         init_map_grid(t_map *map);

t_instance  ***init_instances(t_game *game, t_spritess *spritess, t_map *map);
t_instance  *init_instance(t_game *game, t_pos map_pos, char c, t_spritess *spritess);
void        set_instance_anim(t_instance *instance, char *anim_name, struct timeval tv);

void        *init_mlx(t_game *game);
t_context   *init_context(t_mlx *mlx);

void        *init_spritess(t_game *game, t_context *cur);
t_sprite    *init_sprite(char *name, char *path, char *hb, t_context *cur); //fpt a rajt, dans le path ? Chaque anim a un fpt propre ?

void        init_anims(t_sprite *sprite, char **text, char *path, t_context *cur);
void        init_hb(t_sprite *sprite, char *hb);

t_hitbox    *init_cam(t_game *game);

// FREE

void    free_game(t_game *game);

void    free_map(t_game *game, t_map *map);
void    free_grid(t_map *map, char **grid);
void    free_instances(t_instance ***instances, t_map *map);

void    free_mlx(t_game *game, t_mlx *mlx);
void    free_context(t_context *context);

void    free_spritess(t_game *game, t_spritess *spritess);
void    free_sprite(t_sprite *sprite);

void    free_anims(t_anim **anims);
void    free_anim(t_anim *anim);

int     display_error(char *str);

// PARSING MAP :

t_map   *map(char *av_map);
int     map_grid(t_map *map, char *ber_file);
char    *map_char(char *ber_file, t_map *map);
int     original_value(t_map *map, int x, int y);
int     valid_grid_info(t_map *map, int x, int y);
int     map_grid_playable(t_map *map, int x, int y);

// SIGNALS

void    signals(t_game *game, t_context *context);
int     signals_key(int keycode, t_game *game);
void    signals_playerupd(t_game *game, int x, int y, char *anim_name);

// RENDER

void    cam_update(t_mlx *mlx, t_hitbox *cam, t_map *map);

void    pixel_copy(t_game *game, t_pos txt_poss, t_pos img_poss, t_anim *cur);
int     get_last_line(int map_pos, int cam_offset, t_game *game, int cam_max);

int     render(t_game *game);
void    render_ground(t_game *game, t_map *map, t_spritess *spritess, t_hitbox *cam);
void    render_instances(t_game *game, t_map *map, t_instance ***instances, t_hitbox *cam);

#endif
