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

void    free_instances(t_map *map, t_instance ***instances)
{
    int x_max;
    int y_max;
    int x;
    int y;

    y_max = map->y_max;
    x_max = map->x_max;
    y = 0;
    while (y <= y_max && instances[y] && instances[y][0])
    {
        x = 0;
        while (x <= x_max && instances[y][x])
        {
            free(instances[y][x]);
            x++;
        }
        free(instances[y]);
        y++;
    }
    if (y <= y_max && instances[y])
        free(instances[y]);
    free(instances);
    if (map)
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
    if (map)
        map->grid = 0;
}

void free_map(t_game *game, t_map *map)
{
    if (map)
    {
        if (map->grid)
            free_grid(map, map->grid);
        if (map->instances)
            free_instances(map, map->instances);
        if (map->player)
            free(map->player);
        free(map);
    }
    if (game)
        game->map = 0;
}
