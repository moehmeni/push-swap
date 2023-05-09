/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmomeni <mmomeni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:15:28 by mmomeni           #+#    #+#             */
/*   Updated: 2023/03/28 14:11:47 by mmomeni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"
#define N 20
#define INT_MIN -2147483648

static char	*ft_itoa_return(int i, int neg, int n, int *mem)
{
	char	*s;
	int		j;

	while (n)
	{
		mem[i++] = n % 10;
		n /= 10;
	}
	if (neg)
		mem[i++] = '-';
	s = malloc((i * sizeof(char)) + 1);
	if (!s)
		return (NULL);
	j = i;
	while (i--)
	{
		*s++ = (mem[i]) + 48;
		if (mem[i] == '-')
			*(s - 1) -= 48;
	}
	*s = '\0';
	return (s - j);
}

char	*ft_itoa(int n)
{
	int		i;
	int		mem[N];
	int		neg;

	i = 0;
	neg = 0;
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	if (n < 1)
	{
		n = -1 * n;
		if (n)
			neg = 1;
		else
			return (ft_strdup("0"));
	}
	return (ft_itoa_return(i, neg, n, mem));
}
