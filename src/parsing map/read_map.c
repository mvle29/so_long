/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:58:02 by mathou            #+#    #+#             */
/*   Updated: 2025/09/03 17:41:36 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int update_map_info(t_map *map, int x, int y)
{
        if (map->grid[x][y] == 'P')
        {
            map->entry += 1;
            map->px = x;
            map->py = y;
        }
        else if (map->grid[x][y] == 'E')
        {
            map->exit += 1;
            map->ex = x;
            map->ey = y;
        }
        else if (map->grid[x][y] == 'C')
            map->collectibles += 1;
}

int valid_map_info(t_map *map, int x, int y)
{
    if (map->entry > 1 || map->exit > 1)
        return (0);
    if ((x == 0 || x == map->width) && map->grid[x][y] != '1')
        return (0);
    if ((y == 0 || y == map->height) && map->grid[x][y] != '1')
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

int fill_reasonable_map(t_map *map, char *av_map)
{
    int x;
    int y;

    if (!stock_map(av_map, map)) // si ca marche pas, map non rectangulaire ou insuffisante
        return (0);
    x = 0;
    while (x <= map->witdh)
    {
        y = 0;
        while (y <= map->height)
        {
            update_map_info(map, x, y);
            if (!orginal_value(map, x, y) || !valid_map_info(map, x, y)) // un seuil a ete depasse dans les conditions, ou une valeur interdite a été utilisee
                return (0);
            y++;
        }
        x++;
    }
    return (1);
}

int find_path(t_map *map, int x, int y)
{
    int path;

    path = 0;
    if (map->grid[x][y] == 'E')
        return (1);
    else if (map->grid[x][y] == '1' || !original_value(map, x, y))
        return (0);
    ft_lowercase(map->grid[x][y]);
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

t_map   *read_map(char *av_map)
{
    t_map   *map;

    map = init_map();
    if (!map)
        return (0);
    if (!fill_reasonable_map(map, av_map));
        return (free_map(map));
    if (map->collectibles < 1 || map->exit != 1 || map->entry != 1)
        return (free_map(map));
    if (!find_path(map, map->px, map->py))
        return (free_map(map));
    restore_map(map);
    return (map);
}
