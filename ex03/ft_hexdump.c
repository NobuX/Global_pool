/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarre <pcarre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 18:42:13 by pcarre            #+#    #+#             */
/*   Updated: 2015/12/18 17:44:50 by pcarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tools.h"

void	ft_hexdump_c(int fd)
{
	char	*tmp;
	int		i;
	int		l;

	l = 0;
	tmp = (char*)malloc(sizeof(char) * (BUFF_S + 1));
	while (read(fd, tmp, BUFF_S) != 0)
	{
		if (l < 16)
			ft_putstr("0000000");
		if (l > 15 && l < 256)
			ft_putstr("000000");
		if (l > 255 && l < 4096)
			ft_putstr("00000");
		if (l > 4095 && l < 65536)
			ft_putstr("0000");
		if (l > 65535 && l < 1048576)
			ft_putstr("000");
		if (l > 1048575 && l < 16777216)
			ft_putstr("00");
		if (l > 16777215 && l < 268435456)
			ft_putchar('0');
		ft_putnbr_base(l, BASE_16);
		ft_putstr("  ");
		i = 0;
		while (tmp[i])
		{
			if (i == 8)
				ft_putchar(' ');
			if (tmp[i] < 16)
				ft_putchar('0');
			ft_putnbr_base(tmp[i], BASE_16);
			ft_putchar(' ');
			i++;
		}
		i = 0;
		while (tmp[i])
		{
			if (tmp[i] == '\t' || tmp[i] == '\n')
				tmp[i] = '.';
			i++;
		}
		ft_putchar(' ');
		ft_putchar('|');
		ft_putstr(tmp);
		tmp[i] = '\0';
		ft_putchar('|');
		ft_putchar('\n');
		l += 16;
	}
	close(fd);
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
//	}
	return (0);
}
