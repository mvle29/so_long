/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ground.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 18:46:37 by mathou            #+#    #+#             */
/*   Updated: 2025/10/09 06:28:14 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void    render_ground_txt(t_game *game, t_hitbox *cam, t_sprite *sprite, t_pos map_poss)
{
    t_pos   img_poss;
    t_pos   txt_poss;

    img_poss.x = map_poss.y * game->tile + cam->offset.x;
    img_poss.y = map_poss.y * game->tile + cam->offset.y;
    txt_poss.y = 0;
    while (txt_poss.y < game->tile)
    {
        txt_poss.x = 0;
        while (txt_poss.x < game->tile)
        {
            if (img_poss.x < cam->w && img_poss.y < cam->h && img_poss.x > 0 && img_poss.y > 0)
                pixel_copy();
            img_poss.x++;
            txt_poss.x++;
        }
        txt_poss.y++;
        img_poss.y++;
    }
}

void    render_ground(t_game *game, t_map *map, t_spritess *spritess, t_hitbox *cam)
{
    t_pos   map_poss;
    int     last_row;
    int     last_col;

    map_poss.y = (game->map->player->feet_pos.y - absolute(cam->offset.y)) / game->tile; // renvoie le premier index y_map qui est dans l img (mm partiellement)
    last_row = (cam->h - absolute(cam->offset.y)) / game->tile;
    last_col = (cam->w - absolute(cam->offset.x)) / game->tile;
    while (map_poss.y <= map->y_max && map_poss.y <= last_col) // si un des pixel de map_pos correspond, renvoie 1
    {
        map_poss.x = (game->map->player->feet_pos.x - absolute(cam->offset.x)) / game->tile; // renvoie le premier index x_map qui est dans l img
        while (map_poss.x <= map->x_max && map_poss.x <= last_row)
        {
            render_ground_tile(game, cam, spritess->empty, map_poss);
            map_poss.x++;
        }
        map_poss.y++;
    }
}
