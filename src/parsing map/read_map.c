/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:58:02 by mathou            #+#    #+#             */
/*   Updated: 2025/09/03 16:04:15 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int valid_map_info(t_map *map, int x, int y)
{
        if ((x == 0 || x == map->width) && map->grid[x][y] != '1')
            return (0);
        else if ((y == 0 || y == map->height) && map->grid[x][y] != '1')
            return (0);
        if (map->grid[x][y] == 'P')
            map->entry += 1;
        else if (map->grid[x][y] == 'E')
            map->exit += 1;
        else if (map->grid[x][y] == 'C')
            map->collectibles += 1;
        else if (map->grid[x][y] != '0' && map->grid[x][y] != '1')
            return (0);
        if (map->entry > 1 || map->exit > 1)
            return (0);
        return (1);
}

int fill_nd_check_map(t_map *map, char *av_map)
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
            if (!valid_map_info(map, x, y)) // un seuil a ete depasse dans les conditions, ou une valeur interdite a été utilisee
                return (0);
            y++;
        }
        x++;
    }
    return (1);
}

t_map   *read_map(char *av_map)
{
    t_map   *map;

    map = init_map(av_map);
    if (!map)
        return (0);
    if (!fill_nd_check_map(map, av_map));
        return (free_map(map));
    if (map->collectibles < 1 || map->exit != 1 || map->entry != 1)
        return (free_map(map));
    if (!find_path(map))
        return (free_map(map));
    return (map);
}