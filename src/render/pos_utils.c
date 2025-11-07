/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathvall <mathvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:29:23 by mathou            #+#    #+#             */
/*   Updated: 2025/11/06 13:18:12 by mathvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_pos   img_pos(t_hitbox *cam, t_pos pix_pos)
{
    t_pos   img_poss;

    img_poss.x = pix_pos.x - cam->offset.x;
    img_poss.y = pix_pos.y - cam->offset.y;
    return (img_poss);
    // img_pos : la pos en pixel dans l img en f de cam, et de l offset entre cam et
    // la map. + offset la ou on veut ecire le sprite.
}

t_pos   pix_pos(t_game *game, t_pos map_pos, t_pos offset)
{
    t_pos   pix_poss;

    pix_poss.x = map_pos.x * game->tile + offset.x;
    pix_poss.y = map_pos.y * game->tile + offset.y;
    return (pix_poss);
}

t_pos   map_pos(t_game *game, t_pos pix_poss)
{
    t_pos   map_poss;

    map_poss.x = pix_poss.x / game->tile;
    map_poss.y = pix_poss.y / game->tile;
}

