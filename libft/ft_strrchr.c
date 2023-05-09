/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmomeni <mmomeni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:16:03 by mmomeni           #+#    #+#             */
/*   Updated: 2023/03/23 22:47:53 by mmomeni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*_c;

	i = 0;
	_c = NULL;
	while (s[i])
	{
		if (s[i] == (char) c)
			_c = ((char *) s + i);
		i++;
	}
	if ((char) c == '\0')
		return ((char *) s + i);
	return (_c);
}
