/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:45:17 by mathou            #+#    #+#             */
/*   Updated: 2025/09/03 19:29:33 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

// a util function will be used by multiple files in this folder, therefore placed here in this file.
// a util function can also be a small function that is placed here for a better large view of "important" files and its functions

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

int free_map(t_map *map)
{
    int x;
    int y;

    if (map)
    {
        if (map->grid)
        {
            x = 0;
            while(map->grid[x] && x <= map->width)
            {
                free(map->grid[x]);
                x++;
            }
            free (map->grid);
        }
        free(map);
    }
    return (0);
}
