/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feree_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 06:16:12 by marvin            #+#    #+#             */
/*   Updated: 2025/10/13 06:16:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void    free_instances(t_instance ***instances, t_map *map)
{
    int x_max;
    int y_max;
    int x;
    int y;
    int erreur;

    y_max = map->y_max;
    x_max = map->x_max;
    y = 0;
    erreur = 0;
    while (y <= y_max && !erreur && instances[y])
    {
        x = 0;
        while (x <= x_max && instances[y][x])
        {
            free(instances[y][x]);
            x++;
        }
        if (x <= x_max && !instances[y][x])
            erreur = 1;
        free(instances[y]);
        y++;
    }
    free(instances);
    map->instances = 0;
}

void    free_grid(t_map *map, char **grid)
{
    int y;

    y = 0;
    while (y <= map->y_max && grid[y])
    {
        free(grid[y]);
        y++;
    }
    free(grid);
}

void free_map(t_map *map)
{
    if (map)
    {
        if (map->grid)
            free_grid(map, map->grid);
        if (map->instances)
            free_instances(map->instances, map);
        if (map->player)
            free(map->player);
        free(map);
    }
}
