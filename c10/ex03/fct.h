/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 00:57:31 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/27 15:38:08 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FCT_H
# define FCT_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/errno.h>
# include <fcntl.h>
# include <string.h>
# include <libgen.h>
# include <stdlib.h>

int		ft_strcmp(char *s1, char *s2);
int		ft_cmpbuf(char *last_buffer, char *buffer, int *len);
int		bad_fd(int is_c, int ac, int is_valid);
void	ft_putnbr_base(int nbr, char *base);
void	ft_putstr(char *str, int fd);
void	ft_puterror(char *program_name, char *file_name);
void	ft_print_offset(int offset, int is_c_param, int is_last_line);
void	ft_print_buffer_hex(char *buffer, int is_c_param, int *len);
void	ft_print_buffer_char(char *buffer, int *len);
void	ft_print_last_line(char *buffer, int offset, int is_c_param, int *len);
void	ft_print_line(int *offset, char *buffer, int is_c, int *len);
void	ft_term_buf(int *len, int ret);
void	free_buf(char *buffer, char *other_buffer);
void	ft_init_buffer(char *buffer, int is_c, int *len);
void	ft_same_lines(char *last_buffer, char *buffer, int *len, int *offset);
char	*ft_dupbuf(char *buffer, int *len);

#endif
