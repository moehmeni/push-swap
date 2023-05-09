/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmomeni <mmomeni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:49:42 by mmomeni           #+#    #+#             */
/*   Updated: 2023/03/31 18:56:26 by mmomeni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	size_t	dlen;
	char	*mem;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	dlen = s1len + s2len;
	mem = malloc((dlen * sizeof(char)) + 1);
	if (!mem)
		return (NULL);
	ft_memcpy(mem, s1, s1len);
	ft_memcpy(mem + s1len, s2, s2len);
	mem[dlen] = '\0';
	return (mem);
}
