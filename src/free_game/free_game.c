/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathvall <mathvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 00:33:37 by mathou            #+#    #+#             */
/*   Updated: 2025/11/07 13:43:12 by mathvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/*void    free_instance(t_instance *instance)
{
    return ;
}

void    free_instances(t_instance ***instances)
{
    return ;
}*/

void    free_game(t_game *game)
{
    if (game)
    {
        if (game->map)
            free_map(game, game->map);
        if (game->cur)
            free_context(game->cur);
        if (game->on_screen)
            free_context(game->on_screen);
        if (game->spritess)
            free_spritess(game, game->spritess);
        if (game->cam)
            free(game->cam);
        if (game->mlx)
            free_mlx(game, game->mlx);
        free(game);
    }
}
