#include "include/ft_printf.h"
#include <stdio.h>

int main()
{
	// int i = 99;
	// unsigned int ii = (unsigned int)&i;
	// unsigned long ii2 = (unsigned long)&i;
	// // int *l = &i;
	// printf("(%u)\n", ii);
	// printf("(%lu) (%p)", ii2 , &i);
	printf("(%d)", ft_printf(" %x ", 0));
}
