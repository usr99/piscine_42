/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 16:09:46 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/09 17:55:50 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_line(int x, char a, char b, char c)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (i == 0)
			ft_putchar(a);
		else if (i == x - 1)
			ft_putchar(c);
		else
			ft_putchar(b);
		i++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	i = 0;
	if (y > 0 && x > 0)
	{
		while (i < y)
		{
			if (i > 0 && i < y - 1)
				ft_print_line(x, 'B', ' ', 'B');
			else
				ft_print_line(x, 'A', 'B', 'C');
			i++;
		}
	}
}
