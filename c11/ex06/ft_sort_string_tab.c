/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:50:24 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/20 00:04:56 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return ((s1[i] - s2[i]));
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		j;
	char	*sw;
	int		(*f_cmp)(char *, char *);

	i = 0;
	f_cmp = &ft_strcmp;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if ((*f_cmp)(tab[i], tab[j]) > 0)
			{
				sw = tab[i];
				tab[i] = tab[j];
				tab[j] = sw;
			}
			j++;
		}
		i++;
	}
}
