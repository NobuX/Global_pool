/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarre <pcarre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 18:42:13 by pcarre            #+#    #+#             */
/*   Updated: 2015/12/10 23:55:18 by pcarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tools.h"

void	ft_hexdump_c(int fd)
{
	char	*tmp;

	tmp = (char*)malloc(sizeof(char) * (BUFF_S));
	while (read(fd, tmp, BUFF_S) != 0)
	{
		if (*tmp == '\t' || *tmp == '\n')
			*tmp = '.';
		ft_putchar('|');
		write(1, tmp, BUFF_S);
		ft_putchar('|');
		ft_putchar('\n');
	}

}

int		main(int argc, char **argv)
{
	int		fd;
	int		i;

	i = 1;
/*	if (ft_strcmp(argv[1], "-C") != 0)
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
	{*/
		while (++i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd >= 0)
				ft_hexdump_c(fd);
			else
				return (0);
		}
		close(fd);
//	}
	return (0);
}
