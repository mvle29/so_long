/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_instance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:13:48 by mathou            #+#    #+#             */
/*   Updated: 2025/10/09 06:17:21 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void  *set_instance(t_map *map, t_instance *instance, t_spritess *spritess, char c)
{
    if (c == 'C')
    {
        instance->cur = random_anim(spritess->collectibles);
        instance->sprite = spritess->collectibles;
    }
    else if (c == 'P')
    {
        instance->cur = static_anim(spritess->player->anim);
        instance->sprite = spritess->player;
    }
    else if (c == '1')
    {
        instance->cur = wall_anim(map, spritess->walls);
        instance->sprite = spritess->walls;
    }
    else
    {
        instance->cur = spritess->exit->anim[0];
        instance->sprite = spritess->exit;
    }
}

t_instance  *init_instances_(t_game *game, t_pos map_pos, char c, t_spritess *spritess)
{
    t_instance  *instance;
    
    instance = malloc(sizeof(t_instance));
    if (!instance)
    {
        if (instance)
            free_instances(instance);
        return (0);
    }
    set_instance(game->map, instance, spritess, c);
    instance->txt_pos.x = map_pos.x * game->tile + instance->sprite->txt_hb.offset.x;
    instance->txt_pos.y = map_pos.y * game->tile + instance->sprite->txt_hb.offset.y;
    instance->feet_pos.x = instance->txt_pos.x + instance->sprite->feet_hb.offset.x;
    instance->feet_pos.y = instance->txt_pos.y + instance->sprite->feet_hb.offset.y;
    return (instance);
}

t_instance *init_instances(t_game *game, t_spritess *spritess, t_map *map)
{
    t_instance  ***instance;
    t_pos       pos;

    pos.y = 0;
    instance = malloc(sizeof(t_instance**) * map->y_max);
    while (pos.y <= map->y_max)
    {
        pos.x = 0;
        instance[pos.y] = malloc(sizeof(t_instance*) * map->x_max);
        while (pos.x <= map->x_max)
        {
            instance[pos.y][pos.x] = 0;
            if (map->grid[pos.y][pos.x] == 'C' || map->grid[pos.y][pos.x] == 'E' || map->grid[pos.y][pos.x] == '1' || map->grid[pos.y][pos.x] == 'P')
            {
                instance[pos.y][pos.x] = init_instance(pos, map->grid[pos.y][pos.x], spritess);
                if (!instance)
                    return (0);
            }
            pos.x++;
        }
        pos.y++;
    }
    return (instance);
}
