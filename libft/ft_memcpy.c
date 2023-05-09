/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmomeni <mmomeni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:50:01 by mmomeni           #+#    #+#             */
/*   Updated: 2023/03/24 12:36:46 by mmomeni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*_src;
	char		*_dst;

	if (!dst && !src && n)
		return (NULL);
	_src = (const char *) src;
	_dst = (char *) dst;
	while (n--)
		*_dst++ = *_src++;
	return (dst);
}
