/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:04:50 by abensett          #+#    #+#             */
/*   Updated: 2021/12/12 21:01:20 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *src)
{
	char			*dup;
	unsigned int	lensrc;

	lensrc = 0;
	while (src[lensrc])
		lensrc++;
	dup = malloc(sizeof(char) * (lensrc + 1));
	if (!dup)
		return (NULL);
	dup[lensrc] = '\0';
	while (lensrc-- != 0)
		dup[lensrc] = src[lensrc];
	return (dup);
}

void	ft_memdel(void **ptr)
{
	if (*ptr)
	{
		ft_memset(*ptr, 0, ft_strlen(*ptr));
		free(*ptr);
		*ptr = NULL;
	}
}

char	*get_line_printed(char **line, ssize_t len)
{
	char	*to_print;
	char	*tmp;

	tmp = NULL;
	if (len == 0 && **line == '\0')
	{
		ft_memdel((void **)line);
		return (NULL);
	}
	if (len == 0)
		to_print = ft_strdup(*line);
	else
		to_print = ft_substr(*line, 0, (ft_strchr(*line, '\n') + 1 - *line));
	if (len > 0)
		tmp = ft_strdup((*line + (ft_strlen(to_print))));
	ft_memdel((void **)line);
	*line = tmp;
	return (to_print);
}

char	*get_next_line(int fd)
{
	ssize_t		len;	
	char		buff[BUFFER_SIZE + 1];
	static char	*line;
	char		*tmp;

	len = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!ft_strchr(line, '\n') && len > 0)
	{
		len = read(fd, buff, BUFFER_SIZE);
		if (len < 0)
			return (NULL);
		buff[len] = '\0';
		tmp = ft_strjoin(line, buff);
		ft_memdel((void **)&line);
		line = tmp;
	}
	return (get_line_printed(&line, len));
}
