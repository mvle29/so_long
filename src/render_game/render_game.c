/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:03:06 by mathou            #+#    #+#             */
/*   Updated: 2025/09/04 18:32:29 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void    display_map(t_map *map)
{
    
}

void    display_player(t_map *map)
{
    if (map->next_px == map->px + 1) // go right
        display_animation_right(map);
    if (map->next_px == map->px - 1) // go left
        display_animation_left(map);
    if (map->next_py == map->py + 1) // go up
        display_animation_up(map);
    if (map->next_py == map->py - 1) // go down
        display_animation_down(map);
    // display l image xmp a la bonne adresse
    if (map->collectibles != count_collectibles(map))
        display_animation_collectibles(map);
}

void    render_game(t_map *map)
{
    display_map(map);
    display_player(map);
    if (player_found_exit(map) && map->collectibles == 0)
        display_end();
    display_collectibles(map);
    switch_buf(map);
}
