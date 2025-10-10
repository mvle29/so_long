/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 23:08:27 by mathou            #+#    #+#             */
/*   Updated: 2025/10/09 22:57:11 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int main(int agc, char **agv)
{
    t_map       *map;
    t_game      *game;
    
    if (agc != 2)
        return (display_error());
    map = check_nd_get_map(agc, agv); // Fait
    if (!map)
        return (display_error()); 
    game = init_game(map);
    if (!game)
        return (display_error());
    //mlx_handle_signals(game->cur, map);
    mlx_loop_hook(context->mlx, render_game, game);
    mlx_loop(game->cur->mlx);
    close_context(game->cur, game->on_screen);
    free_game(game);
    return (0);
}

