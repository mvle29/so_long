/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_playerupd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 06:18:44 by mathou            #+#    #+#             */
/*   Updated: 2025/10/09 22:10:54 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

void    upd_anim(t_instance *instance, char *anim_name)
{
    int     i;

    if (ft_strcmp(instance->cur->name, anim_name) == 0)
    {
        if (instance->cur->next)
            instance->cur = instance->cur->next;
        else
            instance->cur = instance->cur->head;
        return ;
    }
    else
    {
        i = 0;
        while (instance->sprite->anim[i])
        {
            if (ft_strcmp(instance->sprite->anim[i]->name, anim_name) == 0)
            {
                instance->cur = instance->sprite->anim[i];
                return ;
            }
            i++;
        }
    }
}

void    signals_playerupd_collectibles(t_map *map, t_instance *player, t_instance ***instances)
{
    t_pos   map_poss;

    map_poss.y = 0;
    while (map_poss.y <= map->y_max)
    {
        map_poss.x = 0;
        while (map_poss.x <= map->x_max)
        {
            if (instances[map_poss.y][map_poss.x])
            {
                if (instances[map_poss.y][map_poss.x]->sprite->name == "collectible" && instances_overlap(instances[map_poss.y][map_poss.x], player))
                {
                    free_instance(instances[map_poss.y][map_poss.x]);
                    instances[map_poss.y][map_poss.x] = 0;
                    map->collectibles--;
                }
            }
            map_poss.x++;
        }
        map_poss.y++;
    }
}

void    signals_playerupd(t_game *game, int x, int y, char *anim_name)
{
    t_map       *map;
    t_pos       next_map_pos;
    t_anim      *anim;
    t_instance  *player;
    t_instance  *exit;

    map = game->map;
    player = map->player;
    exit = exit_find();
    next_map_pos.x = (map->player->feet_pos.x + x) / game->tile;
    next_map_pos.y = (map->player->feet_pos.y + y) / game->tile;
    if (ft_strcmp(player->cur->name, "exit") == 0 || (instances_overlap(player, exit) && map->collectibles == 0))
    {
        signals_playerupd_exitpos();
        upd_anim(player, "exit");
        return ;
    }
    signals_playerupd_anim(player, anim_name);
    if (!overlap())
    {
        map->player->feet_pos.x += x;
        map->player->feet_pos.y += y;
    }
    signals_playerupd_collectibles(game->map, game->map->player, game->map->instances);
}
