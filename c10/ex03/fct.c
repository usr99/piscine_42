/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 00:57:58 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/27 08:04:32 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fct.h"

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return ((int)(s1[i] - s2[i]));
}

void	ft_putnbr_base(int nb, char *base)
{
	int		size_base;

	size_base = 0;
	while (base[size_base])
		size_base++;
	if (nb >= size_base)
	{
		ft_putnbr_base(nb / size_base, base);
		ft_putnbr_base(nb % size_base, base);
	}
	else
		write(1, base + nb, 1);
}

void	ft_putstr(char *str, int fd)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	write(fd, str, length);
}

void	ft_puterror(char *program_name, char *file_name)
{
	ft_putstr(basename(program_name), 2);
	ft_putstr(": ", 2);
	ft_putstr(file_name, 2);
	ft_putstr(": ", 2);
	ft_putstr(strerror(errno), 2);
	ft_putstr("\n", 2);
}
