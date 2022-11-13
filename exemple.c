#include"ft_printf.h"
# include <stdarg.h>

int  f(int a, ...)
{
    va_list ptr;
    va_start(ptr, a);
    int x;

    int i =0;
    int sum = 0;    
    while (i < a )
    {
        x = va_arg(ptr, int);
        sum  += x;
        //printf("{%d}\n", x);
        i++;
    }
    va_end(ptr);
    return sum;
}
//cspdiuxX%

int main()
{
    int *x;
    int a = 42;
    x = &a;
    printf("Hello world %n\n",x);
    printf("%d\n",*x);
}