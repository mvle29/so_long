/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathou <mathou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:38:35 by mavallee          #+#    #+#             */
/*   Updated: 2025/10/10 03:37:31 by mathou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_mult(unsigned int i, size_t size)
{
	int	temp;

	temp = size;
	temp *= i;
	if (size == 0 || i == 0)
		return (1);
	if (temp / i == size || temp / size == i)
		return (1);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	size_t			bit;
	unsigned int	i;

	i = 0;
	bit = 0;
	while (start < ft_strlen(s) && s[start + i] && i < len)
		i++;
	if (!ft_mult(i, sizeof(char)) || !s)
		return (NULL);
	dest = malloc((i + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	if (i == 0)
		dest[0] = '\0';
	else
	{
		bit = ft_strlcpy(dest, (char *)(s + start), i + 1);
		if (ft_strncmp(dest, (char *)(s + start), i) != 0
			&& ft_strlen(dest) > 1)
			return (NULL);
	}
	bit = bit + 1;
	return (dest);
}
/*
int	main(void)
{
	const	char	*s = "Ala bonne heure !";

	printf("%s", ft_substr(s, 100, 1));
}
*/