/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 20:57:49 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/08 22:00:16 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_solution(int *queens_pos)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		ft_putchar(queens_pos[i] + '0' - 1);
		i++;
	}
	ft_putchar('\n');
}

int		ft_check_queens(int *queens_pos)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 10)
	{
		while (queens_pos[j] && j < 10)
		{
			if (queens_pos[i] == queens_pos[j] && i != j)
				return (0);
			else if (queens_pos[i] - queens_pos[j] == i - j && i != j)
				return (0);
			else if (queens_pos[i] - queens_pos[j] == j - i && i != j)
				return (0);
			j++;
		}
		i++;
		j = i;
	}
	return (1);
}

void	ft_place_queen(int i, int *queens_pos)
{
	queens_pos[i]++;
	if (queens_pos[i] > 10)
	{
		queens_pos[i] = 0;
		return ;
	}
	if (ft_check_queens(queens_pos))
	{
		if (i == 9)
		{
			ft_print_solution(queens_pos);
			queens_pos[10]++;
		}
		else
			ft_place_queen(i + 1, queens_pos);
	}
	ft_place_queen(i, queens_pos);
}

int		ft_ten_queens_puzzle(void)
{
	int	queens_pos[11];
	int	i;

	i = 0;
	while (i < 10)
	{
		queens_pos[i] = 0;
		i++;
	}
	ft_place_queen(0, queens_pos);
	return (queens_pos[10]);
}
