/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handle_signals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:46:44 by mathou            #+#    #+#             */
/*   Updated: 2025/09/04 18:24:11 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

// go up doit trgger animation up etc etc. Le but c est d update px et py ici.

void    mlx_handle_signals(t_map *map, t_context *context)
{
    mlx_hook(&context->mlx_win, , close_context, context);
    mlx_hook(&context->mlx_win, , go_up, map);
    mlx_hook(&context->mlx_win, , go_down, map);
    mlx_hook(&context->mlx_win, , go_right, map);
    mlx_hook(&context->mlx_win, , go_left, map);
    mlx_loop_hook(context->mlx, render_game, map);
}
