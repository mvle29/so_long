/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_spritess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 01:57:03 by mathou            #+#    #+#             */
/*   Updated: 2025/10/22 10:31:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h" // comment charger une image externe ? On la transforme en img, on copie l img dans notre big img (le buf) a la bonne addresse : il faudra donc une jolie fonction qui copie a la position x y notre img.
// la texture c est juste le relative path du coup !

t_spritess  *init_spritess(t_context *cur)
{
    t_spritess  *spritess;
    
    if (!cur)
        return (0);
    spritess = malloc(sizeof(t_spritess));
    if (!spritess)
        return (0);
    /*spritess->walls = init_sprite("middle, up, up_right, up_left, up_left_right,\
         up_down, all, right, right_down, right_left, right_left_down, \
         down, down_left, left", "walls", "1, 2", cur);
    spritess->empty = init_sprite("tile", "tile", "1, 2", cur);*/
    spritess->empty = init_sprite("tiles", "tiles", "0,0,32,32,0,0", cur);
    spritess->walls = init_sprite("middle", "walls", "0,0,32,32,0,0", cur);
    spritess->player = init_sprite("static,exit", \
        "player", "9,-15,18,10,3,20", cur);
    spritess->collectibles = init_sprite("potion", "collectibles", "5,5,24,22,3,3", cur);
    spritess->exit = init_sprite("exit", "exit", "5,5,24,22,3,3", cur);
    /*spritess->collectibles = init_sprite("onion, rat, ETC", // A REMPLIR !!!!
            "collectibles", "1, 2", cur);
    spritess->exit = init_sprite("exit", "exit/", "1, 2", cur);*/
    if (!spritess->player)
    {
        free_spritess(spritess);
        return (0);
    }
    return (spritess);
}
// free spritess, free sprite(info dedans). Set a 0 pour le risque que ca s efface pas?