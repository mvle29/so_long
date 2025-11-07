/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_instances.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathvall <mathvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:13:48 by mathou            #+#    #+#             */
/*   Updated: 2025/11/06 17:50:24 by mathvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

void    init_instance_sprite(t_instance *instance, t_spritess *spritess, char c)
{
    if (c == 'C')
        instance->sprite = spritess->collectibles;
    else if (c == 'P')
        instance->sprite = spritess->player;
    else if (c == '1')
        instance->sprite = spritess->walls;
    else if (c == 'E')
        instance->sprite = spritess->exit;
    else
        instance->sprite = 0;
}

char    *anim_name_random(t_anim **anims)
{
    int                         max;
    unsigned long long          *seed;
    static unsigned long long   rand;

    max = 0;
    while (anims[max])
        max++;
    if (!rand)
    {
        seed = malloc(sizeof(unsigned long long*));
        if (!seed)
            return (0);
        rand = (unsigned long long)seed;
        free(seed);
    }
    rand = rand * 6364136223846793005ULL + 1442695040888963407ULL;
    return (anims[rand % max]->name);
}

void    init_instance_anim(t_instance *instance, char c)
{
    instance->cur = 0;
    if (c == 'C')
        set_instance_anim(instance, anim_name_random(instance->sprite->anims));//set_instance_anim(instance, "potion");//instance->cur = instance->sprite->anims[0]; //anim_name_random(instance->sprite->anims)
    else if (c == 'P')
        set_instance_anim(instance, "static");
    else if (c == '1')
        set_instance_anim(instance, "middle");//anim_name_wallpos(instance));
    else if (c == 'E')
        instance->cur = instance->sprite->anims[0];
}

t_instance  *init_instance(t_game *game, t_pos map_pos, char c, t_spritess *spritess)
{
    t_instance  *instance;

    instance = malloc(sizeof(t_instance));
    if (!instance)
        return (0);
    setzero_instance(instance);
    init_instance_sprite(instance, spritess, c);
    if (instance->sprite)
    {
        instance->txt_pos.x = map_pos.x * game->tile + instance->sprite->txt_hb.offset.x;
        instance->txt_pos.y = map_pos.y * game->tile + instance->sprite->txt_hb.offset.y;
        instance->feet_pos.x = instance->sprite->txt_hb.offset.x + instance->sprite->feet_hb.offset.x + map_pos.x * game->tile;
        instance->feet_pos.y = instance->sprite->txt_hb.offset.y + instance->sprite->feet_hb.offset.y + map_pos.y * game->tile;
        init_instance_anim(instance, c);
    }
    return (instance);
}
void    init_instances(t_game *game, t_spritess *spritess, t_map *map)
{
    t_pos       pos;

    pos.y = 0;
    map->instances = malloc(sizeof(t_instance**) * (map->y_max + 1));
    if (!map->instances)
        return (0);
    while (map->instances && pos.y <= map->y_max)
    {
        pos.x = 0;
        map->instances[pos.y] = malloc(sizeof(t_instance*) * (map->x_max + 1));
        if (!map->instances[pos.y])
            free_instances(map->instances, map);
        while (map->instances && pos.x <= map->x_max)
        {
            map->instances[pos.y][pos.x] = init_instance(game, pos, map->grid[pos.y][pos.x], spritess);
            if (!map->instances[pos.y][pos.x])
                free_instances(map->instances, map);
            pos.x++;
        }
        pos.y++;
    }
}

