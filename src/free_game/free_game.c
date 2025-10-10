/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 00:33:37 by mathou            #+#    #+#             */
/*   Updated: 2025/10/10 03:50:25 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void    free_grid(t_map *map, char **grid)
{
    int y;

    y = 0;
    while (grid[y] && y <= map->y_max)
    {
        free(grid[y]);
        y++;
    }
}

/*void    free_instance(t_instance *instance)
{
    return ;
}

void    free_instances(t_instance ***instances)
{
    return ;
}*/

void free_map(t_map *map)
{
    if (map)
    {
        if (map->grid)
            free_grid(map, map->grid);
        /*if (map->instances)
            free_instances(map->instances);
        if (map->player)
            free_instance(map->player);*/
        free(map);
    }
}

/*void    free_game(t_game *game)
{
    if (game)
    {
        if (game->map)
            free_map(game->map);
        if (game->cur)
            free_context(game->cur);
        if (game->on_screen)
            free_context(game->on_screen);
        if (game->spritess)
            free_spritess(game->spritess);
        free(game);
    }
}*/
