/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 21:24:07 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/27 15:59:51 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fct.h"

void	ft_print_offset(int offset, int is_c_param, int is_last_line)
{
	int	i;
	int	size_offset;

	i = offset;
	size_offset = 1;
	while (i /= 16)
		size_offset++;
	size_offset = 7 - size_offset + is_c_param;
	while (size_offset--)
		ft_putnbr_base(0, "0123456789");
	ft_putnbr_base(offset, "0123456789abcdef");
	if (is_c_param && !is_last_line)
		ft_putstr(" ", 1);
}

void	print_spaces(int i, int is_c_param)
{
	while (i < 16)
	{
		if (i == 8 && is_c_param)
			ft_putstr(" ", 1);
		ft_putstr("   ", 1);
		i++;
	}
}

void	ft_print_buffer_hex(char *buffer, int is_c_param, int *len)
{
	int	i;
	int length;
	int	nbr;

	i = 0;
	if (*len == 0)
		length = 16;
	else
		length = *len;
	while (i < 16 && i < length)
	{
		nbr = buffer[i];
		if (i == 8 && is_c_param)
			ft_putstr(" ", 1);
		ft_putstr(" ", 1);
		if (nbr < 0)
			nbr *= -1;
		if (nbr < 16)
			ft_putstr("0", 1);
		ft_putnbr_base(nbr, "0123456789abcdef");
		i++;
	}
	print_spaces(i, is_c_param);
}

void	ft_print_buffer_char(char *buffer, int *len)
{
	int i;
	int length;

	i = 0;
	ft_putstr("  |", 1);
	if (*len == 0)
		length = 16;
	else
		length = *len;
	while (i < 16 && i < length)
	{
		if (buffer[i] < ' ' || buffer[i] > '~')
			ft_putstr(".", 1);
		else
			write(1, buffer + i, 1);
		i++;
	}
	ft_putstr("|", 1);
}

void	ft_print_last_line(char *buffer, int offset, int is_c_param, int *len)
{
	if (*len != 0 && *len != 16)
	{
		ft_print_offset(offset, is_c_param, 0);
		ft_print_buffer_hex(buffer, is_c_param, len);
		if (is_c_param)
			ft_print_buffer_char(buffer, len);
		ft_putstr("\n", 1);
	}
	offset += *len;
	ft_print_offset(offset, is_c_param, 1);
	ft_putstr("\n", 1);
}
