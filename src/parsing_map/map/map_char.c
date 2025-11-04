/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 00:55:41 by mathou            #+#    #+#             */
/*   Updated: 2025/10/11 04:18:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

char    *map_char_get(int fd)
{
    int     r;
    char    *tmp;
    char    buf;

    buf = 0;
    r = read(fd, &buf, 1);
    if (r < 1)
        return (0);
    tmp = 0;
    while (r)
    {
        tmp = ft_realloc(tmp, sizeof(char) * (2 + ft_strlen(tmp)));
        if (!tmp)
            return (0);
        ft_strlcat(tmp, &buf, sizeof(char) * (2 + ft_strlen(tmp)));
        r = read(fd, &buf, 1);
    }
    if (r < 0)
    {
        free(tmp);
        return (0);
    }
    return (tmp);
}

void    map_info(t_map *map, char *tmp)
{
    int i;
    int n;

    i = 0;
    n = 0;
    while (ft_isspace(tmp[i]))
        n++;
    while (tmp[n + i])
    {
        if (map->x_max == -1 && ft_isspace(tmp[n + i]))
            map->x_max = i - 1;
        while (ft_isspace(tmp[n + i]) && ft_isspace(tmp[n + i + 1]))
            n++;
        if (ft_isspace(tmp[n + i]) && i % (map->x_max + 1) != 0
            && i / (map->x_max + 1) != map->y_max - 1) // Pas bon : y = 0 par ex
        {
            map->x_max = 0;
            return ;
        }
        if (ft_isspace(tmp[n + i]) && tmp[n + i + 1])
        {
            n++;
            map->y_max++;
        }
        else
            i++;
    }
}

char    *map_char_formatted(char *tmp)
{
    char    *tmpb;
    int     i;
    int     count;

    i = 0;
    count = 0;
    tmpb = 0;
    while (tmp[i])
    {
        tmpb = ft_realloc(tmpb, sizeof(char) * (count + 2));
        if (!tmpb)
        {
            free(tmp);
            return (0);
        }
        if (!ft_isspace(tmp[i]))
        {
            tmpb[count] = tmp[i];
            count++;
        }
        tmpb[count] = '\0';
        i++;
    }
    free(tmp);
    return (tmpb);
}

char    *map_char(char *ber_file, t_map *map)
{
    char    *tmp;
    int     fd;

    fd = open(ber_file, O_RDONLY);
    if (fd < 1)
        return (0);
    tmp = map_char_get(fd);
    close(fd);
    if (!tmp)
        return (0);
    map_info(map, tmp);
    if (map->x_max < 2 || map->y_max < 2)
    {
        free(tmp);
        return (0);
    }
    tmp = map_char_formatted(tmp);
    if (!tmp)
        return (0);
    return (tmp);
}
