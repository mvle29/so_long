/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:45:17 by mathou            #+#    #+#             */
/*   Updated: 2025/09/03 18:03:07 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

// a util function will be used by multiple files in this folder, therefore placed here in this file.

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
