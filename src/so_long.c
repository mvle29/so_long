/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 23:08:27 by mathou            #+#    #+#             */
/*   Updated: 2025/09/03 19:38:45 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int main(int agc, char **agv)
{
    context;
    t_map *map;
    
    map = ckeck_map(agc, agv);
    if (!map)
        return (display_error());
    context = create_context();
    if (!context)
        return (display_error());
    while (faut_aff(map, context))
    {
        test_signals();
        update_map(map, context);
    }
    close_context(context);
    free(map);
}
