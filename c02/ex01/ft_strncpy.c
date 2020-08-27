/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 18:16:13 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/08 13:54:50 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && (unsigned int)i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while ((unsigned int)i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
