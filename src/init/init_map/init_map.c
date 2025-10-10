/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 00:48:47 by mathou            #+#    #+#             */
/*   Updated: 2025/10/10 03:51:04 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

t_map   *init_map(void)
{
    t_map   *map;

    map = malloc(sizeof(t_map));
    if (!map)
        return (0);
    map->entry = 0;
    map->exit = 0;
    map->collectibles = 0;
    map->x_max = -1;
    map->y_max = 0;
    map->instances = 0;
    map->grid = 0;
    return (map);
}
int init_map_grid(t_map *map)
{
    int y;

    map->grid = malloc(sizeof(char*) * (map->y_max + 1));
    if (!map->grid)
        return (0);
    y = 0;
    while (y <= map->y_max)
    {
        map->grid[y] = malloc(sizeof(char) * (map->x_max + 1));
        if (!map->grid[y])
        {
            free_grid(map, map->grid);
            return (0);
        }
        y++;
    }
    return (1);
}

