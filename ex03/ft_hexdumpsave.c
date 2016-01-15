/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarre <pcarre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 18:42:13 by pcarre            #+#    #+#             */
/*   Updated: 2016/01/15 16:02:32 by pcarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tools.h"

int		ft_hexdump_c(int fd, int l, int f_s)
{
	char	*tmp;
	char	*end_line;
	int		i;
	
	tmp = (char*)malloc(sizeof(char) * (BUFF_S + 1));
	tmp[BUFF_S] = '\0';
	while ((read(fd, tmp, BUFF_S) != 0) && (l < f_s - (f_s % 16)))
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
		l += 16;
		ft_third_coll(tmp);
	}
	end_line = (char*)malloc(sizeof(char) * ((f_s % 16) + 1));
	end_line[(f_s % 16)] = '\0';
	while ((read(fd, end_line, 1) != 0) && (l < f_s))
	{
		ft_first_coll(l);
		ft_putnbr_base(l, BASE_16);
		ft_putstr("  ");
		i = 0;
		ft_put_ascii_code(end_line, i);
		i = 0;
		while (end_line[i])
		{	
			if (end_line[i] == '\t' || end_line[i] == '\n')
				end_line[i] = '.';
			i++;
		}
		ft_third_coll(end_line);
		l += 16;
	}
	return (l);
}

int		ft_main_hexdump_c(int i, int l, int f_s, int argc, char **argv)
{
	int		fd;
	int		g_error;

	g_error = 0;
	while (++i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd < 0)
		{
			ft_putstr("hexdump: ");
			ft_putstr(argv[i]);
			ft_putstr(": No such file or directory\n");
			g_error++;
		}
		else
		{
			f_s += ft_global_size(argv[i]);
			l = ft_hexdump_c(fd, l, f_s);
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
	}
	return (g_error);
}

int		main(int argc, char **argv)
{
	int		i;
	int		lines;
	int		file_size;
	int		g_error;

	lines = 0;
	i = 1;
	file_size = 0;
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
	g_error = ft_main_hexdump_c(i, lines, file_size, argc, argv);
	if ((g_error + 2) == argc)
	{
		ft_putstr("hexdump: ");
		ft_putstr(argv[(g_error + 1)]);
		ft_putstr(": Bad file descriptor\n");
	}
	return (0);
}
