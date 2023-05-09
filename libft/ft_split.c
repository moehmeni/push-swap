/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmomeni <mmomeni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 10:54:41 by mmomeni           #+#    #+#             */
/*   Updated: 2023/03/31 16:39:29 by mmomeni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	words_count(char const *s, char c)
{
	size_t	n;

	n = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
			n++;
		while (*s != c && *s)
			s++;
	}
	return (n);
}

static void	free_all(char **v)
{
	char	**start;

	start = v;
	while (*v)
	{
		free(*v);
		v++;
	}
	free(start);
}

static char	**split_return(char const *s, char c, char **v, int wlen)
{
	int			i;
	int			j;
	char const	*w;

	i = 0;
	while (i < wlen)
	{
		j = 0;
		while (*s == c && *s)
			s++;
		w = s;
		while (*s != c && *s)
		{
			j++;
			s++;
		}
		v[i] = ft_calloc(j + 1, sizeof(char));
		if (!v[i])
		{
			free_all(v);
			return (NULL);
		}
		ft_strlcpy(v[i++], w, j + 1);
	}
	return (v);
}

char	**ft_split(char const *s, char c)
{
	int			wlen;
	char		**v;

	if (!s)
		return (NULL);
	wlen = words_count(s, c);
	v = ft_calloc(wlen + 1, sizeof(char *));
	if (!v)
		return (NULL);
	return (split_return(s, c, v, wlen));
}
