/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 05:07:40 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/27 14:08:16 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fct.h"

char	*ft_dupbuf(char *buffer, int *len)
{
	int		i;
	char	*new_buf;
	int		length;

	i = 0;
	if (*len == 0)
		length = 16;
	else
		length = *len;
	new_buf = malloc(sizeof(char) * 16);
	if (!new_buf)
		return (NULL);
	while (i < 16 && i < length)
	{
		new_buf[i] = buffer[i];
		i++;
	}
	return (new_buf);
}

int		ft_cmpbuf(char *last_buffer, char *buffer, int *len)
{
	int	i;
	int length;

	i = 0;
	if (last_buffer == NULL)
		return (0);
	if (*len == 0)
		length = 16;
	else
		length = *len;
	while (i < 16 && i < length)
	{
		if (last_buffer[i] != buffer[i])
			return (0);
		i++;
	}
	return (1);
}

void	ft_print_line(int *offset, char *buffer, int is_c, int *len)
{
	ft_print_offset(*offset, is_c, 0);
	ft_print_buffer_hex(buffer, is_c, len);
	if (is_c)
		ft_print_buffer_char(buffer, len);
	ft_putstr("\n", 1);
	*offset += 16;
}

int		bad_fd(int is_c, int ac, int is_valid)
{
	if (ac == 2 + is_c && !is_valid)
		return (1);
	else
		return (0);
}

void	ft_term_buf(int *len, int ret)
{
	*len = ret;
}
