/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 00:51:38 by mathou            #+#    #+#             */
/*   Updated: 2025/09/08 21:19:17 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int init_game(t_map *map)
{
    t_game  *game;

    game = malloc(sizeof(t_game));
    if (!game)
    {
        free_map(map);
        return (0);
    }
    game->map = map;
    game->context = init_context();
    game->spritess = init_spritess(game->context, game->map);
    if (!game->context || !game->spritess)
    {
        free_game(game);
        return (0);
    }
    return (1);
}
