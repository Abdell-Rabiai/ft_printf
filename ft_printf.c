/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:22:16 by arabiai           #+#    #+#             */
/*   Updated: 2022/11/14 19:05:06 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// # include "ft_printf_utils.c"

int	ft_strchar(char *string, char c)
{
	while (*string)
	{
		if (c == *string)
			return (1);
		string++;
	}
	return (0);
}

void	ft_putnbr_base_adress(size_t n, int fd, int *count, char *base)
{
	size_t base_len;

	base_len = ft_strlen(base);
	if (n < base_len)
		ft_putchar_fd_count(base[n % base_len], fd, count);
	else
	{
		ft_putnbr_base_adress(n / base_len, fd, count, base);
		ft_putnbr_base_adress(n % base_len, fd, count, base);
	}
}

void	ft_put_adress_count(void *adresse, int fd, int *count)
{
	size_t	nb; // unsigned long

	if (!adresse)
	{
		ft_putstr_fd_count("0x0", fd, count);
		return ;
	}
	nb = (size_t)adresse;
	ft_putstr_fd_count("0x", fd, count);
	ft_putnbr_base_adress(nb, fd, count, "0123456789abcdef");
}

void	ft_convert_format(va_list arg_p, char format_character, int *count)
{
	if (format_character == '%')
		ft_putchar_fd_count(format_character, 1, count);
	else if (format_character == 's')
		ft_putstr_fd_count(va_arg(arg_p, char *), 1, count);
	else if (format_character == 'c')
		ft_putchar_fd_count(va_arg(arg_p, int), 1, count);
	else if (format_character == 'd' || format_character == 'i')
		ft_putnbr_base(va_arg(arg_p, int), 1, count, "0123456789");
	else if (format_character == 'u')
		ft_putnbr_fd_uns_count(va_arg(arg_p, int), 1, count);
	else if (format_character == 'x')
		ft_putnbr_base(va_arg(arg_p, int), 1, count, "0123456789abcdef");
	else if (format_character == 'X')
		ft_putnbr_base(va_arg(arg_p, int), 1, count, "0123456789ABCDEF");
	else if (format_character == 'p')
		ft_put_adress_count(va_arg(arg_p, void *), 1, count);
}

int	ft_printf(const char *string_format, ...)
{
	va_list	arg_p;
	int		count;

	va_start(arg_p, string_format);
	count = 0;
	while (*string_format)
	{
		if (*string_format != '%')
			ft_putchar_fd_count(*string_format, 1, &count);
		else if (*string_format != '\0'
			&& ft_strchar(SPECIFIER, *(string_format + 1)))
		{
			ft_convert_format(arg_p, *(string_format + 1), &count);
			string_format++;
		}
		string_format++;
	}
	return (count);
}

// int main()
// {
// 	// printf("[%c]\n",ft_strchar("cspdiuxX%",'d'));
// 	int x = 2147483647;
// 	unsigned int hex = -983461; // 214748 % 16 = 13421,
// 	ft_printf("\nhello_world {s = %s} : {c = %c} : {d = %d} : {i = %i} : {u = %u} : {x = %x} : {p = %p} ","TABI3A", 'X', x, -2147483647, 429496729, hex, &x);
// 	printf("\n\nhello_world {s = %s} : {c = %c} : {d = %d} : {i = %i} : {u = %u} : {x = %x} : {p = %p} \n\n","TABI3A", 'X', x, -2147483647, 429496729, hex, &x);
// }