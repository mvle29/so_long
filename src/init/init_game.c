/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 00:51:38 by mathou            #+#    #+#             */
/*   Updated: 2025/10/17 10:14:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_game  *init_game(t_map *map)
{
    t_game  *game;

    game = malloc(sizeof(t_game));
    if (!game)
    {
        free_map(map);
        return (0);
    }
    game->map = map;
    game->mlx = init_mlx();
    if (!game->mlx)
        printf("\n MLX ECHOUE");
    game->cur = init_context(game->mlx);
    if (!game->cur)
        printf("\n CUR ECHOUE");
    game->on_screen = init_context(game->mlx);
    if (!game->on_screen)
        printf("\n SCREEN ECHOUE");
    /*init_spritess(game, game->cur, map);
    init_instances();
    init_cam(game);*/
    game->tile = 32;
    game->spritess = init_spritess(game->cur);
    //if (!game->spritess)
    //    printf("\n INIT SPRITESS ECHOUE");
    //if (game->spritess)
    game->map->instances = init_instances(game, game->spritess, map);
    game->map->player = init_instance(game, map->p, 'P', game->spritess);
    game->cam = init_cam(game);
    if (!game->cur || !game->on_screen || !game->spritess)//|| !game->map->instances)// || game->cam)
    {
        free_game(game); // free_map dedans
        display_error("FAILED TO LOAD GAME");
    }
    return (game);
}
