/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:44:55 by mathou            #+#    #+#             */
/*   Updated: 2025/09/04 14:59:17 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int malloc_grid(t_map *map)
{
    int x;

    map->grid = malloc(sizeof(char*) * (map->x_max + 1));
    if (!map->grid)
        return (0);
    x = 0;
    while (x <= map->x_max)
    {
        map->grid[x] = malloc(sizeof(char) * (map->y_max + 1));
        if (!map->grid[x])
            return (0);
        x++;
    }
    return (1);
}

int stock_map(char *tmp, t_map *map)
{
    int     x;
    int     y;
    int     i;

    if (!malloc_grid(map))
    {
        free(tmp);
        return (0);
    }
    x = 0;
    i = 0;
    while (x <= map->x_max)
    {
        y = 0;
        while (y <= map->y_max)
        {
            map->grid[x][y] = tmp[i];
            i++;
            y++;
        }
        x++;
    }
    free(tmp);
    return (1);
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
    if ((x == 0 || x == map->x_max) && map->grid[x][y] != '1')
        return (0);
    if ((y == 0 || y == map->y_max) && map->grid[x][y] != '1')
        return (0);
}

int get_map(t_map *map, char *ber_file)
{
    int x;
    int y;
    char    *tmp;

    tmp = extract_map_param(ber_file, map);
    if (!tmp)
        return (0);
    if (!stock_map(tmp, map)) // si ca marche pas, map non rectangulaire ou insuffisante, free tmp dans la fonction
        return (0);
    x = 0;
    while (x <= map->x_max)
    {
        y = 0;
        while (y <= map->y_max)
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
