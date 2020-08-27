/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 10:49:03 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/14 00:01:01 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_check_base(char *base);
int		ft_atoi_base(char *str, char *base);

int		ft_count_nb_size(int nb, int size_base)
{
	if (nb < 0)
		nb *= -1;
	if (nb >= size_base)
		return (ft_count_nb_size(nb / size_base, size_base) + 1);
	else
		return (1);
}

void	ft_set_str(char *str, int nb, char *base, int size_base)
{
	int i;

	i = ft_count_nb_size(nb, size_base) - 1;
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
		i++;
	}
	while (i > 0)
	{
		str[i] = base[nb % size_base];
		nb /= size_base;
		i--;
	}
	if (str[i] != '-')
		str[i] = base[nb % size_base];
}

char	*ft_get_str(int nb, int size_base)
{
	int		str_length;
	char	*str;

	str_length = ft_count_nb_size(nb, size_base);
	if (nb < 0)
		str_length++;
	str = malloc(sizeof(*str) * str_length + 1);
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		size_base_from;
	int		size_base_to;
	int		converted_nb;
	char	*str;

	if (!(size_base_from = ft_check_base(base_from)))
		return (NULL);
	if (!(size_base_to = ft_check_base(base_to)))
		return (NULL);
	converted_nb = ft_atoi_base(nbr, base_from);
	str = ft_get_str(converted_nb, size_base_to);
	ft_set_str(str, converted_nb, base_to, size_base_to);
	return (str);
}
