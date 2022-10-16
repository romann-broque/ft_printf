/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_same_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:31:54 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/16 13:05:59 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define SEPARATOR "-----------\n"

void	concat(char **str, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL && strcmp(line, SEPARATOR) != 0)
	{
		*str = ft_strjoin(*str, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

int	main(int ac, char **av)
{
	int		ret_val;
	int		fd;
	char	*output1;
	char	*output2;

	ret_val = EXIT_SUCCESS;
	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		output1 = "";
		output2 = "";
		concat(&output1, fd);
		concat(&output2, fd);
		if (strcmp(output1, output2) != 0)
			ret_val = EXIT_FAILURE;
		free(output1);
		free(output2);
		close(fd);
	}
	return (ret_val);
}
