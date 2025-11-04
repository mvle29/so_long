/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_hb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 21:38:49 by mathou            #+#    #+#             */
/*   Updated: 2025/10/20 12:25:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/so_long.h"

void    init_hb(t_sprite *sprite, char *hb)
{
    char    **scale;

    sprite->feet_hb.h = -1;
    sprite->feet_hb.w = -1;
    scale = ft_split(hb, ',');
    if (!scale)
        return ;
    sprite->txt_hb.offset.x = ft_atoi(scale[0]); //4
    sprite->txt_hb.offset.y = ft_atoi(scale[1]); //-15
    sprite->feet_hb.w = ft_atoi(scale[2]); //18
    sprite->feet_hb.h = ft_atoi(scale[3]); //10
    sprite->feet_hb.offset.x = ft_atoi(scale[4]); //3
    sprite->feet_hb.offset.y = ft_atoi(scale[5]); //20
    free_split(scale);
}
