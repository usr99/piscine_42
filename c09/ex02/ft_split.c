/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 23:16:01 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/17 02:21:22 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_find_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_count_words(char *str, char *charset)
{
	int		size;
	int		i;

	size = 0;
	i = 0;
	while (str[i])
	{
		while (ft_find_charset(str[i], charset))
			i++;
		while (!ft_find_charset(str[i], charset) && str[i])
			i++;
		if (!ft_find_charset(str[i - 1], charset))
			size++;
	}
	return (size);
}

void	ft_set_str_array(char **str_array, char *str, char *charset, int size)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (k < size)
	{
		while (ft_find_charset(str[i], charset))
			i++;
		while (!ft_find_charset(str[i + j], charset) && str[i + j])
			j++;
		str_array[k] = malloc(sizeof(**str_array) * (j + 1));
		ft_strncpy(str_array[k], str + i, j);
		i += j;
		j = 0;
		k++;
	}
}

char	**ft_split(char *str, char *charset)
{
	int		size;
	char	**str_array;

	size = ft_count_words(str, charset);
	str_array = malloc(sizeof(*str_array) * (size + 1));
	str_array[size] = 0;
	ft_set_str_array(str_array, str, charset, size);
	return (str_array);
}
