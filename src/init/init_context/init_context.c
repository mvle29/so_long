/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_context.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 00:51:55 by mathou            #+#    #+#             */
/*   Updated: 2025/09/28 02:22:36 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_mlx   *init_mlx(void)
{
    t_mlx   *mlx;

    mlx = malloc(sizeof(t_context));
    if (!mlx)
        return (0);
    mlx->mlx = mlx_init();
    if (!mlx->mlx)
    {
        free(mlx);
        return (0);
    }
    mlx->win_w = 600;
    mlx->win_h = 400;
    mlx->win = mlx_new_window(mlx->mlx, mlx->win_w, mlx->win_h, "so_long!");
    if (!mlx->win)
    {
        free(mlx);
        return (0);
    }
    return (mlx);
}

t_context   *init_context(t_mlx *mlx)
{
    t_context   *context;

    if (!mlx)
        return (0);
    context = malloc(sizeof(t_context));
    if (!context)
    {
        free_mlx(mlx);
        return (0);
    }
    context->mlx = mlx;
    context->img_h = 400;
    context->img_w = 600;
    context->img = mlx_new_img(mlx->mlx, mlx->win, context->img_w, context->img_h);
    if (!context->img)
    {
        free_context(context);
        return (0);
    }
    context->addr = mlx_get_data_addr(context->img, &context->bpp, &context->ll, &context->endian);
    if (!context->addr)
    {
        free_context(context);
        return (0);
    }
    return (context);
}
