/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 21:41:31 by mathou            #+#    #+#             */
/*   Updated: 2025/09/24 17:29:27 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/so_long.h"

t_sprite    *init_sprite(char *name, char *path, char *hb, t_context *cur)
{
    t_sprite    *sprite;
    char        **textures;
    int         i;

    sprite = malloc(sizeof(t_sprite));
    if (!sprite)
        return (0);
    textures = ft_split(name, ", ");
    sprite->anim = malloc(sizeof(t_anim*) * (ft_count_split(textures) + 1));
    if (!textures || !sprite->anim)
    {
        if (textures)
            free_split(textures);
        free_sprite(sprite);
        return (0);
    }
    init_hb(sprite, hb);
    init_name(sprite, path);
    if (sprite)
        init_anim(sprite, textures, path, cur);
    free_split(textures);
    return (sprite);
} // plsrs options d init spriteet : 
