/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 01:27:03 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/22 19:11:54 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	order;

	i = 0;
	order = 0;
	while (i < length - 1 && order == 0)
	{
		if ((*f)(tab[i], tab[i + 1]) < 0)
			order = -1;
		else if ((*f)(tab[i], tab[i + 1]) > 0)
			order = 1;
		i++;
	}
	i = 0;
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) * order < 0)
			return (0);
		i++;
	}
	return (1);
}
