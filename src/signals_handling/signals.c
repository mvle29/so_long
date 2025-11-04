/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:46:44 by mathou            #+#    #+#             */
/*   Updated: 2025/10/21 15:29:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

// go up doit trgger animation up etc etc. Le but c est d update px et py ici.

void    close_context(t_game *game)
{
    if (game->mlx->win)
        mlx_destroy_window(game->mlx->mlx, game->mlx->win);
    game->mlx->win = 0;
    free_game(game);
    exit(0);
}

int signals_key(int keycode, t_game *game)
{
    //t_instance  *player;
    //t_instance  ***instance;
    //char        **grid;

    if (keycode == XK_Escape)
        close_context(game);
    if (keycode == XK_z)
        signals_playerupd(game, 0, -5, "static");
    else if (keycode == XK_q)
        signals_playerupd(game, -5, 0, "static");
    else if (keycode == XK_s)
        signals_playerupd(game, 0, 5, "static");
    else if (keycode == XK_d)
        signals_playerupd(game, 5, 0, "static");
    else
        return (0);
    /*
    grid = game->map->grid;
    player = game->map->player;
    instance = game->map->instances;
    signal_playerupd_collectibles(game->map, player, grid, instance);*/
    return (0);
}

void    signals(t_game *game, t_context *context)
{
    mlx_loop_hook(context->mlx->mlx, &render, game);
    mlx_hook(context->mlx->win, KeyRelease, KeyReleaseMask, &signals_key, game);
    //mlx_hook(&context->mlx->win, 2, 1L<<0, move, &game);
}
