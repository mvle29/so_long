/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavallee <mavallee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:23:14 by mavallee          #+#    #+#             */
/*   Updated: 2024/06/01 16:09:28 by mavallee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (n * (-1));
	return (n);
}

static int	count_int_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*itoa;
	int		len;
	int		sign;

	sign = 1;
	itoa = malloc(sizeof(char) * (count_int_len(n) + 1));
	if (!itoa)
	{
		return (NULL);
	}
	if (n < 0)
	{
		itoa[0] = '-';
		sign = -1;
	}
	len = count_int_len(n) - 1;
	itoa[count_int_len(n)] = '\0';
	while ((len != -1 && sign == 1) || (len != 0 && sign == -1))
	{
		itoa[len] = ft_abs(n % 10) + '0';
		n /= 10;
		len--;
	}
	return (itoa);
}
/*
int	main(void)
{
	char	*itoa;

	itoa = ft_itoa(-555);
	printf("\n%s", itoa);
	printf("\n%d", count_int_len(555));
}
*/