/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:37:07 by maboulho          #+#    #+#             */
/*   Updated: 2022/06/17 02:47:58 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*test(char *buffer, int fd)
{
	int		size_readed;
	char	*tmp;

	size_readed = 1;
	tmp = malloc(BUFFER_SIZE + 1);
	while (size_readed != 0 && ft_strchr(buffer, '\n') == -1)
	{
		size_readed = read(fd, tmp, BUFFER_SIZE);
		if (size_readed == -1)
		{
			free (tmp);
			return (NULL);
		}
		tmp[size_readed] = '\0';
		buffer = ft_strjoin(buffer, tmp);
	}
	free (tmp);
	if (size_readed == 0 && *buffer == '\0')
	{
		free(buffer);
		buffer = NULL;
	}
	return (buffer);
}

char	*get_after_new_line(char *s, int line_index)
{
	int		i;
	char	*after_line;

	after_line = malloc(ft_strlen(s + line_index) + 1);
	i = 0;
	while (s[i + line_index])
	{
		after_line[i] = s[i + line_index];
		i++;
	}
	after_line[i] = '\0';
	free(s);
	return (after_line);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;
	int			index_line;

	buffer = test(buffer, fd);
	if (!buffer)
		return (0);
	index_line = ft_strchr(buffer, '\n');
	if (index_line == -1)
	{
		line = buffer;
		buffer = NULL;
		return (line);
	}
	line = ft_substr(buffer, 0, index_line + 1);
	buffer = get_after_new_line(buffer, index_line + 1);
	return (line);
}

// int main()
// {
// 	int fd = open("test.txt", O_RDWR);
// 	char *s;
// 	while ((s = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", s);
// 		free(s);
// 	}
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	//system("leaks a.out");
// }
