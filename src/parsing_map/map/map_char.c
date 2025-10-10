/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 00:55:41 by mathou            #+#    #+#             */
/*   Updated: 2025/10/10 03:46:23 by mathou           ###   ########.fr       */
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
    while (tmp[n] == '\n')
        n++;
    while (tmp[n + i])
    {
        if (map->x_max == -1 && tmp[n + i] == '\n')
            map->x_max = i - 1;
        else if (i > 0 && tmp[n + i] == '\n' && tmp[n + i - 1] == '\n')
            return ;
        else if (tmp[n + i] == '\n' && (i - 1) % map->x_max != 0 
            && (i - 1) / map->x_max != map->y_max) // Pas bon : y = 0 par ex
        {
            map->x_max = 0;
            return ;
        }
        if (tmp[n + i] == '\n' && tmp[n + i + 1])
            map->y_max++;
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
    while (tmp[i])
    {
        tmpb = malloc(sizeof(char) * (count + 1));
        if (!tmpb)
        {
            free(tmp);
            return (0);
        }
        if (tmp[i] != '\n')
        {
            tmpb[count] = tmp[i];
            count++;
        }
        i++;
    }
    tmpb[count] = '\0';
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
    if (map->x_max <= 2 || map->y_max <= 2)
    {
        free(tmp);
        return (0);
    }
    tmp = map_char_formatted(tmp);
    if (!tmp)
        return (0);
    return (tmp);
}
