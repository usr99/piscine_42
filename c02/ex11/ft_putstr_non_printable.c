/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 21:16:45 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/08 13:48:00 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	char	*hex;

	hex = "0123456789abcdef";
	while (*str)
	{
		if (*str < ' ' || *str > '~')
		{
			ft_putchar('\\');
			ft_putchar(hex[*str / 16]);
			ft_putchar(hex[*str % 16]);
		}
		else
			ft_putchar(*str);
		str++;
	}
}
