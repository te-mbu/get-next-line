/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tembu <tembu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:22:00 by tembu             #+#    #+#             */
/*   Updated: 2020/01/24 15:14:08 by tembu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "stdio.h"
#include <limits.h>
/*
int	main(int ac, char **av)
{
	char	*line;
//	char	*gline;
	int		fd;
//	int		gd;
	int		ret;
//	int		gret;

	if (ac < 2)
		return (0);
	line = NULL;
//	gline = NULL;
	fd = open(av[1], O_RDONLY);
//	gd = open(av[2], O_RDONLY);
	printf("OPEN_MAX = %d\n", OPEN_MAX);
	ret = 1;
//	gret = 1;
//	while (ret > 0 || gret > 0)
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		printf("[%d]->%s\n", ret, line);
		if (ret >= 0)
			free(line);
		gret = get_next_line(gd, &gline);
		printf("[%d]->%s\n", gret, gline);
		if (ret >= 0)
			free(gline);
	}
}
*/

int			main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		ret;
	argc = 2;
	fd = open(argv[1], O_RDONLY);

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%d | %s\n", ret, line);
		//printf("ret : %d\n", ret);
		free(line);
	}

	printf("ret : %d\n", ret);
	//	system ("leaks a.out");*/
	/*
	   printf("%d  |  ", get_next_line(fd, &line));
	   printf("%s\n", line);
	   free(line);
	   printf("%d  |  ", get_next_line(fd, &line));
	   printf("%s\n", line);
	   free(line);
	   printf("%d  |  ", get_next_line(fd, &line));
	   printf("%s\n", line);
	   free(line);
	   printf("%d  |  ", get_next_line(fd, &line));
	   printf("%s\n", line);
	   free(line);
	   printf("%d  |  ", get_next_line(fd, &line));
	   printf("%s\n", line);
	   free(line);
	   */

	//	system("leaks a.out");
	close(fd);
	return (0);
}
