/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_playerupd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 06:18:44 by mathou            #+#    #+#             */
/*   Updated: 2025/10/23 11:34:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

int asset_overlap2(t_pos next, t_map *map, t_pos map_poss)
{
    t_pos       asset_line1;
    t_pos       asset_line2;
    t_instance  *compare;
    int         overlap;
    int         i;

    if (map_poss.x < 0 || map_poss.x > map->x_max || map_poss.y < 0 || map_poss.y > map->y_max)
        return (0);
    compare = map->instances[map_poss.y][map_poss.x];
    if (!compare->sprite)
        return (0);
    asset_line1.x = compare->feet_pos.x;
    asset_line1.y = compare->feet_pos.y;
    asset_line2.x = compare->feet_pos.x + compare->sprite->feet_hb.w;
    asset_line2.y = compare->feet_pos.y + compare->sprite->feet_hb.h;
    i = 0;
    overlap = 0;
    while (i <= 70)
    {
        if ((next.x + i <= asset_line2.x && next.x + i >= asset_line1.x) ||
        (next.x - i <= asset_line2.x && next.x - i >= asset_line1.x))
            overlap++;
        if ((next.y + i <= asset_line2.y && next.y + i >= asset_line1.y)
        || (next.y - i <= asset_line2.y && next.y - i >= asset_line1.y))
            overlap = ft_negative(overlap);
        if (overlap < 0)
            return (1);
        i++;
    }
    return (0);
}

int asset_overlap1(t_game *game, t_pos next, t_instance *instance, t_map *map)
{
    int     i;
    t_pos   tmp;
    t_pos   map_poss;

    i = 0;
    tmp.x = next.x;
    tmp.y = next.y;
    while (i < 4)
    {
        if (tmp.x > next.x + instance->sprite->feet_hb.w)
        {
            tmp.x = next.x;
            tmp.y += instance->sprite->feet_hb.h;
        }
        map_poss.x = tmp.x / game->tile;
        map_poss.y = tmp.y / game->tile;
        if (asset_overlap2(tmp, map, map_poss) && map->instances[map_poss.y][map_poss.x]->sprite != game->spritess->collectibles)
            return (1);
        tmp.x += instance->sprite->feet_hb.w;
        i++;
    }
    return (0);
}

void    signals_playerupd_collectibles(t_game *game, t_pos next, t_instance *instance, t_map *map)
{
    int     i;
    t_pos   tmp;
    t_pos   map_poss;

    i = 0;
    tmp.x = next.x;
    tmp.y = next.y;
    while (i < 4)
    {
        if (tmp.x > next.x + instance->sprite->feet_hb.w)
        {
            tmp.x = next.x;
            tmp.y += instance->sprite->feet_hb.h;
        }
        map_poss.x = tmp.x / game->tile;
        map_poss.y = tmp.y / game->tile;
        if (map->instances[map_poss.y][map_poss.x]->sprite == game->spritess->collectibles && asset_overlap2(tmp, map, map_poss))
        {
            map->collectibles -= 1;
            map->instances[map_poss.y][map_poss.x]->sprite = 0;
        }
        tmp.x += instance->sprite->feet_hb.w;
        i++;
    }
}

int    exit_overlap(t_game *game, t_pos next, t_instance *instance, t_map *map)
{
    int     i;
    t_pos   tmp;
    t_pos   map_poss;

    i = 0;
    tmp.x = next.x;
    tmp.y = next.y;
    while (i < 4)
    {
        if (tmp.x > next.x + instance->sprite->feet_hb.w)
        {
            tmp.x = next.x;
            tmp.y += instance->sprite->feet_hb.h;
        }
        map_poss.x = tmp.x / game->tile;
        map_poss.y = tmp.y / game->tile;
        if (map->instances[map_poss.y][map_poss.x]->sprite == game->spritess->exit && asset_overlap2(tmp, map, map_poss))
            return (1);
        tmp.x += instance->sprite->feet_hb.w;
        i++;
    }
    return (0); 
}

void    signals_playerupd(t_game *game, int x, int y, char *anim_name)
{
    t_map       *map;
    t_pos       next_map_pos;
    //t_anim      *anim;
    t_instance  *player;
    //t_instance  *exit;

    map = game->map;
    player = map->player;
    //exit = exit_find();
    next_map_pos.x = map->player->feet_pos.x + x;
    next_map_pos.y = map->player->feet_pos.y + y;
    if (!ft_strcmp(player->cur->name, "exit"))
        return ;
    set_instance_anim(player, anim_name);
    if (!asset_overlap1(game, next_map_pos, player, map) || (exit_overlap(game, next_map_pos, player, map) && map->collectibles == 0))
    {
        if (exit_overlap(game, next_map_pos, player, map) && map->collectibles == 0)
            set_instance_anim(player, "exit");
        map->player->feet_pos.x += x;
        map->player->feet_pos.y += y;
    }
    signals_playerupd_collectibles(game, next_map_pos, player, map);
}
