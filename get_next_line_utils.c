/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:05:18 by abensett          #+#    #+#             */
/*   Updated: 2021/06/09 18:13:08 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	int		i;
	int		d;
	int		f;

	if (little[0] == '\0')
		return ((char *) big);
	i = 0;
	while (big[i] && n != 0)
	{
		if (n < ft_strlen(little))
			return (NULL);
		d = 0;
		f = i;
		while (big[f] == little[d] && big[f] && little[d])
		{
			d++;
			f++;
		}
		if (little[d] == '\0')
			return ((char *) big + i);
		n--;
		i++;
	}
	return (NULL);
}
char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}
