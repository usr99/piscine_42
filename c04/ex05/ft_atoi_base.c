/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 15:20:24 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/10 19:38:26 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_base(char *base)
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

int	ft_check_number(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	nb;
	int	nb_minus;
	int	size_base;

	nb = 0;
	nb_minus = 0;
	size_base = ft_check_base(base);
	if (size_base == 0)
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			nb_minus++;
		str++;
	}
	while (ft_check_number(*str, base) != -1)
	{
		nb = nb * size_base + ft_check_number(*str, base);
		str++;
	}
	if (nb_minus % 2 == 1)
		nb *= -1;
	return (nb);
}
