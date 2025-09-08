/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_spritess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 01:57:03 by mathou            #+#    #+#             */
/*   Updated: 2025/09/09 00:55:16 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h" // comment charger une image externe ? On la transforme en img, on copie l img dans notre big img (le buf) a la bonne addresse : il faudra donc une jolie fonction qui copie a la position x y notre img.
// la texture c est juste le relative path du coup !
void    *init_text_img(t_sprite *sprite, t_text *text, char *text_path, t_context *context)
{
    void    *img;
    char    *xpm_name;

    xpm_name = add_xpm(text->name);
    if (!xpm_name)
    {
        free(text->img);
        return ;
    }
    text->img = xpm_to_mlx_img();
    if (!text->img)
        return ;
}

void    assign_textures(t_sprite *sprite, char **textures, char *text_path, t_context *context)
{
    int i;

    i = 0;
    if (!sprite->hb)
        return ;
    while (textures[i])
    {
        sprite->text[i] = malloc(sizeof(t_text));
        if (sprite->text[i])
            sprite->text[i]->name = ft_strdup(textures[i]);
        if (sprite->text[i] && sprite->text[i]->name)
            sprite->text[i]->img = init_text_img(sprite->text[i], text_path, context); // tt ca retourne 0 en cas d erreur donc oklm pour les free on checke la ou il y a des 0
        if (!sprite->text[i] || !sprite->text[i]->name || !sprite->text[i]->img)
        {
            free_sprite(sprite);
            return ;
        }
        i++;
    } 
    sprite->text[i] = 0;
}

t_sprite    *init_sprite(char *text_name, char *text_path, char *text_hb, t_context *context)
{
    t_sprite    *sprite;
    char        **textures;
    int         i;

    sprite = malloc(sizeof(t_sprite));
    if (!sprite)
        return (0);
    textures = ft_split(text_name, ", ");
    sprite->text = malloc(sizeof(t_text*) * (ft_count_split(textures) + 1));
    if (!textures || !sprite->text)
    {
        if (textures)
            free_split(textures);
        free_sprite(sprite);
        return (0);
    }
    init_hb(sprite, text_hb);
    assign_textures(textures[i], text_path, text_hb, context);
    free_split(textures);
    return (sprite);
} // plsrs options d init spriteet : 

t_spritess  *init_spritess(t_context *context, t_map *map)
{
    t_spritess  *spritess;

    if (!context)
        return (0);
    spritess = malloc(sizeof(t_spritess));
    if (!spritess)
        return (0);
    spritess->walls = init_sprite("middle, up, up_right, up_left, up_left_right,\
         up_down, all, right, right_down, right_left, right_left_down, \
         down, down_left, left", "../../text/walls", "1, 2", context);
    spritess->empty = init_sprite("empty", "../../text/empty", "1, 2", context);
    spritess->player = init_sprite("static1, static2, go_left, go_right, \
        go_up, go_down, exit", "../../text/player", "1, 2", context);
    spritess->collectibles = init_sprite("collectibles", 
            "../../textures/collectibles", "1, 2", context);
    spritess->exit = init_sprite("exit", "../../text/exit", "1, 2", context);
    spritess->instances = init_instances(spritess, map);
    if (!spritess->exit || !spritess->collectibles || !spritess->player ||
            !spritess->empty || !spritess->walls || !spritess->instances)
    {
        free_spritess(spritess);
        return (0);
    }
    return (spritess);
}
// free spritess, free sprite(info dedans). Set a 0 pour le risque que ca s efface pas?