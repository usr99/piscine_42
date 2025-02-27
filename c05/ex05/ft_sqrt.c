/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 09:58:52 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/12 09:58:56 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long	i;

	i = 2;
	if (nb == 1)
		return (1);
	if (nb % 2 == 1)
		i = 1;
	while (i <= nb / 2 + 1)
	{
		if (i * i == nb)
			return (i);
		i += 2;
	}
	return (0);
}
