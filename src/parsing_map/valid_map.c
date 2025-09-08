/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 00:53:00 by mathou            #+#    #+#             */
/*   Updated: 2025/09/07 01:05:57 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int find_path(t_map *map, int x, int y)
{
    int path;

    path = 0;
    if (map->grid[x][y] == 'E')
        return (1);
    else if (map->grid[x][y] == '1' || !original_value(map, x, y))
        return (0);
    map->grid[x][y] += 3;
    if (find_path(map, x + 1, y))
        path = 1;
    else if (find_path(map, x - 1, y))
        path = 1;
    else if (find_path(map, x, y + 1))
        path = 1;
    else if (find_path(map, x, y - 1))
        path = 1;
    return (path);
}

int valid_map_info(t_map *map, int x, int y)
{
    if (map->entry > 1 || map->exit > 1)
        return (0);
    if ((x == 0 || x == map->x_max) && map->grid[x][y] != '1')
        return (0);
    if ((y == 0 || y == map->y_max) && map->grid[x][y] != '1')
        return (0);
}
int original_value(t_map *map, int x, int y)
{
    if (map->grid[x][y] == 'P')
        return (1);
    if (map->grid[x][y] == 'E')
        return (1);
    if (map->grid[x][y] == 'C')
        return (1);
    if (map->grid[x][y] == '0')
        return (1);
    if (map->grid[x][y] == '1')
        return (1);
    return (0);
}
