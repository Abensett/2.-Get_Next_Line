/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:19:23 by abensett          #+#    #+#             */
/*   Updated: 2021/09/10 14:19:27 by abensett         ###   ########.fr       */
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

char	*ft_strnew(size_t size)
{
	char	*s;

	s = malloc((size + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	ft_memset(s, 0, size);
	return (s);
}

void	ft_memdel(void **ptr)
{
	if (*ptr && ptr)
	{
		free(*ptr);
		ptr = 0;
	}
}

char	*get_line_printed(char *line, int len)
{
	char	*line_to_print;
	int		i;

	i = 0;
	if (len == 0)
		line_to_print = ft_strdup(line);
	else
		line_to_print = ft_substr(line, 0, (ft_strchr(line, '\n') - line));
	while (line_to_print[i])
	{
		write(1, &line_to_print[i], 1);
		i++;
	}
	write(1, "\n",1);
	return (line_to_print);
}



char	*get_next_line(int fd)
{
	char		*buff;
	int			len;	
	static char	*line;
	char		*tmp;
	char		*linetoprint;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (line == NULL)
		line = ft_strnew(0);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	len = read(fd, buff, BUFFER_SIZE);
	while (!ft_strchr(line, '\n') && len > 0)
	{
		buff[len] = '\0';
		tmp = ft_strjoin(line, buff);
		ft_memdel((void **)&line);
		line = tmp;
	}
	if (len < 0)
		return (NULL);
	printf("%d",len);	
	linetoprint =  get_line_printed(line, len);
	if (len > 0)
		tmp = ft_strdup((line + (ft_strlen(linetoprint) + 1)));
	else
		tmp = ft_strdup((line + ft_strlen(linetoprint)));
	ft_memdel((void **)&line);
	line = tmp;
	printf("MON PRINT %s\n",linetoprint);

	return (linetoprint);
}
