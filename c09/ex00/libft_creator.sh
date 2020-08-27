# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamartin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/17 18:32:27 by mamartin          #+#    #+#              #
#    Updated: 2020/08/17 22:17:59 by mamartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

gcc -c ft_putchar.c ft_swap.c ft_strlen.c ft_putstr.c ft_strcmp.c
ar -rc libft.a ft_putchar.o ft_swap.o ft_strlen.o ft_putstr.o ft_strcmp.o
