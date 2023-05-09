/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmomeni <mmomeni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:34:04 by mmomeni           #+#    #+#             */
/*   Updated: 2023/05/07 19:44:06 by mmomeni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*read_next_line(int fd, char *tmp, char *mem)
{
	int		fb;
	char	*mem_tmp;

	fb = 1;
	while (fb)
	{
		fb = read(fd, tmp, BUFFER_SIZE);
		if (fb == -1)
			return (NULL);
		if (fb == 0)
			break ;
		tmp[fb] = '\0';
		if (!mem)
			mem = ft_strdup("");
		mem_tmp = mem;
		mem = ft_strjoin(mem_tmp, tmp);
		free(mem_tmp);
		mem_tmp = NULL;
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	return (mem);
}

static char	*mem_update(char *line)
{
	size_t	i;
	char	*mem;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i] || !line[1])
		return (NULL);
	mem = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!(*mem))
	{
		free(mem);
		mem = NULL;
	}
	line[i + 1] = '\0';
	return (mem);
}

char	*get_next_line(int fd)
{
	static char	*mem;
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	line = read_next_line(fd, tmp, mem);
	free(tmp);
	tmp = NULL;
	if (!line)
	{
		free(mem);
		mem = NULL;
		return (NULL);
	}
	mem = mem_update(line);
	return (line);
}
