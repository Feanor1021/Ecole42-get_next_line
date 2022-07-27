/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:56:05 by fyardimc          #+#    #+#             */
/*   Updated: 2022/07/25 21:20:56 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*get_till_n(int fd, char *line)
{
	char	*buf;
	int		read_return;

	if (ft_strchr(line, '\n'))
		return (line);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read_return = 1;
	while (!ft_strchr(line, '\n') && read_return != 0)
	{
		read_return = read(fd, buf, BUFFER_SIZE);
		if (read_return == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_return] = '\0';
		line = ft_strjoin(line, buf);
	}
	free(buf);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line[4096];
	char		*ret_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line[fd] = get_till_n(fd, line[fd]);
	if (!line[fd])
		return (NULL);
	ret_line = get_line(line[fd]);
	line[fd] = skip_next_n(line[fd]);
	return (ret_line);
}
