/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:56:48 by tembu             #+#    #+#             */
/*   Updated: 2020/01/29 16:30:29 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <string.h>

char			*ft_strjoin(char *s1, char *s2);
char			*ft_substr(char *s, unsigned int start, unsigned int len);
size_t			ft_strlen(char *s);
int				get_next_line(int fd, char **line);
char			*ft_strdup(char *src);
int				ft_line_until_n(char *str);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

#endif
