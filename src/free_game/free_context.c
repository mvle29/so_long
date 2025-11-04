/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_context.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 06:17:14 by marvin            #+#    #+#             */
/*   Updated: 2025/10/13 06:17:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void    free_mlx(t_mlx *mlx)
{
    if (mlx->mlx)
    {
        if (mlx->win)
            mlx_destroy_window(mlx->mlx, mlx->win);
        mlx_destroy_display(mlx->mlx);
        free(mlx->mlx);
    }
    free(mlx);
}

void    free_context(t_context *context)
{
    if (context)
    {
        if (context->img)
            mlx_destroy_image(context->mlx->mlx, context->img);
        free(context);
    }
}
