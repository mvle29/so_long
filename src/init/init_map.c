/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 00:48:47 by mathou            #+#    #+#             */
/*   Updated: 2025/09/08 21:33:13 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_map   *init_map(void)
{
    t_map   *map;

    map = malloc(sizeof(t_map));
    if (!map)
        return (0);
    map->entry = 0;
    map->exit = 0;
    map->collectibles = 0;
    return (map);
}
int init_grid(t_map *map)
{
    int x;

    map->grid = malloc(sizeof(char*) * (map->x_max + 1));
    if (!map->grid)
        return (0);
    x = 0;
    while (x <= map->x_max)
    {
        map->grid[x] = malloc(sizeof(char) * map->y_max);
        if (!map->grid[x])
            return (0);
        x++;
    }
    return (1);
}

