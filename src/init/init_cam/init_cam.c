/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 02:01:05 by mathou            #+#    #+#             */
/*   Updated: 2025/10/17 09:52:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

/*typedef struct s_cam
{
    int w;
    int h;
    t_pos   offset; // quand la cam bouge : on update l offset a partir du coin gauche superieur.
}       t_cam;*/

t_hitbox    *init_cam(t_game *game)
{
    t_hitbox    *cam;

    cam = malloc(sizeof(t_hitbox));
    if (!cam)
        return (0);
    cam->w = game->cur->mlx->win_w;
    cam->h = game->cur->mlx->win_h;
    cam->offset.x = cam->w / 2 - game->map->player->feet_pos.x;
    cam->offset.y = cam->h / 2 - game->map->player->feet_pos.y;
    return (cam);
}
