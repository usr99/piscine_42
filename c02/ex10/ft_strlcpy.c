/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 21:16:23 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/10 20:52:38 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	// copie chaque caractere de src dans dest
	// stop si src est finie
	// stop si size - 1 caracteres ont ete copies
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	// termine la chaine dest avec le caractere de fin de chaine
	dest[i] = '\0';
	// compte la longueur de la chaine src
	i = 0;
	while (src[i] != '\0')
		i++;
	// renvoie la longeur de la chaine src
	return (i);
}
