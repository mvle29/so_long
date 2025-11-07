/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_anims.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathvall <mathvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 21:42:31 by mathou            #+#    #+#             */
/*   Updated: 2025/11/07 13:38:40 by mathvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/so_long.h"

static  char    *ft_strdupcat_max(char *s1, char *s2, char *s3, char *s4)
{
    char    *res;

    res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + ft_strlen(s4) + 1));
    if (!res)
        return (0);
    res[0] = '\0';
    ft_strcat(res, s1);
    ft_strcat(res, s2);
    ft_strcat(res, s3);
    ft_strcat(res, s4);
    return (res);
}

static  char    *ft_strsep(char *s1, char *s2, char *s3, char *sep)
{
    char    *res;

    res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + ft_strlen(sep) * 2 + 1));
    if (!res)
        return (0);
    res[0] = '\0';
    ft_strcat(res, s1);
    ft_strcat(res, sep);
    ft_strcat(res, s2);
    ft_strcat(res, sep);
    ft_strcat(res, s3);
    return (res);
}

t_context    *init_anim_txt(int i, t_sprite *sprite, char *path, t_mlx *mlx)
{
    char        *xpm_path;
    t_context   *text;
    char        *nb;

    text = malloc(sizeof(t_context));
    if (!text)
        return (0);
    nb = ft_itoa(i);
    xpm_path = ft_strdupcat_max(path, "/", nb, ".xpm");
    text->mlx = mlx;
    text->img = mlx_xpm_file_to_image(mlx->mlx, xpm_path, &sprite->txt_hb.w, &sprite->txt_hb.h);
    if (!text->img || !nb)
    {
        if (nb)
            free(nb);
        if (xpm_path)
            free(xpm_path);
        free_context(text);
        return (0);
    }
    free(nb);
    free(xpm_path);
    text->addr = mlx_get_data_addr(text->img, &text->bpp, &text->ll, &text->endian);
    if (!text->addr)
    {
        free_context(text); // destroy image dedans
        return (0);
    }
    return (text);
}

void    init_anim(t_anim *anim, t_sprite *sprite, char *path, t_context *cur)
{
    t_anim  *new;
    int     i;

    i = 0;
    new = anim;
    new->text = 0;
    new->next = 0;
    while (i == 0 || new->text)
    {
        if (new->next)
            new = new->next;
        new->next = malloc(sizeof(t_anim));
        if (!new->next)
        {
            free_anims(sprite, sprite->anims);
            return ;
        }
        new->name = anim->name;
        new->fpus = anim->fpus;
        new->text = init_anim_txt(i, sprite, path, cur->mlx);
        i++;
    }
    if (new->next)
        free(new->next);
    new->next = anim;
}

void    init_anims(t_sprite *sprite, char **text, char *path, t_context *cur)
{
    int     i;
    char    *accurate_path;

    i = 0;
    while (text[i] && sprite->anims)
    {
        accurate_path = ft_strsep("text", path, text[i], "/");
        sprite->anims[i] = malloc(sizeof(t_anim));
        if (accurate_path && sprite->anims[i])
            sprite->anims[i]->name = ft_strdup(text[i]);
        if (accurate_path && sprite->anims[i] && sprite->anims[i]->name)
            sprite->anims[i]->fpus = ft_atoi(text[i + 1]);
        if (accurate_path && sprite->anims[i] && sprite->anims[i]->name)
            init_anim(sprite->anims[i], sprite, accurate_path, cur);
        if (accurate_path)
            free(accurate_path);
        if (!sprite->anims[i] || !sprite->anims[i]->name || !sprite->anims[i]->text)
        {
            free_anims(sprite, sprite->anims);
            return ;
        }
        i += 2;
    }
    if (sprite->anims)
        sprite->anims[i] = 0;
}

