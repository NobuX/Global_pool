/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextools_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarre <pcarre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 16:50:05 by pcarre            #+#    #+#             */
/*   Updated: 2015/12/21 17:06:18 by pcarre           ###   ########.fr       */
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

void	ft_third_coll(char *tmp)
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
