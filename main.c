# include "ft_printf.h"
# include "ft_printf_utils.c"

int main()
{
	int i = 214748369876545678;
	int count = 0;
	char *b16 = "0123456789ABCDEF";
	char *b10 = "0123456789";
	printf("\n\n%X\n\n",i);
	ft_putnbr_base(i, 1, &count, b16);
    printf("\n\n");
}