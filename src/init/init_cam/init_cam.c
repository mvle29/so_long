/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathvall <mathvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 02:01:05 by mathou            #+#    #+#             */
/*   Updated: 2025/11/06 17:50:10 by mathvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

/*typedef struct s_cam
{
    int w;
    int h;
    t_pos   offset; // quand la cam bouge : on update l offset a partir du coin gauche superieur.
}       t_cam;*/

void    *init_cam(t_game *game)
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
