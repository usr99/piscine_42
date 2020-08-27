/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 00:52:25 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/19 18:57:21 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*new_tab;

	i = 0;
	new_tab = malloc(sizeof(*tab) * length);
	if (!new_tab)
		return (NULL);
	while (i < length)
	{
		new_tab[i] = (*f)(tab[i]);
		i++;
	}
	return (new_tab);
}
