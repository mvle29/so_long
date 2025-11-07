/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_anim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathvall <mathvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:48:47 by mathvall          #+#    #+#             */
/*   Updated: 2025/11/06 13:17:22 by mathvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	update_anim(t_game *game, struct timeval  tv)
{
	int	x;
	int	y;
	t_map *map;

	map = game->map;
	y = 0;
	while (y <= map->y_max)
	{
		x = 0;
		while (x <= map->x_max)
		{
			set_instance_anim(game->map->instances[y][x], game->map->instances[y][x]->cur->name, tv);
			x++;
		}
		y++;
	}
	set_instance_anim(game->map->player, game->map->player->cur->name, tv);
}
