/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_same_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:31:54 by rbroque           #+#    #+#             */
/*   Updated: 2022/10/14 23:11:22 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int	main(int ac, char **av)
{
	size_t	i;
	int		ret_val;
	int		fd;
	char	*last_line;
	char	*curr_line;

	ret_val = EXIT_SUCCESS;
	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		i = 1;
		last_line = NULL;
		curr_line = get_next_line(fd);
		while (curr_line != NULL)
		{
			if (i == 1)
			{
				free(last_line);
				last_line = strdup(curr_line);
			}
			else if (i == 2)
			{
				if (strcmp(curr_line, last_line) != 0)
				{
					ret_val = EXIT_FAILURE;
					break ;
				}
			}
			else			
				i = 0;
			free(curr_line);
			curr_line = get_next_line(fd);
			++i;
		}
		free(last_line);
		free(curr_line);
		close(fd);
	}
	return (ret_val);
}
