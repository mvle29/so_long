/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_spritess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 06:15:48 by marvin            #+#    #+#             */
/*   Updated: 2025/10/13 06:15:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void    free_anim(t_anim *anim)
{
    t_anim  *last;
    t_anim  *tmp;

    last = anim;
    if (anim->name)
        free(anim->name);
    while (last->next && last->next != anim)
        last = last->next;
    while (anim != last)
    {
        tmp = anim;
        if (anim->text)
            free_context(anim->text);
        anim = anim->next;
        free(tmp);
    }
    if (anim->text)
        free_context(anim->text);
    free(anim);
}

void    free_anims(t_sprite *sprite, t_anim **anims)
{
    int i;

    i = 0;
    while (anims[i])
    {
        free_anim(anims[i]);
        i++;
    }
    free(anims);
    sprite->anims = 0;
}

void    free_sprite(t_sprite *sprite)
{
    if (sprite->anims)
        free_anims(sprite, sprite->anims);
    free(sprite);
}

void    free_spritess(t_game *game, t_spritess *spritess)
{
    if (spritess->empty)
        free_sprite(spritess->empty);
    if (spritess->player)
        free_sprite(spritess->player);
    if (spritess->collectibles)
        free_sprite(spritess->collectibles);
    if (spritess->walls)
        free_sprite(spritess->walls);
    if (spritess->exit)
        free_sprite(spritess->exit);
    free(spritess);
    game->spritess = 0;
}
