/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 21:41:31 by mathou            #+#    #+#             */
/*   Updated: 2025/10/22 10:31:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/so_long.h"

t_sprite    *init_sprite(char *name, char *path, char *hb, t_context *cur)
{
    t_sprite    *sprite;
    char        **textures;

    sprite = malloc(sizeof(t_sprite));
    if (!sprite)
        return (0);
    sprite->name = path;
    textures = ft_split(name, ',');
    if (!textures)
    {
        free_sprite(sprite);
        return (0);
    }
    sprite->anims = malloc(sizeof(t_anim*) * (ft_countstr(name, ',') + 1));
    init_anims(sprite, textures, path, cur);
    init_hb(sprite, hb);
    free(textures);
    if (sprite->feet_hb.w == -1 || sprite->feet_hb.h == -1 || !sprite->anims)
    {
        free_sprite(sprite);
        return (0);
    }
    return (sprite);
} // plsrs options d init spriteet : 
