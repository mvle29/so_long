/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_context.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathvall <mathvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 00:51:55 by mathou            #+#    #+#             */
/*   Updated: 2025/11/06 13:42:50 by mathvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

t_mlx   *init_mlx(void)
{
    t_mlx   *mlx;

    mlx = malloc(sizeof(t_context));
    if (!mlx)
        return (0);
    setzero_mlx(mlx);
    mlx->mlx = mlx_init();
    if (!mlx->mlx)
    {
        free(mlx);
        printf("MLX_INIT ECHOUE \n");
        return (0);
    }
    mlx->win_w = 600;
    mlx->win_h = 400;
    mlx->win = mlx_new_window(mlx->mlx, mlx->win_w, mlx->win_h, "so_long!");
    if (!mlx->win)
    {
        printf("MLX_WIN ECHOUE \n");
        mlx_destroy_display(mlx->mlx);
        free(mlx->mlx);
        free(mlx);
        return (0);
    }
    printf("MLX INIT VALIDE \n");
    return (mlx);
}

t_context   *init_context(t_mlx *mlx)
{
    t_context   *context;

    if (!mlx)
        return (0);
    context = malloc(sizeof(t_context));
    if (!context)
        return (0);
    setzero_context(mlx);
    context->mlx = mlx;
    context->img_h = context->mlx->win_h;
    context->img_w = context->mlx->win_w;
    context->bpp = 0;
    context->ll = 0;
    context->endian = 0;
    context->img = mlx_new_image(mlx->mlx, context->img_w, context->img_h);
    if (context->img)
        context->addr = mlx_get_data_addr(context->img, &context->bpp, &context->ll, &context->endian);
    if (!context->addr)
    {
        free_context(context);
        return (0);
    }
    return (context);
}
