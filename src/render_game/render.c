/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:03:06 by mathou            #+#    #+#             */
/*   Updated: 2025/10/09 07:00:42 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void    render_buf(t_game *game)
{
    t_context   *tmp;

    tmp = game->on_screen;
    game->on_screen = game->cur;
    mlx_on_win();
    game->cur = tmp;
}

void    pixel_copy(t_game *game, t_pos txt_poss, t_pos img_poss, t_anim *cur)
{
    unsigned int    pixel;
    t_context       *img_cont;
    t_context       *txt_cont;

    img_cont = game->cur;
    txt_cont = cur->text;
    pixel = (unsigned int)txt_cont->addr[txt_poss.x * (txt_cont->bpp / 8) + txt_poss.y * txt_cont->ll]; // i = rangee a laquelle on s interesse
    (unsigned int)(img_cont->addr[img_poss.x * (img_cont->bpp / 8) + img_poss.y * img_cont->ll]) = pixel;
}

// d abord : on update sprites->hitbox, puis la map (si hitbox est en contact avec autre hitbox), puis sprites-> text, puis le context?

void    render(t_game *game)
{
    // update_instances(game->spritess->instances, game->map); // on get la hb_map, on l update avec la touche pressee et avec l overlap, on update la map en consequence
    render_ground(game, game->map, game->spritess, game->cam);
    render_instances();
    //display_recipe(game->spritess->recipe, game->map, game->context);
    if (player_found_exit(game->map) && game->map->collectibles == 0)
        end_display();
    render_buf(game);
}
// finalement : est ce qu on display les instances ? ou plutot a partir de la map logique ? Pour le player, c est a partir de l instance. Le reste plutot map logique ?