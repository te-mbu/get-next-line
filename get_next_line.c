/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:56:22 by tembu             #+#    #+#             */
/*   Updated: 2020/01/29 16:24:22 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char				*ft_line(char *join_buf)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (!join_buf)
		return (NULL);
	while (join_buf[i] && join_buf[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = join_buf[j];
		j++;
	}
	line[i] = '\0';
	return (line);
}

static char				*ft_stock_line(char *join_buf)
{
	unsigned int	i;
	char			*line_to_stock;

	i = 0;
	if (!join_buf)
		return (NULL);
	while (join_buf[i] && join_buf[i] != '\n')
		i++;
	i++;
	line_to_stock = ft_substr(join_buf, i, ft_strlen(join_buf) - i);
	return (line_to_stock);
}

static int				ft_free(char *str_to_free, int returned)
{
	free(str_to_free);
	str_to_free = NULL;
	return (returned);
}

static int				get_next_line2(char *join_buf, char **str, char **line)
{
	if (!(*line = ft_line(join_buf)))
		return (ft_free(join_buf, -1));
	if (!ft_line_until_n(join_buf))
	{
		free(*str);
		*str = NULL;
		return (ft_free(join_buf, 0));
	}
	free(*str);
	if (!(*str = ft_stock_line(join_buf)))
		return (ft_free(join_buf, -1));
	free(join_buf);
	return (1);
}

int						get_next_line(int fd, char **line)
{
	static char		*str;
	int				i;
	char			buf[BUFFER_SIZE + 1];
	char			*join_buf;

	join_buf = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	if (str)
		if (!(join_buf = ft_strdup(str)))
			return (ft_free(join_buf, -1));
	while (!ft_line_until_n(join_buf) && (i = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[i] = '\0';
		if (!(join_buf = ft_strjoin(join_buf, buf)))
			return (ft_free(join_buf, -1));
	}
	if (i < 0)
		return (ft_free(join_buf, -1));
	if (i == 0 && (join_buf == NULL || join_buf[0] == '\0'))
		return (0);
	return (get_next_line2(join_buf, &str, line));
}
