/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathvall <mathvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 00:51:38 by mathou            #+#    #+#             */
/*   Updated: 2025/11/07 13:15:49 by mathvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int init_game_contxt(t_game *game)
{
    init_mlx(game);
    if (!game->mlx)
    {
        printf("\n MLX ECHOUE");
        return (1);
    }
    game->cur = init_context(game->mlx);
    game->on_screen = init_context(game->mlx);
    if (!game->on_screen || !game->cur)
    {
        printf("\n SCREEN ECHOUE");
        return (1);
    }
    return (0);
}

int init_game_assets(t_game *game)
{
    t_map *map;

    map = game->map;
    game->tile = 32;
    init_spritess(game, game->cur);
    if (!game->spritess)
    {
        printf("\n INIT SPRITESS ECHOUE");
        return (1);
    }
    init_instances(game, game->spritess, map);
    game->map->player = init_instance(game, map->p, 'P', game->spritess);
    init_cam(game);
    if (!game->map->instances || !game->map->player || !game->cam)
        return (1);
    return (0);
}

t_game  *init_game(t_map *map)
{
    t_game  *game;
    int     error;

    game = malloc(sizeof(t_game));
    if (!game)
    {
        free_map(map);
        return (0);
    }
    setzero_game(game);
    game->map = map;
    error = init_game_contxt(game);
    if (!error)
        error = init_game_assets(game);
    if (error)
    {
        free_game(game); // free_map dedans
        display_error("FAILED TO LOAD GAME");
        return (0);
    }
    return (game);
}
