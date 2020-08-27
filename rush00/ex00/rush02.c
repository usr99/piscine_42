/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 20:46:26 by nxu               #+#    #+#             */
/*   Updated: 2020/08/09 20:54:53 by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_printline(int x, char a, char b, char c)
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
	if (x > 0 && y > 0)
	{
		while (i < y)
		{
			if (i == 0)
				ft_printline(x, 'A', 'B', 'A');
			else if (i == y - 1)
				ft_printline(x, 'C', 'B', 'C');
			else
				ft_printline(x, 'B', ' ', 'B');
			i++;
		}
	}
}
