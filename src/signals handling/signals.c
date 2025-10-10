/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:46:44 by mathou            #+#    #+#             */
/*   Updated: 2025/10/09 06:22:26 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

// go up doit trgger animation up etc etc. Le but c est d update px et py ici.

int *signal_move(int keycode, t_game *game)
{
    t_instance  *player;
    t_instance  ***instance;
    char        **grid;

    if (keycode == Z)
        signal_playerupd(game, 0, 5, "up");
    if (keycode == Q)
        signal_playerupd(game, -5, 0, "left");
    if (keycode == S)
        signal_playerupd(game, 0, -5, "down");
    if (keycode == D)
        signal_playerupd(game, 5, 0, "right");
    else
        return ;
    grid = game->map->grid;
    player = game->map->player;
    instance = game->map->instances;
    signal_playerupd_collectibles(game->map, player, grid, instance);
    cam_update();
    return ;
}

void    signals(t_game *game, t_map *map, t_context *context)
{
    mlx_hook(&context->mlx->win, , close_context, );
    mlx_hook(&context->mlx->win, 2, 1L<<0, move, game);
    mlx_loop_hook(context->mlx, render_game, game);
}
