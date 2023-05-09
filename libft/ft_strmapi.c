/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmomeni <mmomeni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:25:22 by mmomeni           #+#    #+#             */
/*   Updated: 2023/03/31 18:58:21 by mmomeni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*_s;

	if (!s)
		return (NULL);
	_s = malloc(ft_strlen(s) + 1);
	if (!_s)
		return (NULL);
	i = 0;
	while (s[i++])
		*_s++ = (*f)(i - 1, s[i - 1]);
	*_s = '\0';
	return (_s - (i - 1));
}
