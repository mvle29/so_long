/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 23:08:27 by mathou            #+#    #+#             */
/*   Updated: 2025/10/12 22:50:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int main(int agc, char **agv)
{
    t_map       *map;
    t_game      *game;
    
    if (agc != 2)
        return (display_error());
    map = map(agc, agv); // Fait
    if (!map)
        return (display_error()); 
    game = init_game(map);
    if (!game)
        return (display_error());
    //mlx_handle_signals(game->cur, map);
    mlx_loop_hook(context->mlx, render_game, game);
    mlx_loop(game->cur->mlx);
    free_game(game);
    return (0);
}

