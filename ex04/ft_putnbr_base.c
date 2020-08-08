/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 14:13:27 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/08 15:29:35 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base == 0 || base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j])
		{
			if (base[j] == base[i] && j != i)
				return (0);
			j++;
		}
		j = i;
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	nb;
	int		size_base;

	nb = nbr;
	size_base = ft_check_base(base);
	if (size_base == 0)
		return ;
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
	}
	if (nb >= size_base)
	{
		ft_putnbr_base(nb / size_base, base);
		ft_putnbr_base(nb % size_base, base);
	}
	else
		ft_putchar(base[nb]);
}
