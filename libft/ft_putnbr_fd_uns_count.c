#include "libft.h"

void	ft_putnbr_fd_uns_count(unsigned int n, int fd, int *count)
{
	if (n < 10)
		ft_putchar_fd_count(n + '0', fd, count);
	else
	{
		ft_putnbr_fd_uns_count(n / 10, fd, count);
		ft_putnbr_fd_uns_count(n % 10, fd, count);
	}
}