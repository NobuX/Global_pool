/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarre <pcarre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 18:04:27 by pcarre            #+#    #+#             */
/*   Updated: 2015/12/11 00:13:03 by pcarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TOOLS_H
# define FT_TOOLS_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFF_S 16

void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_putchar(char c);
int		ft_strlen(char *str);
void	ft_putnbr_base(int nbr, char *base);

#endif
