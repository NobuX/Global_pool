/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarre <pcarre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 18:42:13 by pcarre            #+#    #+#             */
/*   Updated: 2015/12/10 18:42:21 by pcarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tools.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		i;

	i = 1;
	if (ft_strcmp(argc[2], "-C") != 0)
	{
		while (i++ < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd >= 0)
				ft_hexdump(fd);
			else
				return (0);
		}
		close(fd);
	}
	else
	{
		while (++i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd >= 0)
				ft_hexdump_c(fd);
			else
				return (0);
		}
		close(fd);
	}
	return (0);
}
