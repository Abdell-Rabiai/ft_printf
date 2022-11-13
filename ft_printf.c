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

# include"ft_printf.h"

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

void ft_put0x_hexa_count(unsigned int nb, int fd, int *count)
{
	ft_putstr_fd_count("0x", fd, count);
	ft_putnbr_fd_hexa_count(nb, fd, count, 'x');
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
		ft_putnbr_fd_count(va_arg(arg_p, int), 1, count);
	else if (format_character == 'u')
		ft_putnbr_fd_uns_count(va_arg(arg_p, int), 1, count);
	else if (format_character == 'x' || format_character == 'X')
		ft_putnbr_fd_hexa_count(va_arg(arg_p, int), 1, count, format_character);
	else if (format_character == 'p')
		ft_put0x_hexa_count(va_arg(arg_p, int), 1, count);
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

// int main()
// {
// 	// printf("[%c]\n",ft_strchar("cspdiuxX%",'d')); 
// 	int x = 2147483647;
// 	unsigned int hex = 4294967295; // 214748 % 16 = 13421, 
// 	ft_printf("\nhello_world {s = %s} : {c = %c} : {d = %d} : {i = %i} : {u = %u} : {x = %x} : {p = %p} ","TABI3A", 'X', x, -214748364, 429496729, hex, 21465);
// 	printf("\n\nhello_world {s = %s} : {c = %c} : {d = %d} : {i = %i} : {u = %u} : {x = %x} : {p = %p} \n\n","TABI3A", 'X', x, -214748364, 429496729, hex, 21465);
// 	ft_printf("%p\n\n",&x);
// 	printf("%p\n\n",&x);
// 	// printf("**%d**\n\n",ft_printf("hello_world {%} ","HMAYMOU"));
// 	// printf("**%d**\n\n",printf("hello_world {%} ","HMAYMOU")); 
// }