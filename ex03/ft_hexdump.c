/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarre <pcarre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 18:42:13 by pcarre            #+#    #+#             */
/*   Updated: 2015/12/19 00:32:02 by pcarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tools.h"

void	ft_first_coll(int l)
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
}

void	ft_put_ascii_code(char *tmp, int i)
{
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
}

void	ft_third_coll(char* tmp)
{
	ft_putchar(' ');
	ft_putchar('|');
	ft_putstr(tmp);
	ft_putchar('|');
	ft_putchar('\n');
}

int		ft_global_size(char *argv)
{
	int		fd;
	int		size;
	char	buf;

	fd = open(argv, O_RDONLY);
	size = 0;
	while (read(fd, &buf, 1))
		size++;
	close(fd);
	return (size);
}

int		ft_hexdump_c(int fd, int l, int t)
{
	char	*tmp;
	int		i;

	tmp = (char*)malloc(sizeof(char) * (BUFF_S + 1));
	tmp[BUFF_S] = '\0';
	while ((read(fd, tmp, BUFF_S) != 0) && (l < t - (t % 16)))
	{
			ft_first_coll(l);
			ft_putnbr_base(l, BASE_16);
			ft_putstr("  ");
			i = 0;
			ft_put_ascii_code(tmp, i);
			i = 0;
			while (tmp[i])
			{
				if (tmp[i] == '\t' || tmp[i] == '\n')
					tmp[i] = '.';
				i++;
			}
			ft_third_coll(tmp);
			l += 16;
	}
	return (l);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		i;
	int		l;
	int		t;

	l = 0;
	i = 1;
	t = ft_global_size(argv[i]);
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
			{
				l = ft_hexdump_c(fd, l, t);
				close(fd);
				if (!(argv[i + 1]))
				{
					i = 1;
					l = 0;
					while (++i < argc)
					{
						l += ft_global_size(argv[i]);
						if (!(argv[i + 1]))
						{
							ft_first_coll(l);
							ft_putnbr_base(l, BASE_16);
							ft_putchar('\n');
						}
					}
				}
			}
			else
				return (0);
		}
//	}
	return (0);
}
