/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 22:46:40 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/10 16:42:11 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return ((s1[i] - s2[i]));
}

void	ft_sort_params(int nb_param, char **param)
{
	int		i;
	int		j;
	char	*sw;

	i = 1;
	j = 2;
	while (i < nb_param)
	{
		while (j < nb_param)
		{
			if (ft_strcmp(param[i], param[j]) > 0)
			{
				sw = param[i];
				param[i] = param[j];
				param[j] = sw;
			}
			j++;
		}
		i++;
		j = i + 1;
	}
}

int		main(int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	ft_sort_params(argc, argv);
	while (i < argc)
	{
		while (argv[i][j] != '\0')
		{
			ft_putchar(argv[i][j]);
			j++;
		}
		j = 0;
		i++;
		ft_putchar('\n');
	}
	return (0);
}
