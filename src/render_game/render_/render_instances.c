/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_instances.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 19:03:01 by mathou            #+#    #+#             */
/*   Updated: 2025/10/09 22:50:15 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void    render_instance_txt(t_game *game, t_hitbox *cam, t_instance *instance, t_pos map_poss)
{
    t_pos   img_poss;
    t_pos   txt_poss;
    
    img_poss.x = instance->feet_pos.x + cam->offset.x;
    img_poss.y = instance->feet_pos.y + cam->offset.y;
    txt_poss.y = 0;
    while (txt_poss.y < instance->sprite->txt_hb.h)
    {
        txt_poss.x = 0;
        while (txt_poss.x < instance->sprite->txt_hb.w)
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

void    render_instance(t_game *game, t_map *map, t_instance ***instances, t_hitbox *cam)
{
    t_pos   map_poss;
    t_pos   player_poss;
    int     last_row;
    int     last_col;
    
    player_poss.x = map->player->feet_pos.x;
    player_poss.y = map->player->feet_pos.y;
    map_poss.y = (player_poss.y - absolute(cam->offset.y)) / game->tile;
    last_row = (cam->h - absolute(cam->offset.y)) / game->tile;
    last_col = (cam->w - absolute(cam->offset.x)) / game->tile;
    while (map_poss.y <= map->y_max && map_poss.y <= last_row)
    {
        map_poss.x = (player_poss.x - absolute(cam->offset.x)) / game->tile;
        while (map_poss.x <= map->x_max && map_poss.x <= last_row)
        {
            if (instances[map_poss.y][map_poss.x])
            {
                if (instances[map_poss.y][map_poss.x]->feet_pos.y < player_poss.y && player_poss.x / game->tile == map_poss.x && player_poss.y / game->tile == map_poss.y)
                    render_instance_txt(game, cam, map->player, map_poss);
                render_instance_txt(game, cam, instances[map_poss.y][map_poss.x], map_poss);
            }
            if (player_poss.x / game->tile == map_poss.x && player_poss.y / game->tile == map_poss.y)
                render_instance_txt(game, cam, map->player, map_poss);
            map_poss.x++;
        }
        map_poss.y++;
    }
}

