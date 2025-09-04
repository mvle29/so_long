/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:29:27 by mathou            #+#    #+#             */
/*   Updated: 2025/09/04 18:33:21 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

typedef struct  s_map
{
    char    *map;
    int     collectibles;
    int     exit;
    int     entry;
    char    **grid;
    int     x_max;
    int     y_max;
    int     px;
    int     py;
    int     next_px;
    int     next_py;
    int     ex;
    int     ey;
}           t_map;

typedef struct  s_context
{
    void    *mlx;
    void    *mlx_win;
    void    *img1;
    void    *img2;
    char    *addr;
    int     bits_ppix;
    int     line_len;
    int     endian;
}           t_context;

typedef struct s_game
{
    t_context   *context;
    t_map       *map;
}       t_game;

#endif