/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 10:45:25 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/13 16:35:53 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (dest[len])
		len++;
	while (src[i])
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (dest);
}

int		ft_strlen_2d(int size, char **strs)
{
	int	i;
	int	j;
	int	length;

	i = 0;
	j = 0;
	length = 0;
	while (i < size)
	{
		while (strs[i][j] != '\0')
			j++;
		length += j;
		j = 0;
		i++;
	}
	return (length);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		length_sep;
	int		nb_char;
	char	*str;

	i = 0;
	length_sep = 0;
	nb_char = ft_strlen_2d(size, strs);
	while (sep[length_sep])
		length_sep++;
	if (size == 0)
	{
		str = malloc(0);
		return (str);
	}
	str = malloc(sizeof(*str) * (nb_char + length_sep * (size - 1)) + 1);
	str[0] = '\0';
	while (i < size)
	{
		ft_strcat(str, strs[i]);
		if (i != size - 1)
			ft_strcat(str, sep);
		i++;
	}
	return (str);
}
