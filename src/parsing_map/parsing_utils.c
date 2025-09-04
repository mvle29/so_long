/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:45:17 by mathou            #+#    #+#             */
/*   Updated: 2025/09/04 14:58:55 by mathou           ###   ########.fr       */
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

int free_map(t_map *map)
{
    int x;
    int y;

    if (map)
    {
        if (map->grid)
        {
            x = 0;
            while(map->grid[x] && x <= map->x_max)
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
