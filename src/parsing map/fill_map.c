/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:44:55 by mathou            #+#    #+#             */
/*   Updated: 2025/09/03 18:20:13 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int stock_map(char *av_map, t_map *map)
{
    int i;
    int width;
    int height;

    i = 0;
    while (av_map[i])
    {
        map = malloc 
    }
}

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
