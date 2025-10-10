/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 00:53:00 by mathou            #+#    #+#             */
/*   Updated: 2025/10/10 03:49:10 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int grid_path(t_map *map, t_pos to_go, int x, int y)
{
    if (x == to_go.x && y == to_go.y)
        return (1);
    else if (map->grid[y][x] == '1' || !original_value(map, x, y))
        return (0);
    map->grid[x][y] += 3;
    if (grid_path(map, to_go, x + 1, y))
        return (1);
    else if (grid_path(map, to_go, x - 1, y))
        return (1);
    else if (grid_path(map, to_go, x, y + 1))
        return (1);
    else if (grid_path(map, to_go, x, y - 1))
        return (1);
    return (0);
}

int map_grid_playable(t_map *map, int x, int y)
{
    char    **grid;
    t_pos   pos;

    grid = map->grid;
    pos.y = 0;
    while (pos.y <= map->y_max)
    {
        pos.x = 0;
        while (pos.x <= map->x_max)
        {
            if (grid[pos.y][pos.x] == 'C' || grid[pos.y][pos.x] == 'E')
            {
                if (grid_path(map, pos, x, y))
                    return (0);
            }
            x++;
        }
        y++;
    }
    return (1);
}

int valid_grid_info(t_map *map, int x, int y)
{
    if (map->entry > 1 || map->exit > 1)
        return (0);
    if ((x == 0 || x == map->x_max) && map->grid[x][y] != '1')
        return (0);
    if ((y == 0 || y == map->y_max) && map->grid[x][y] != '1')
        return (0);
    return (1);
}
int original_value(t_map *map, int x, int y)
{
    if (map->grid[y][x] == 'P')
        return (1);
    if (map->grid[y][x] == 'E')
        return (1);
    if (map->grid[y][x] == 'C')
        return (1);
    if (map->grid[y][x] == '0')
        return (1);
    if (map->grid[y][x] == '1')
        return (1);
    return (0);
}
