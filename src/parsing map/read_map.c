/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:58:02 by mathou            #+#    #+#             */
/*   Updated: 2025/09/03 18:17:06 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_map   *map(void)
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

void    restore_map(t_map *map)
{
    while ()
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
