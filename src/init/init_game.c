/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 00:51:38 by mathou            #+#    #+#             */
/*   Updated: 2025/10/05 23:25:38 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int init_game(t_map *map)
{
    t_game  *game;
    t_mlx   *mlx;

    game = malloc(sizeof(t_game));
    if (!game)
    {
        free_map(map);
        return (0);
    }
    game->map = map;
    mlx = init_mlx();
    game->cur = init_context(mlx);
    game->on_screen = init_context(mlx);
    init_spritess(game, game->cur, map);
    init_instances();
    init_cam(game);
    if (!game->cur || !game->spritess || !game->on_screen || game->cam)
    {
        free_game(game); // free_map dedans
        return (0);
    }
    return (1);
}
