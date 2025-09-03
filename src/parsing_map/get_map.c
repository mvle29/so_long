/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:44:55 by mathou            #+#    #+#             */
/*   Updated: 2025/09/03 19:55:28 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char    *read_map(char *ber_file, t_map *map)
{
    char    *tmp;
    int     len;
    int     r;
    char    buf;
    int     fd;

    fd = open(ber_file, RD_ONLY);
    if (fd < 1)
        return (0);
    r = read(fd, buf, 1);
    tmp = malloc (sizeof(char));
    if (!tmp)
        return (0);
    while (r)
    {
        tmp = ft_strjoin(tmp, &buf);
        if (!tmp)
            return (0);
        r = read(fd, buf, 1);
    }
    if (r == -1)
    {
        free(tmp);
        return (0);
    }
    tmp = ft_strjoin(tmp, &buf);
    return (tmp);
}

int malloc_grid(t_map *map)
{
    int x;

    map->grid = malloc(sizeof(char*) * (map->width + 1));
    if (!map->grid)
        return (0);
    x = 0;
    while (x <= map->width)
    {
        map->grid[x] = malloc(sizeof(char) * (map->height + 1));
        if (!map->grid[x])
            return (0);
        x++;
    }
    return (1);
}

int stock_map(char *ber_file, t_map *map)
{
    char    *tmp;
    int     x;
    int     y;
    int     i;

    tmp = read_map(ber_file, map);
    if (!tmp || map->width <= 1 || map->height <= 1)
        return (0);
    if (!malloc_grid(map))
        return (0);
    x = 0;
    i = 0;
    while (x <= map->width)
    {
        y = 0;
        while (y <= map->height)
        {
            map->grid[x][y] = tmp[i];
            i++;
            y++;
        }
        x++;
    }
    free(tmp);
    return (1);
}

int get_map(t_map *map, char *av_map)
{
    int x;
    int y;

    if (!stock_map(av_map, map)) // si ca marche pas, map non rectangulaire ou insuffisante
        return (0);
    x = 0;
    while (x <= map->width)
    {
        y = 0;
        while (y <= map->height)
        {
            update_map_info(map, x, y);
            if (!orginal_value(map, x, y) || !valid_map_info(map, x, y)) // un seuil a ete depasse dans les conditions, ou une valeur interdite a été utilisee
                return (0);
            y++;
        }
        x++;
    }
    return (1);
}
