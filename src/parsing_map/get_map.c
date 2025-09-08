/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:44:55 by mathou            #+#    #+#             */
/*   Updated: 2025/09/08 21:32:08 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int stock_map(char *tmp, t_map *map)
{
    int     x;
    int     y;
    int     i;

    if (!init_grid(map))
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
        map->p_pos->x = x;
        map->p_pos->y = y;
    }
    else if (map->grid[x][y] == 'E')
    {
        map->exit += 1;
        map->e_pos->x = x;
        map->e_pos->y = y;
    }
    else if (map->grid[x][y] == 'C')
        map->collectibles += 1;
}

int get_map(t_map *map, char *ber_file)
{
    int x;
    int y;
    char    *tmp;

    tmp = transfer_param(ber_file, map);
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
