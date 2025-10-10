/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_spritess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 01:57:03 by mathou            #+#    #+#             */
/*   Updated: 2025/10/09 06:16:27 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h" // comment charger une image externe ? On la transforme en img, on copie l img dans notre big img (le buf) a la bonne addresse : il faudra donc une jolie fonction qui copie a la position x y notre img.
// la texture c est juste le relative path du coup !

t_spritess  *init_spritess(t_game *game, t_context *cur, t_map *map)
{
    t_spritess  *spritess;
    
    if (!cur)
        return (0);
    spritess = malloc(sizeof(t_spritess));
    if (!spritess)
        return (0);
    spritess->walls = init_sprite("middle, up, up_right, up_left, up_left_right,\
         up_down, all, right, right_down, right_left, right_left_down, \
         down, down_left, left", "../../text/walls/", "1, 2", cur);
    spritess->empty = init_sprite("tile", "../../text/tile/", "1, 2", cur);
    spritess->player = init_sprite("static, go_left, go_up, exit", \
        "../../text/player/", "1, 2", cur);
    spritess->collectibles = init_sprite("onion, rat, ETC", // A REMPLIR !!!!
            "../../textures/collectibles/", "1, 2", cur);
    spritess->exit = init_sprite("exit", "../../text/exit/", "1, 2", cur);
    if (!spritess->exit || !spritess->collectibles || !spritess->player ||
            !spritess->empty || !spritess->walls)
        free_spritess(spritess);
    game->spritess = spritess;
}
// free spritess, free sprite(info dedans). Set a 0 pour le risque que ca s efface pas?