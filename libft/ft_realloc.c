/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 02:56:30 by mathou            #+#    #+#             */
/*   Updated: 2025/10/10 03:02:06 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_realloc(char *str, int size)
{
    char    *strr;
    
    if (size <= 0)
    {
        if (str)
            free(str);
        return (0);
    }
    strr = ft_calloc(size, 1);
    if (!strr)
    {
        if (str)
            free(str);
        return (0);
    }
    if (str)
    {
        ft_strlcpy(strr, str, sizeof(char) * (ft_strlen(str) + 1));
        free(str);
    }
    return (strr);
}
