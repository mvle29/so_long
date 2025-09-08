/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nd_get_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:58:02 by mathou            #+#    #+#             */
/*   Updated: 2025/09/07 01:08:02 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

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
    if (!error && (map->collectibles < 1 || map->exit != 1 || map->entry != 1))
        error = 1;
    if (!error && !find_path(map, map->p_pos->x, map->p_pos->y))
        error = 1;
    if (!error)
        restore_map(map);
    else
        free_map(map);
    return (map);
}
