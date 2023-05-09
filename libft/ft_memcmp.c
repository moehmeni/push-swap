/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmomeni <mmomeni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:27:23 by mmomeni           #+#    #+#             */
/*   Updated: 2023/03/23 22:13:24 by mmomeni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*_s1;
	const unsigned char	*_s2;

	i = 0;
	_s1 = (const unsigned char *) s1;
	_s2 = (const unsigned char *) s2;
	while (i < n)
	{
		if (_s1[i] != _s2[i])
			return (_s1[i] - _s2[i]);
		i++;
	}
	return (0);
}
