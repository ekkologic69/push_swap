/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:58:46 by maboulho          #+#    #+#             */
/*   Updated: 2021/12/16 16:34:27 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s1)
		return (ft_strdup(s2));
	len = ft_strlen(s1) + ft_strlen(s2);
	dest = malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		dest[j++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		dest[j++] = s2[i++];
	}
	dest[j] = '\0';
	free(s1);
	return (dest);
}

int	ft_strchr( char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if (s[i] == (char)c)
		return (i);
	return (-1);
}

void	ft_strlcpy(char *dest, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dest[i] = ((char *)src)[i];
		i++;
	}
	dest[i] = '\0';
	i = 0;
	while (src[i])
		i++;
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	x;
	size_t	g;
	size_t	sub_size;

	if (!s)
		return (NULL);
	g = ft_strlen(s);
	x = 0;
	if (start >= g)
	{
		return (ft_strdup(""));
	}
	sub_size = g - start + 1;
	if (sub_size > len + 1)
		sub_size = len + 1;
	dst = malloc(sub_size);
	if (!dst)
		return (NULL);
	while (x < len && s[start])
		dst[x++] = s[start++];
	dst[x] = '\0';
	return (dst);
}

char	*ft_strdup(char *s1)
{
	char	*p;
	int		i;

	i = 0;
	p = malloc ((ft_strlen(s1) + 1) * sizeof (char));
	if (!p)
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
