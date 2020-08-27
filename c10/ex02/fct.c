/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 19:22:04 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/25 19:22:06 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fct.h"

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_atoi(char *str)
{
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb);
}

void	ft_putstr(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

void	ft_save_file_content(char *content, char new_carac, int length)
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		content[i] = content[i + 1];
		i++;
	}
	content[i] = new_carac;
}

void	ft_clear_file_content(char *content, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		content[i] = -1;
		i++;
	}
	content[i] = '\0';
}
