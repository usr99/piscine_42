/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 18:30:53 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/06 19:52:50 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	is_first_letter;

	i = 0;
	is_first_letter = 1;
	while (str[i] != '\0')
	{
		while ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)
			|| (str[i] >= 48 && str[i] <= 57))
		{
			if (is_first_letter == 1)
			{
				if (str[i] >= 97 && str[i] <= 122)
					str[i] -= 32;
				is_first_letter = 0;
			}
			else if (str[i] >= 65 && str[i] <= 90)
				str[i] += 32;
			i++;
		}
		is_first_letter = 1;
		i++;
	}
	return (str);
}
