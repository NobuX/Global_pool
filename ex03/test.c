/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarre <pcarre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 14:09:00 by pcarre            #+#    #+#             */
/*   Updated: 2015/12/18 16:37:47 by pcarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tools.h"

void	ft_putchar(char c)
{
		write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}


void	ft_putnbr_base(int nbr, char *base)
{
	if (nbr >= ft_strlen(base))
	{
		ft_putnbr_base(nbr / ft_strlen(base), base);
		ft_putnbr_base(nbr % ft_strlen(base), base);
	}
	else
	{	
		ft_putchar(base[nbr]);
	}
}

/*char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	while (j < i / 2)
	{
		tmp = str[j];
		str[j] = str[i - j - 1];
		str[i - j - 1] = tmp;
		j++;
	}
	return (str);
}


void	ft_count_base(int nbr, char *base)
{
	char	*score;

	score = NULL;
	if (nbr >= ft_strlen(base))
	{
		ft_count_base(nbr / ft_strlen(base), base);
		ft_count_base(nbr % ft_strlen(base), base);
	}
	else
		score = base[nbr];
	score = ft_strrev(score);
	while (strlen(score) > 8)
		score *= 10;
	score = ft_strrev(score);
	ft_putstr(score);
}*/

int		main()
{
	unsigned int		i;

	i = 0;
	while (i <= 42)
	{
		ft_putnbr_base(i, BASE_16);
		ft_putchar('\n');
		i += 16;
	}
//	ft_count_base(16, char *base);
//	ft_putchar('\n');
	return (0);
}
