/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarre <pcarre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 18:42:13 by pcarre            #+#    #+#             */
/*   Updated: 2015/12/10 19:56:11 by pcarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tools.h"

void	ft_hexdump_c(int fd)
{
	char	buff[BUFF_S];
	char	*tmp;
	int		ret;

	tmp = (char*)malloc(sizeof(*tmp) * (BUFF_S));
	while ((ret = read(fd, buff, BUFF_S)))
	{
		tmp = buff;
		ft_putstr(tmp);
	}

}

int		main(int argc, char **argv)
{
	int		fd;
	int		i;

	i = 1;
	if (ft_strcmp(argv[2], "-C") != 0)
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
