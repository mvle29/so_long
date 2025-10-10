/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 18:33:05 by mathou            #+#    #+#             */
/*   Updated: 2025/10/05 23:00:23 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void    cam_update(t_mlx *mlx, t_hitbox *cam, t_map *map)
{
    t_pos   img_poss;
    t_pos   map_poss;

    cam->w = mlx->win_w;
    cam->h = mlx->win_h;
    cam->offset.x = mlx->win_w / 2 - map->player->feet_pos.x;
    cam->offset.y = mlx->win_h / 2 - map->player->feet_pos.y;

    // offset entre map[0][0] et arretes de la cam + ou _
    // on update : l offset entre coin sup gauche de la map et la window
    // on update : les dimensions de la camera si elles ont change
    // en cas de resize : on change les indicateurs mlx a la toute fin peut etre ?
    // ensuite, on update la cam
    // ensuite, on update l image, on change de taille d'image du coup
    //  -> Quelles sont les incidence d un changement de taille d image (les buf) dans notre programme ?
}
