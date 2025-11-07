/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_spritess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathvall <mathvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 01:57:03 by mathou            #+#    #+#             */
/*   Updated: 2025/11/07 13:24:50 by mathvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h" // comment charger une image externe ? On la transforme en img, on copie l img dans notre big img (le buf) a la bonne addresse : il faudra donc une jolie fonction qui copie a la position x y notre img.
// la texture c est juste le relative path du coup !

void    init_spritess(t_game *game, t_context *cur)
{
    if (!cur)
        return (0);
    game->spritess = malloc(sizeof(t_spritess));
    if (!game->spritess)
        return (0);
    /*spritess->walls = init_sprite("middle, up, up_right, up_left, up_left_right,\
         up_down, all, right, right_down, right_left, right_left_down, \
         down, down_left, left", "walls", "1, 2", cur);
    spritess->empty = init_sprite("tile", "tile", "1, 2", cur);*/
    game->spritess->empty = init_sprite("tiles,1000", "tiles", "0,0,32,32,0,0", cur);
    game->spritess->walls = init_sprite("middle,1000", "walls", "0,0,32,32,0,0", cur);
    game->spritess->player = init_sprite("static,1000,exit,1000", \
        "player", "9,-15,18,10,3,20", cur);
    game->spritess->collectibles = init_sprite("potion,1000", "collectibles", "5,5,24,22,3,3", cur);
    game->spritess->exit = init_sprite("exit,1000", "exit", "5,5,24,22,3,3", cur);
    /*spritess->collectibles = init_sprite("onion, rat, ETC", // A REMPLIR !!!!
            "collectibles", "1, 2", cur);
    spritess->exit = init_sprite("exit", "exit/", "1, 2", cur);*/
    if (!game->spritess->player || !game->spritess->empty
        || !game->spritess->walls || !game->spritess->collectibles || !game->spritess->exit)
    {
        free_spritess(game, game->spritess);
        return (0);
    }
    return (game->spritess);
}
// free spritess, free sprite(info dedans). Set a 0 pour le risque que ca s efface pas?
