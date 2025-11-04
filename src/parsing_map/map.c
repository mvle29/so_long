/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:58:02 by mathou            #+#    #+#             */
/*   Updated: 2025/10/11 05:34:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void    map_grid_restore(t_map *map)
{
    int x;
    int y;

    y = 0;
    while (y <= map->y_max)
    {
        x = 0;
        while (x <= map->x_max)
        {
            if (!original_value(map, x, y))
                map->grid[y][x] -= 3;
            if (map->grid[y][x] == 'P')
                map->grid[y][x] = '0';
            x++;
        }
        y++;
    }
}

t_map   *map(char *av_map)
{
    t_map   *map;

    map = init_map();
    if (!map)
        return (0);
    if (!map_grid(map, av_map) || map->collectibles < 1 || map->exit != 1 || map->entry != 1)
    {
        free_map(map);
        return (0);
    }
    if (!map_grid_playable(map, map->p.x, map->p.y))
    {
        free_map(map);
        return (0);
    }
    map_grid_restore(map);
    return (map);
}
