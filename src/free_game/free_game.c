/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 00:33:37 by mathou            #+#    #+#             */
/*   Updated: 2025/09/07 02:55:14 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void    free_obj(t_sprite *obj)
{
    t_sprite    tmp;
    if (obj)
    {
        if (obj->text)
        {
            
        }
    }
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

void    free_game(t_game *game)
{
    if (game)
    {
        if (game->map)
            free_map(game->map);
        if (game->context)
            free_mlx(game->context);
        if (game->spritess)
            free_spritess(game->spritess);
        free(game);
    }
}
