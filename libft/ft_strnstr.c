/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmomeni <mmomeni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:16:01 by mmomeni           #+#    #+#             */
/*   Updated: 2023/03/24 10:50:17 by mmomeni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n_len;

	n_len = ft_strlen(needle);
	if (!n_len)
		return ((char *) haystack);
	while (len-- && *haystack)
	{
		if ((len + 1) < n_len)
			return (NULL);
		if (!ft_strncmp(haystack++, needle, n_len))
			return ((char *)(haystack - 1));
	}
	return (NULL);
}
