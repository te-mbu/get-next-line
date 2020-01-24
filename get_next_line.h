/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:56:48 by tembu             #+#    #+#             */
/*   Updated: 2020/01/24 15:37:23 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

char			*ft_strjoin(char *s1, char *s2);
char			*ft_substr(char *s, unsigned int start, unsigned int len);
size_t			ft_strlen(char *s);
int				get_next_line(int fd, char **line);
char            *ft_strdup(char *src);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif


#endif