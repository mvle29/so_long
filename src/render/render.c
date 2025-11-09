/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathvall <mathvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:03:06 by mathou            #+#    #+#             */
/*   Updated: 2025/11/09 20:08:41 by mathvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void    render_buf(t_game *game)
{
    t_context   *tmp;

    tmp = game->on_screen;
    game->on_screen = game->cur;
    mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, game->on_screen->img, 0, 0);
    game->cur = tmp;
}

int get_last_line(int map_pos, int cam_offset, t_game *game, int cam_max)
{
    int last_pos;

    last_pos = map_pos;
    while (cam_offset + last_pos * game->tile <= cam_max)
        last_pos++;
    return (last_pos);
}

void    pixel_copy(t_game *game, t_pos txt_poss, t_pos img_poss, t_anim *cur)
{
    char            *pixel;
    unsigned int    color;
    t_context       *img_cont;
    t_context       *txt_cont;

    img_cont = game->cur;
    txt_cont = cur->text;
    pixel = txt_cont->addr + (txt_poss.x * (txt_cont->bpp / 8) + txt_poss.y * txt_cont->ll); // i = rangee a laquelle on s interesse
    color = *(unsigned int *)pixel;
    if (color != 4278190080)
    {
        pixel = img_cont->addr + (img_poss.x * (img_cont->bpp / 8) + img_poss.y * img_cont->ll);
        *(unsigned int *)pixel = color;
    }
}

// d abord : on update sprites->hitbox, puis la map (si hitbox est en contact avec autre hitbox), puis sprites-> text, puis le context?

int    render(t_game *game)
{
    // update_instances(game->spritess->instances, game->map); // on get la hb_map, on l update avec la touche pressee et avec l overlap, on update la map en consequence
    //render_background(game, game->map, game->spritess, game->cam);
    render_ground(game, game->map, game->spritess, game->cam);
    render_instances(game, game->map, game->map->instances, game->cam);
    //display_recipe(game->spritess->recipe, game->map, game->context);
    //if (player_found_exit(game->map) && game->map->collectibles == 0)
    //    end_display();
    if (game)
        render_buf(game);
    set_instance_anim(game->map->player, game->map->player->cur->name);
    cam_update(game->mlx, game->cam, game->map);
    return (game->tile);
}
// finalement : est ce qu on display les instances ? ou plutot a partir de la map logique ? Pour le player, c est a partir de l instance. Le reste plutot map logique ?
