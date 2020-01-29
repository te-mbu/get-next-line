/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:57:06 by tembu             #+#    #+#             */
/*   Updated: 2020/01/29 16:24:17 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char				*ft_strjoin(char *s1, char *s2)
{
	long int		len;
	long int		i;
	long int		j;
	char			*string;
	char			s1_new[ft_strlen(s1) + 1];

	i = -1;
	j = -1;
	if (!s1)
		return (ft_strdup(s2));
	len = ft_strlen(s1) + ft_strlen(s2);
	while (s1[++i])
		s1_new[i] = s1[i];
	s1_new[i] = '\0';
	i = -1;
	free(s1);
	string = (char *)malloc(sizeof(char) * (len + 1));
	if (!string)
		return (NULL);
	while (++i < (long int)ft_strlen(s1_new))
		string[i] = s1_new[i];
	while (++j < (long int)ft_strlen(s2))
		string[i + j] = s2[j];
	string[len] = '\0';
	return (string);
}

char				*ft_substr(char *s, unsigned int start, unsigned int len)
{
	char	*string;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	string = (char *)malloc(sizeof(char) * (len + 1));
	if (!string)
		return (NULL);
	while (i < len)
	{
		string[i] = s[start + i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

char				*ft_strdup(char *src)
{
	int		i;
	char	*string;
	int		size;

	i = 0;
	size = ft_strlen(src);
	string = NULL;
	string = (char *)malloc(sizeof(char) * (size + 1));
	if (!string)
		return (NULL);
	while (src[i])
	{
		string[i] = src[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

size_t				ft_strlen(char *s)
{
	size_t i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int					ft_line_until_n(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
