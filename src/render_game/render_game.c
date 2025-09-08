/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:03:06 by mathou            #+#    #+#             */
/*   Updated: 2025/09/07 23:22:53 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void    display_map(t_text *map_text, t_context *context)
{
    
}

void    display_player(t_sprite *player, t_context *context)
{
    
}


// d abord : on update sprites->hitbox, puis la map (si hitbox est en contact avec autre hitbox), puis sprites-> text, puis le context?

void    render_game(t_game *game)
{
    void    *img2;
    
    img2 = get_buf(game->context);
    update_instances(game->spritess->instances, game->map); // on get la hb_map, on l update avec la touche pressee et avec l overlap, on update la map en consequence
    display_map(game->spritess->empty, game->context); // on guette la map logique, taille de l hitbox, on affiche avc marge appropriee
    display_walls(game->spritess->walls, game->context, game->map);
    display_player(game->spritess->player, game->context, game->spritess->instances);
    display_collectibles(game->spritess->collectibles->text, game->context);
    display_exit(game->spritess->exit->text, game->context);
    //display_recipe(game->spritess->recipe, game->map, game->context);
    if (player_found_exit(game->map) && game->map->collectibles == 0)
        display_end();
    switch_buf(buf2, game->context);
}
// finalement : est ce qu on display les instances ? ou plutot a partir de la map logique ? Pour le player, c est a partir de l instance. Le reste plutot map logique ?