/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmomeni <mmomeni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:20:09 by mmomeni           #+#    #+#             */
/*   Updated: 2023/03/23 22:13:17 by mmomeni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*_s;

	i = 0;
	_s = (const char *) s;
	while (i < n)
	{
		if (_s[i] == (char) c)
			return ((void *) &_s[i]);
		i++;
	}
	return (NULL);
}
