/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_anim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 21:42:31 by mathou            #+#    #+#             */
/*   Updated: 2025/09/24 18:42:38 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../include/so_long.h"

t_text    *init_txt_context(int i, t_sprite *sprite, char *pathh, t_context *cur)
{
    void        *img;
    char        *xpm_name;
    t_text      *text;

    text = malloc(sizeof(t_text));
    if (!text)
        return (0);
    xpm_name = ft_strdupcattt(pathh, ft_atoi(i), ".xpm");
    if (!xpm_name)
        return ;
    text->context = malloc(sizeof(t_context));
    if (!text->context)
    {
        free(xpm_name);
        return ;
    }
    text->context->mlx = cur->mlx;
    text->context->img = xpm_to_mlx_img(cur->mlx->mlx, xpm_name, &sprite->hb.w, &sprite->hb.h);
    free(xpm_name);
    if (!text->context->img)
        return ;
    text->context->addr = mlx_get_data_addr(text->context->img, &text->context->bpp, &text->context->ll, &text->context->endian);
    if (!text->context->addr)
        free_text(text); // destroy image dedans
    return (text);
}

void    init_anim(t_anim *anim, t_sprite *sprite, char *path, t_context *cur)
{
    t_anim  *new;
    char    *pathh;
    int     i;

    i = 1;
    new = anim;
    while (new->text || i == 1)
    {
        new->head = anim;
        new->text = 0;
        pathh = ft_strdupcattt(path, anim->name, "/");
        if (!path)
            return ;
        new->text = init_txt_context(i, sprite, pathh, cur);
        new->next = malloc(sizeof(t_anim));
        if (!new->next)
            free_anim(anim);
        if (new->text)
            new = new->next;
        free(pathh);
        i++;
    }
    free(new->next);
    new->head = 0;
}

void    init_anims(t_sprite *sprite, char **text, char *path, t_context *cur)
{
    int i;

    i = 0;
    if (sprite->hb.h == 0)
        return ;
    while (text[i])
    {
        sprite->anim[i] = malloc(sizeof(t_anim));
        if (sprite->anim[i])
            sprite->anim[i]->name = ft_strdup(text[i]);
        if (sprite->anim[i] && sprite->anim[i]->name)
            init_anim(sprite->anim[i], sprite, path, cur);
        /*if (sprite->anim[i] && sprite->anim[i]->name)
            sprite->anim[i]->context->img = init_txt_context(sprite, sprite->text[i], path, cur); // tt ca retourne 0 en cas d erreur donc oklm pour les free on checke la ou il y a des 0*/
        if (!sprite->anim[i] || !sprite->anim[i]->head || !sprite->anim[i]->text)
        {
            free_sprite(sprite);
            return ;
        }
        i++;
    }
    sprite->anim[i] = 0;
}

