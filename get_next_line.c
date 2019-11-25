/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 21:35:47 by othabchi          #+#    #+#             */
/*   Updated: 2019/11/22 18:40:42 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		liberezbakhaw(char **bakhaw)
{
	if (bakhaw)
	{
		free(*bakhaw);
		*bakhaw = NULL;
	}
	return (-1);
}

char	*mygnlread(int fd, int ret, char *buf, char *save)
{
	char		*antileak;

	while (!ft_strchr(save, '\n') && (ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(antileak = ft_strjoin(save, buf)))
			return (NULL);
		free(save);
		save = antileak;
	}
	return (save);
}

int		get_next_line(int fd, char **line)
{
	static char	*save[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			ret;
	int			i;

	i = 0;
	ret = 0;
	if (fd < 0 || fd >= OPEN_MAX || !line || BUFFER_SIZE <= 0
		|| read(fd, buf, 0))
		return (-1);
	if (!save[fd])
		if (!ft_strnew(&save[fd]))
			return (liberezbakhaw(&save[fd]));
	if (!(save[fd] = mygnlread(fd, ret, buf, save[fd])))
		return (liberezbakhaw(&save[fd]));
	while (save[fd][i] != '\n' && save[fd][i] != '\0')
		++i;
	(*line) = save[fd];
	if (!(save[fd] = ft_strdup(save[fd][i] ? save[fd] + i + 1 : save[fd] + i)))
		return (liberezbakhaw(&save[fd]));
	ret = (*line)[i] == '\n' ? 1 : 0;
	if (ret == 0)
		liberezbakhaw(&save[fd]);
	(*line)[i] = '\0';
	return (ret);
}
