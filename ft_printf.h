/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:06:21 by arabiai           #+#    #+#             */
/*   Updated: 2022/11/14 18:57:09 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <string.h>

# define SPECIFIER "%scdiuxXp"

int		ft_printf(const char *string_format, ...);

int     ft_strchar(char *string, char c);
void    ft_putnbr_base_adress(size_t n, int fd, int *count, char *base);
void	ft_put_adress_count(void *adresse, int fd, int *count);
void	ft_convert_format(va_list arg_p, char format_character, int *count);

void	ft_putchar_fd_count(char c, int fd, int *count);
size_t  ft_strlen(char *str);
void	ft_putnbr_base(int n, int fd, int *count, char *base);
void	ft_putnbr_fd_uns_count(unsigned int n, int fd, int *count);
void	ft_putstr_fd_count(char *s, int fd, int *count);

#endif
