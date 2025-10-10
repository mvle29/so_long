/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 02:01:05 by mathou            #+#    #+#             */
/*   Updated: 2025/10/09 06:13:36 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

/*typedef struct s_cam
{
    int w;
    int h;
    t_pos   offset; // quand la cam bouge : on update l offset a partir du coin gauche superieur.
}       t_cam;*/

void    init_cam(t_game *game)
{
    game->cam = malloc(sizeof(t_hitbox));
    if (!game->cam)
        return ;
    game->cam->w = game->cur->mlx->win_w;
    game->cam->h = game->cur->mlx->win_h;
    game->cam->offset.x = game->cam->w / 2 - game->map->player->feet_pos.x;
    game->cam->offset.y = game->cam->h / 2 - game->map->player->feet_pos.y;
}
