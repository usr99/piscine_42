/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 19:27:55 by nxu               #+#    #+#             */
/*   Updated: 2020/08/09 19:51:47 by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_line(int x, char a, char b, char c)
{
	int i;

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
	int i;

	i = 0;
	if (y > 0 && x > 0)
	{
		while (i < y)
		{
			if (i == 0 || i == y - 1)
				ft_print_line(x, 'o', '-', 'o');
			else
				ft_print_line(x, '|', ' ', '|');
			i++;
		}
	}
}
