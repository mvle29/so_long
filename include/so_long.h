/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:29:27 by mathou            #+#    #+#             */
/*   Updated: 2025/09/03 19:42:25 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

typedef struct  s_map
{
    char    *map;
    size_t  collectibles;
    size_t  exit;
    size_t  entry;
    char    **grid;
    int width;
    int height;
    int px;
    int py;
    int ex;
    int ey;
}       t_map;

#endif