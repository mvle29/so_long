/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_instances_anim.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 23:25:43 by marvin            #+#    #+#             */
/*   Updated: 2025/10/13 23:25:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

/*char    *anim_name_wallpos(t_map *map, t_pos wall, t_pos pos, t_instance *wall)
{
    if(pos.x == wall.x + 2 && pos.y != wall.y + 1)
    {
        pos.x = wall.x - 1;
        pos.y = pos.y + 1;
    }
    else if (pos.x == wall.x + 1 != pos.x == wall.x + 1)
        return ;
    else if (pos.x == wall.x && pos.y == wall.y)

    else if (!ft_strcmp(wall->sprite->anim[pos.y][pos.x]->sprite->name, "walls") &&)
}*/

void    set_instance_anim(t_instance *instance, char *anim_name, struct timeval  *tv)
{
    int     i;

    if (instance->cur && !ft_strcmp(instance->cur->name, anim_name)
    && (!instance->cur->tv || tv->tv_sec - instance->cur->tv->tv_sec >= instance->cur->fpt))
    {
        instance->cur->tv = tv;
        instance->cur = instance->cur->next;
        if (!instance->cur->text)
            instance->cur = instance->cur->next;
        return ;
    }
    else if (instance->cur && ft_strcmp(instance->cur->name, anim_name))
    {
        instance->cur->tv = tv;
        i = 0;
        while (instance->sprite->anims[i])
        {
            if (ft_strcmp(instance->sprite->anims[i]->name, anim_name) == 0)
            {
                instance->cur = instance->sprite->anims[i];
                return ;
            }
            i++;
        }
    }
}
