/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 21:29:24 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/08 13:56:26 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_count_hex_size(int nb)
{
	int	i;

	i = 0;
	if (nb >= 16)
	{
		i = ft_count_hex_size(nb / 16) + 1;
	}
	return (i);
}

void	ft_putnbr_hex(int nb)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nb > 15)
	{
		ft_putnbr_hex(nb / 16);
		ft_putnbr_hex(nb % 16);
	}
	else
		ft_putchar(hex[nb]);
}

void	ft_print_hex_line(char *str, int i, unsigned int size)
{
	int	j;

	j = i - 1;
	while (j++ < i + 15)
	{
		if (j % 2 == 0)
			ft_putchar(' ');
		if ((unsigned int)j < size)
		{
			if (str[j] < 16)
				ft_putchar('0');
			ft_putnbr_hex(str[j]);
		}
		else
			write(1, "  ", 2);
	}
	j = i + 16;
	ft_putchar(' ');
	while (i++ < j && (unsigned int)i < size)
	{
		if (str[i - 1] < 32 || str[i - 1] > 126)
			ft_putchar('.');
		else
			ft_putchar(str[i - 1]);
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	str = addr;
	if (size == 0)
		return (addr);
	while ((unsigned int)i < size)
	{
		j = -1;
		while (j++ < 15 - ft_count_hex_size((int)str + i))
			ft_putchar('0');
		ft_putnbr_hex((int)str + i);
		ft_putchar(':');
		ft_print_hex_line(str, i, size);
		ft_putchar('\n');
		i += 16;
	}
	return (addr);
}
