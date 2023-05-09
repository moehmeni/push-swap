/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmomeni <mmomeni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:49:57 by mmomeni           #+#    #+#             */
/*   Updated: 2023/03/24 16:44:55 by mmomeni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	n;
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	i = 0;
	dst_len = ft_strlen(dst);
	n = dst_len;
	if (dstsize < dst_len)
		return (dstsize + src_len);
	while (src[i] && n < (dstsize - 1))
		dst[n++] = src[i++];
	dst[n] = '\0';
	return (dst_len + src_len);
}
