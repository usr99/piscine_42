/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 18:23:58 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/26 02:24:22 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	char	*sw;

	i = 0;
	while (tab[i + 1])
	{
		if ((*cmp)(tab[i], tab[i + 1]) > 0)
		{
			sw = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = sw;
			i = 0;
		}
		else
			i++;
	}
}
