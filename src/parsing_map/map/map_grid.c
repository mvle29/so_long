/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:44:55 by mathou            #+#    #+#             */
/*   Updated: 2025/10/21 18:04:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

int map_grid_get(char *tmp, t_map *map)
{
    int     x;
    int     y;
    int     i;

    if (!init_map_grid(map))
    {
        free(tmp);
        return (0);
    }
    y = 0;
    i = 0;
    while (y <= map->y_max)
    {
        x = 0;
        while (x <= map->x_max)
        {
            map->grid[y][x] = tmp[i];
            i++;
            x++;
        }
        y++;
    }
    free(tmp);
    return (1);
}
void    map_grid_upd(t_map *map, int x, int y)
{
    if (map->grid[y][x] == 'P')
    {
        map->entry += 1;
        map->p.x = x;
        map->p.y = y;
    }
    else if (map->grid[y][x] == 'E')
    {
        map->exit += 1;
        map->e.x = x;
        map->e.y = y;
    }
    else if (map->grid[y][x] == 'C')
        map->collectibles += 1;
}

int    map_grid(t_map *map, char *ber_file)
{
    int x;
    int y;
    char    *tmp;

    tmp = map_char(ber_file, map);
    if (!tmp)
        return (0);
    if (!map_grid_get(tmp, map)) // si ca marche pas, map non rectangulaire ou insuffisante, free tmp dans la fonction
        return (0);
    y = 0;
    while (y <= map->y_max)
    {
        x = 0;
        while (x <= map->x_max)
        {
            map_grid_upd(map, x, y);
            if (!original_value(map, x, y) || !valid_grid_info(map, x, y)) // un seuil a ete depasse dans les conditions, ou une valeur interdite a été utilisee
                return (0);
            x++;
        }
        y++;
    }
    return (1);
}
