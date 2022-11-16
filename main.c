// # include "ft_printf.h"
// # include "ft_printf_utils.c"

// int main()
// {
// 	int i = 214748369876545678;
// 	int count = 0;
// 	char *b16 = "0123456789ABCDEF";
// 	char *b10 = "0123456789";
// 	printf("\n\n%X\n\n",i);
// 	ft_putnbr_base(i, 1, &count, b16);
//     printf("\n\n");
// }


// int main()
// {
// 	// printf("[%c]\n",ft_strchar("cspdiuxX%",'d'));
// 	int x = 2147483647;
// 	unsigned int hex = -983461; // 214748 % 16 = 13421,
// 	ft_printf("\nhello_world {s = %s} : {c = %c} : {d = %d} : {i = %i} : {u = %u} : {x = %x} : {p = %p} ","TABI3A", 'X', x, -2147483647, 429496729, hex, 	NULL);
// 	printf("\n\nhello_world {s = %s} : {c = %c} : {d = %d} : {i = %i} : {u = %u} : {x = %x} : {p = %p} \n\n","TABI3A", 'X', x, -2147483647, 429496729, hex, NULL);
// }