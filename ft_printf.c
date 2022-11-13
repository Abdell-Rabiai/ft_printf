/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:22:16 by arabiai           #+#    #+#             */
/*   Updated: 2022/11/13 13:10:45 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"libft/libft.h"
# include"ft_printf.h"
# include <stdarg.h>

#define SPECIFIER "%scdiuxXp"

int ft_strchar(char *string, char c) // look for c if found return it
{
	while (*string)
	{
		if(c == *string)
			return(1);
		string++;
	}
	return (0);
}

void	ft_putnbr_fd_count_base(int n, int fd, int *count, int base)
{
	long	nb;
	long quotient;

	quotient = n;
	while (quotient != 0)
    {
        remainder = quotient % 16;
        if (remainder < 10)
            hexadecimalnum[j++] = 48 + remainder;
        else
            hexadecimalnum[j++] = 55 + remainder;
        quotient = quotient / 16;
    }
	if (n < 0)
	{
		ft_putchar_fd_count('-', fd, count);
		nb *= -1;
	}
	if (nb < 10)
		ft_putchar_fd_count(nb + '0', fd, count);
	else
	{
		ft_putnbr_fd_count(nb / 10, fd, count);
		ft_putnbr_fd_count(nb % 10, fd, count);
	}
}

void ft_convert_format(va_list arg_p, char format_character, int *count)
{
	if(format_character == '%')
		ft_putchar_fd_count(format_character, 1, count);
	else if (format_character == 's')
		ft_putstr_fd_count(va_arg(arg_p, char *), 1, count);
	else if (format_character == 'c')
		ft_putchar_fd_count(va_arg(arg_p, int), 1, count);
	else if (format_character == 'd' || format_character == 'i')
		ft_putnbr_fd_count_base(va_arg(arg_p, int), 1, count);
	else if (format_character == 'u')
		ft_putnbr_fd_uns_count(va_arg(arg_p, int), 1, count);
	else if (format_character == 'x' || format_character == 'X')
		ft_putnbr_fd_count_base(va_arg(arg_p, int), 1, count);
}

int ft_printf(const char *string_format, ...)
{
	va_list arg_p;
	va_start(arg_p, string_format); // va_start makes the atgument pointer arg-p points to the last fixed argument which is in our case 
	int count;
	
	count = 0;
	while (*string_format)
	{
		if (*string_format != '%')
			ft_putchar_fd_count(*string_format,1, &count); // (hello%d, 5)
		else if (*string_format != '\0' && ft_strchar(SPECIFIER, *(string_format + 1)))
		{
		   ft_convert_format(arg_p, *(string_format + 1), &count);
		   string_format++;
		}
		string_format++;  
	}
	return (count);
}

int main()
{
	// printf("[%c]\n",ft_strchar("cspdiuxX%",'d')); 
	int x = 2147483647;
	ft_printf("hello_world {s = %s} : {c = %c} : {d = %d} : {i = %i} : {u = %u} ","HMAYMOU", 'X', x, -2147483648, 4294967295);
	printf("\n\nhello_world {s = %s} : {c = %c} : {d = %d} : {i = %i} : {u = %u} ","HMAYMOU", 'X', x, -2147483648, 4294967295);
	// printf("**%d**\n\n",ft_printf("hello_world {%} ","HMAYMOU"));
	// printf("**%d**\n\n",printf("hello_world {%} ","HMAYMOU")); 
}