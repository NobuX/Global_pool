/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarre <pcarre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 18:42:13 by pcarre            #+#    #+#             */
/*   Updated: 2015/12/21 17:51:19 by pcarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tools.h"

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

int		ft_main_hexdump_c(
{
	int		fd;
}

int		main(int argc, char **argv)
{
	int		fd;
	int		i;
	int		l;
	int		t;

	l = 0;
	i = 1;
	t = 0;
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
			t += ft_global_size(argv[i]);
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
