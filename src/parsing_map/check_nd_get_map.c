/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:58:02 by mathou            #+#    #+#             */
/*   Updated: 2025/09/04 15:00:45 by mathou           ###   ########.fr       */
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

void    restore_map(t_map *map)
{
    int x;
    int y;

    x = 0;
    while (x <= map->x_max)
    {
        y = 0;
        while (y <= map->y_max)
        {
            if (!original_value(map, x, y))
                map->grid[x][y] -= 3;
            y++;
        }
        x++;
    }
}

t_map   *check_nd_get_map(char *av_map)
{
    t_map   *map;
    int error;

    error = 0;
    map = init_map();
    if (!map)
        error = 1;
    if (!error && !get_map(map, av_map));
        error = 1;
    if (!error && map->collectibles < 1 || map->exit != 1 || map->entry != 1)
        error = 1;
    if (!error && !find_path(map, map->px, map->py))
        error = 1;
    if (!error)
        restore_map(map);
    else
        free_map(map);
    return (map);
}
