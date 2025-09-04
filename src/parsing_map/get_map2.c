/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:56:43 by mathou            #+#    #+#             */
/*   Updated: 2025/09/04 14:59:13 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char    *read_map(int fd, t_map *map)
{
    int     r;
    char    *tmp;
    char    buf;

    r = read(fd, buf, 1);
    if (r < 1)
        return (0);
    tmp = 0;
    while (r)
    {
        tmp = ft_realloc(tmp, 2 + ft_strlen(tmp));
        if (!tmp)
            return (0);
        ft_strncat(tmp, &buf, 1);
        r = read(fd, buf, 1);
    }
    if (r < 0)
    {
        free(tmp);
        return (0);
    }
    return (tmp);
}
void    get_map_scale(t_map *map, char *tmp)
{
    int i;
    int witdh;
    int y_max;

    i = 0;
    while (tmp[i])
    {
        if (!map->x_max && tmp[i] == '\n')
            map->x_max = i - 2;
        else if (tmp[i] == '\n' && i % (map->x_max + 2) != 0)
            map->x_max = 0;
        i++;
    }
    if (i % (map->x_max + 2) != 0)
        map->x_max = 0;
    map->y_max = i / (map->x_max + 2);
}

char    *formatted_map(t_map *map, char *tmp)
{
    char    *tmpb;
    int i;
    int count;

    count = 0;
    i = 0;
    tmpb = 0;
    while (tmp[i])
    {
        if (tmp[i] && tmp[i] == '\n' && tmp[i + 1] == '\n')
        {
            free(tmp);
            return (0); // 2 versions a faire de ce cas a la fin : 1 avec slash n infini, qui marque fin de map, une sans. V sans ici
        }
        if (tmp[i] != '\n')
            count++;
        i++;
    }
    tmpb = ft_realloc(tmpb, count + 1);
    if (!tmpb)
        return (0);
    ft_strcpyex(tmpb, tmp, "\n");
    free(tmp);
    return (tmpb);
}

char    *extract_map_param(char *ber_file, t_map *map)
{
    char    *tmp;
    int     fd;

    fd = open(ber_file, O_RDONLY);
    if (fd < 1)
        return (0);
    tmp = read_map(fd, map);
    close(fd);
    if (!tmp)
        return (0);
    get_map_scale(map, tmp);
    if (map->x_max <= 1 || map->y_max <= 1)
    {
        free(tmp);
        return (0);
    }
    tmp = formatted_map(map, tmp);
    if (!tmp)
        return (0);
    return (tmp);
}
