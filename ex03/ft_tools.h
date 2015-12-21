/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarre <pcarre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 18:04:27 by pcarre            #+#    #+#             */
/*   Updated: 2015/12/21 17:05:21 by pcarre           ###   ########.fr       */
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
# define BASE_16 "0123456789abcdef"
# define BASE_10 "0123456789"

void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_putchar(char c);
int		ft_strlen(char *str);
void	ft_putnbr_base(int nbr, char *base);

void	ft_first_coll(int l);
void	ft_put_ascii_code(char *tmp, int i);
void	ft_third_coll(char *tmp);
int		ft_global_size(char *argv);

#endif
