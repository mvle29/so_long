/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_instances.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 19:03:01 by mathou            #+#    #+#             */
/*   Updated: 2025/10/20 12:34:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

void    render_player_txt(t_game *game, t_hitbox *cam, t_instance *instance)
{
    t_pos   img_poss;
    t_pos   txt_poss;
    
    img_poss.y = instance->feet_pos.y - instance->sprite->feet_hb.offset.y + cam->offset.y;
    txt_poss.y = 0;
    while (txt_poss.y < instance->sprite->txt_hb.h)
    {
        img_poss.x = instance->feet_pos.x - instance->sprite->feet_hb.offset.x + cam->offset.x;
        txt_poss.x = 0;
        while (txt_poss.x < instance->sprite->txt_hb.w)
        {
            if (img_poss.x < cam->w && img_poss.y < cam->h && img_poss.x > 0 && img_poss.y > 0)
                pixel_copy(game, txt_poss, img_poss, instance->cur);
            img_poss.x++;
            txt_poss.x++;
        }
        txt_poss.y++;
        img_poss.y++;
    }
}

void    render_instance_txt(t_game *game, t_hitbox *cam, t_instance *instance, t_pos map_poss)
{
    t_pos   img_poss;
    t_pos   txt_poss;
    
    if (!instance->sprite)
        return ;
    img_poss.y = map_poss.y * game->tile + cam->offset.y + instance->sprite->txt_hb.offset.y;
    txt_poss.y = 0;
    while (txt_poss.y < instance->sprite->txt_hb.h)
    {
        img_poss.x = map_poss.x * game->tile + cam->offset.x + instance->sprite->txt_hb.offset.x;
        txt_poss.x = 0;
        while (txt_poss.x < instance->sprite->txt_hb.w)
        {
            if (img_poss.x < cam->w && img_poss.y < cam->h && img_poss.x > 0 && img_poss.y > 0)
                pixel_copy(game, txt_poss, img_poss, instance->cur);
            img_poss.x++;
            txt_poss.x++;
        }
        txt_poss.y++;
        img_poss.y++;
    }
}

void    render_instances(t_game *game, t_map *map, t_instance ***instances, t_hitbox *cam)
{
    t_pos   map_poss;
    t_pos   player_poss;
    int     last_row;
    int     last_col;
    
    player_poss.x = map->player->feet_pos.x;
    player_poss.y = map->player->feet_pos.y;
    map_poss.y = ((ft_abs(cam->offset.y) - cam->offset.y) / 2) / game->tile;
    last_row = get_last_line(map_poss.y, cam->offset.y, game, game->cur->img_h);
    while (map_poss.y <= map->y_max && map_poss.y <= last_row)
    {
        map_poss.x = ((ft_abs(cam->offset.x) - cam->offset.x) / 2) / game->tile;
        last_col = get_last_line(map_poss.x, cam->offset.x, game, game->cur->img_w);
        while (map_poss.x <= map->x_max && map_poss.x <= last_col)
        {
            if (instances[map_poss.y][map_poss.x]->sprite)
            {
                if (instances[map_poss.y][map_poss.x]->feet_pos.y < player_poss.y && player_poss.x / game->tile == map_poss.x && player_poss.y / game->tile == map_poss.y)
                    render_player_txt(game, cam, map->player);
                render_instance_txt(game, cam, instances[map_poss.y][map_poss.x], map_poss);
                if (instances[map_poss.y][map_poss.x]->feet_pos.y >= player_poss.y && player_poss.x / game->tile == map_poss.x && player_poss.y / game->tile == map_poss.y)
                    render_player_txt(game, cam, map->player);
            }
            else if (player_poss.x / game->tile == map_poss.x && player_poss.y / game->tile == map_poss.y)
                render_player_txt(game, cam, map->player);
            map_poss.x++;
        }
        map_poss.y++;
    }
}

