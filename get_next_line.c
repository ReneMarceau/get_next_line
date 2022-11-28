/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 13:54:15 by rmarceau          #+#    #+#             */
/*   Updated: 2022/11/28 12:12:13 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	size_t	total;
	char	*ptr;

	i = 0;
	total = count * size;
	ptr = (void *)malloc(total);
	if (!ptr)
		return (NULL);
	while (i < total)
		ptr[i++] = 0;
	return ((void *)ptr);
}

static char	*ft_read_buff(char *stash, int fd)
{
	char	*buff;
	int		ret;

	buff = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (NULL);
	ret = 1;
	while (!ft_strchr(stash, '\n') && ret != 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buff);
			free(stash);
			return (NULL);
		}
		buff[ret] = '\0';
		stash = ft_strjoin(stash, buff);
	}
	free(buff);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read_buff(stash, fd);
	if (!stash)
		return (NULL);
	line = ft_get_line(stash);
	stash = ft_clean_stash(stash);
	return (line);
}
