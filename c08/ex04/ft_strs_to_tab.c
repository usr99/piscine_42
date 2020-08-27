/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 01:17:21 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/17 01:17:24 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char				*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	int			length;
	t_stock_str	*stock_str;

	i = 0;
	stock_str = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!stock_str)
		return (NULL);
	while (i < ac)
	{
		length = ft_strlen(av[i]);
		stock_str[i].size = length;
		stock_str[i].str = av[i];
		stock_str[i].copy = malloc(sizeof(**av) * (length + 1));
		ft_strcpy(stock_str[i].copy, av[i]);
		i++;
	}
	stock_str[i].str = 0;
	return (stock_str);
}
