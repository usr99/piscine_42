/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 16:20:28 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/23 19:52:07 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_read_file.h"

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

void	ft_read_file(int fd)
{
	int		nb_bytes_read;
	char	buffer[10];

	while ((nb_bytes_read = read(fd, buffer, 10)))
		write(1, buffer, nb_bytes_read);
}
