/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrabet <smrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 10:15:24 by smrabet           #+#    #+#             */
/*   Updated: 2020/08/06 12:49:35 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] >= tab[i + 1])
			return ;
		i++;
	}
	i = 0;
	while (i < size)
	{
		ft_putchar(tab[i] + '0');
		i++;
	}
	if (tab[0] != 10 - size)
		write(1, ", ", 2);
}

void	ft_print_combn(int n)
{
	int	tab[9];
	int	i;

	i = -1;
	if (n > 9 || n < 1)
		return ;
	while (i++ < n)
		tab[i] = i;
	while (tab[0] <= 10 - n)
	{
		ft_print_tab(tab, n);
		tab[n - 1]++;
		i = n - 1;
		while (i >= 0)
		{
			if (tab[i] > 10 - n + i && i != 0)
			{
				tab[i] = 0;
				tab[i - 1]++;
			}
			i--;
		}
	}
}
