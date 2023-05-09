/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmomeni <mmomeni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:49:00 by mmomeni           #+#    #+#             */
/*   Updated: 2023/03/23 22:13:51 by mmomeni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*mem;

	len = ft_strlen(s1);
	mem = malloc((len + 1) * sizeof(char));
	if (!mem)
		return (NULL);
	mem[len] = '\0';
	while (len--)
		mem[len] = s1[len];
	return (mem);
}
