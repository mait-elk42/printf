#include "include/ft_printf.h"
#include <stdio.h>
#include <limits.h>

void *test(void *n)
{
	printf("(%ld)", (long)n + 1);
	return (n + 1);
}
int	main()
{
	//
	// int i = 99;
	// unsigned int ii = (unsigned int)&i;
	// unsigned long ii2 = (unsigned long)&i;
	// // int *l = &i;
	// printf("(%u)\n", ii);
	// printf("(%lu) (%p)", ii2 , &i);
	// printf("(%d)", ft_printf(" %x ", 0));
	// printf("^%d^", ft_printf(" %p ", INT_MIN));
	printf("%d", (int)test((void *)INT_MAX));
}
