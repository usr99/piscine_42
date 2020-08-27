/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 12:37:22 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/27 15:40:42 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fct.h"

void	free_buf(char *buffer, char *other_buffer)
{
	free(buffer);
	free(other_buffer);
}

void	ft_init_buffer(char *buffer, int is_c, int *len)
{
	*len = 0;
	buffer[16] = is_c;
}

void	ft_same_lines(char *last_buffer, char *buffer, int *len, int *offset)
{
	int	ret;

	ft_putstr("*\n", 1);
	*offset += 16;
	while ((ret = read(0, buffer + *len, 16 - *len)) == 16 - *len
			&& ft_cmpbuf(last_buffer, buffer, len) == 1)
		*offset += 16;
	ft_print_line(offset, buffer, buffer[16], len);
}
