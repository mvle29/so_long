/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hb|name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 21:38:49 by mathou            #+#    #+#             */
/*   Updated: 2025/09/20 21:50:46 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/so_long.h"

void    init_hb(t_sprite *sprite, char *hb)
{
    char    **scale;

    scale = ft_split(hb, ", ");
    if (!scale)
        return ;
    sprite->hb.w = ft_atoi(scale[0]);
    sprite->hb.h = ft_atoi(scale[1]);
    free_split(scale);
}

void    init_name(t_sprite *sprite, char *path)
{
    int     i;
    char    **folders;

    folders = ft_split(path, "/");
    if (!folders)
        return ;
    i = 0;
    while (folders[i])
        i++;
    sprite->name = ft_strdup(folders[i - 1]);
    free_split(folders);
    if (!sprite->name)
        return ;
}
