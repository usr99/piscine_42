/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 14:59:44 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/09 18:38:24 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	length_total;
	unsigned int	i;
	unsigned int	j;

	length_total = 0;
	i = 0;
	j = 0;
	while (dest[i] != '\0' && i < size)
		i++;
	while (src[j])
		j++;
	length_total = i + j;
	if (i == size)
		return (length_total);
	j = 0;
	while (src[j] != '\0' && i + j < size - 1)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (length_total);
}
