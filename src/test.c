/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:23:19 by marvin            #+#    #+#             */
/*   Updated: 2025/10/20 11:15:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    display_map(t_map *map)
{
    int x;
    int y;

    y = 0;
    printf("\n");
    while (y <= map->y_max)
    {
        x = 0;
        while (x <= map->x_max)
        {
            printf(" %c ", map->grid[y][x]);
            x++;
        }
        printf("\n");
        y++;
    }
}

int    display_error(char *str)
{
    printf("\n %s \n", str);
    exit(1);
}

int main(int agc, char **agv)
{
    t_map       *mapp;
    t_game      *game;
    
    game = 0;
    if (agc != 2)
        display_error("ARGS INVALIDES");
    mapp = map(agv[1]); // Fait
    if (!mapp)
        return (display_error("FAILED TO INIT_MAP"));
    display_map(mapp);
    game = init_game(mapp);
    if (!game)
        return (display_error("FAILED TO INIT GAME"));
    signals(game, game->cur);
    mlx_loop(game->cur->mlx->mlx);
    //free_game(game);
}
