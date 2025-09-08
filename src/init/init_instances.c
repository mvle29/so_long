/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_instances.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:13:48 by mathou            #+#    #+#             */
/*   Updated: 2025/09/08 23:50:57 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_instance  *instance_wall(t_spritess *spritess, int x, int y)
{
    t_instance  *wall;

    wall = malloc(sizeof(t_instance));
    if (!wall)
        return (0);
    wall->sprite_type = spritess->walls;
    wall->collect_count = 0;
    wall->pos = malloc(sizeof(t_pos));
    if (!wall->pos)
        free(wall);
        return (0);
    wall->pos->x = x;
    wall->pos->y = y;
    return (wall);
}

t_instance  *instance_collectible(t_spritess *spritess, t_map *map, int x, int y)
{
    t_instance  *collectible;

    collectible = malloc(sizeof(t_instance));
    if (!collectible)
        return (0);
    collectible->sprite_type = spritess->collectibles;
    collectible->collect_count = &(map->collectibles);
    collectible->pos = malloc(sizeof(t_pos));
    if (!collectible->pos)
        free(collectible);
        return (0);
    collectible->pos->x = x;
    collectible->pos->y = y;
    return (collectible);
}

t_instance  *instance_player(t_spritess *spritess, int x, int y)
{
    t_instance  *player;

    player = malloc(sizeof(t_instance));
    if (!player)
        return (0);
    player->sprite_type = spritess->player;
    player->collect_count = 0;
    player->pos = malloc(sizeof(t_pos));
    if (!player->pos)
        free(player);
        return (0);
    player->pos->x = x;
    player->pos->y = y;
    return (player);
}

t_instance  *instance_exit(t_spritess *spritess, int x, int y)
{
    t_instance  *exit;

    exit = malloc(sizeof(t_instance));
    if (!exit)
        return (0);
    exit->sprite_type = spritess->player;
    exit->collect_count = 0;
    exit->pos = malloc(sizeof(t_pos));
    if (!exit->pos)
        free(exit);
        return (0);
    exit->pos->x = x;
    exit->pos->y = y;
    return (exit);
}

t_instance  *init_instance(t_spritess *spritess, t_map *map, int i)
{
    int     count;
    t_pos   grid;

    count = 0;
    grid.x = 0;
    while (grid.x <= map->x_max)
    {
        grid.y = 0;
        while (grid.y <= map->y_max)
        {
            if (map->grid[grid.x][grid.y] != '0')
                count++;
            if (count == i && map->grid[grid.x][grid.y] == '1')
                return (instance_wall(spritess, grid.x, grid.y));
            if (count == i && map->grid[grid.x][grid.y] == 'E')
                return (instance_exit(spritess, grid.x, grid.y));
            if (count == i && map->grid[grid.x][grid.y] == 'C')
                return (instance_collectible(spritess, map, grid.x, grid.y));
            if (count == i && map->grid[grid.x][grid.y] == 'P')
                return (instance_player(spritess, grid.x, grid.y));
            grid.y++;
        }
        grid.x++;
    }
    return (0);
}

t_instance **init_instances(t_spritess *spritess, t_map *map)
{
    t_instance **instances;
    int         sprite_nb;
    int         i;

    if (!spritess->walls || !spritess->empty || !spritess->player
            || !spritess->collectibles || !spritess->exit)
            return (0);
    sprite_nb = sprite_number(map);
    instances = malloc(sizeof(t_instance*) * (sprite_nb + 1));
    if (!instances)
        return (0);
    i = 0;
    while (i < sprite_nb)
    {
        instances[i] = init_instance(spritess, map, i);
        if (!instances[i])
        {
            free_instances(instances);
            return (0);
        }
        i++;
    }
    instances[i] = 0;
    return (instances);
}
