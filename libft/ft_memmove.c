/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmomeni <mmomeni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:50:56 by mmomeni           #+#    #+#             */
/*   Updated: 2023/03/24 20:22:32 by mmomeni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	*ft_memmove(void *dst, const void *src, size_t len)
// {
// 	unsigned char	*tmp;

// 	if (!dst && !src && len)
// 		return (NULL);
// 	tmp = (unsigned char *) ft_calloc(len, sizeof(unsigned char));
// 	ft_memcpy(tmp, src, len);
// 	ft_memcpy(dst, tmp, len);
// 	free(tmp);
// 	return (dst);
// }

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*pdst;
	unsigned char	*psrc;

	if (!dst && !src && len)
		return (NULL);
	pdst = (unsigned char *) dst;
	psrc = (unsigned char *) src;
	if (pdst < psrc)
		return (ft_memcpy(dst, src, len));
	pdst += len;
	psrc += len;
	while (len--)
		*--pdst = *--psrc;
	return (dst);
}
