/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 08:56:01 by mberne            #+#    #+#             */
/*   Updated: 2020/12/15 10:59:31 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>

#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		fd;

	line = NULL;
	fd = open("fichier.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	while (get_next_line(fd, &line) == 1)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	if (close(fd) == -1)
		return (-1);
	return (0);
}
