/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 23:08:27 by mathou            #+#    #+#             */
/*   Updated: 2025/09/04 18:36:01 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int main(int agc, char **agv)
{
    t_context   *context;
    t_map       *map;
    t_game      *game;
    
    map = check_map(agc, agv); // Fait
    if (!map)
        return (display_error()); 
    context = create_context();
    if (!context)
    {
        free_map(map);
        return (display_error());
    }
    game = init_game(map, context);
    if (!game)
        return (display_error());
    mlx_handle_signals(context, map);
    mlx_loop(context->mlx);
    close_context(context);
    free_map(map);
    return (0);
}
