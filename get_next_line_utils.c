/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 11:45:27 by othabchi          #+#    #+#             */
/*   Updated: 2019/11/22 17:16:09 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_strnew(char **my_static)
{
	if (!((*my_static) = (char *)malloc(sizeof(char) * 1)))
	{
		free((*my_static));
		(*my_static) = NULL;
		return (-1);
	}
	(*my_static)[0] = 0;
	return (1);
}

size_t		ft_strlen(const char *str)
{
	size_t i;

	if (!str || !str[0])
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char		*ft_strchr(char *s, char c)
{
	int i;

	if (!s || !s[0])
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == '\0')
		return (NULL);
	return (&s[i]);
}

char		*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*dest;

	if ((!s1) || (!s2) || (!(dest = malloc(sizeof(char) *
		(ft_strlen(s1) + ft_strlen(s2) + 1)))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char		*ft_strdup(const char *str)
{
	char	*res;
	int		i;

	if (!(res = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
