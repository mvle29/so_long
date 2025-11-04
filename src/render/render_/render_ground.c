/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ground.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 18:46:37 by mathou            #+#    #+#             */
/*   Updated: 2025/10/20 09:47:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

void    render_ground_txt(t_game *game, t_hitbox *cam, t_sprite *sprite, t_pos map_poss)
{
    t_pos   img_poss;
    t_pos   txt_poss;

    img_poss.x = map_poss.x * game->tile + cam->offset.x;
    img_poss.y = map_poss.y * game->tile + cam->offset.y;
    txt_poss.y = 0;
    while (txt_poss.y < game->tile)
    {
        img_poss.x = map_poss.x * game->tile + cam->offset.x;
        txt_poss.x = 0;
        while (txt_poss.x < game->tile)
        {
            if (img_poss.x < cam->w && img_poss.y < cam->h && img_poss.x > 0 && img_poss.y > 0)
                pixel_copy(game, txt_poss, img_poss, sprite->anims[0]);
            img_poss.x++;
            txt_poss.x++;
        }
        txt_poss.y++;
        img_poss.y++;
    }
}

void    render_ground(t_game *game, t_map *map, t_spritess *spritess, t_hitbox *cam)
{
    t_pos   map_poss;
    int     last_row;
    int     last_col;

    map_poss.y = ((ft_abs(cam->offset.y) - cam->offset.y) / 2) / game->tile; // renvoie le premier index y_map qui est dans l img (mm partiellement)
    last_row = get_last_line(map_poss.y, cam->offset.y, game, game->cur->img_h);
    while (map_poss.y <= map->y_max && map_poss.y <= last_row) // si un des pixel de map_pos correspond, renvoie 1
    {
        map_poss.x = ((ft_abs(cam->offset.x) - cam->offset.x) / 2) / game->tile; // renvoie le premier index x_map qui est dans l img
        last_col = get_last_line(map_poss.x, cam->offset.x, game, game->cur->img_w);
        while (map_poss.x <= map->x_max && map_poss.x <= last_col)
        {
            render_ground_txt(game, cam, spritess->empty, map_poss);
            map_poss.x++;
        }
        map_poss.y++;
    }
}
