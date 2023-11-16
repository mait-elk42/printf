/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:19:52 by mait-elk          #+#    #+#             */
/*   Updated: 2023/11/16 15:35:46 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	_handle_this(char c, va_list *vaddress)
{
	if (c == 'c')
		return (_prt_char(va_arg(*vaddress, int)));
	else if (c == 's')
		return (_prt_str(va_arg(*vaddress, char *)));
	else if (c == 'p')
		return (_prt_ptr(va_arg(*vaddress, unsigned long), "0123456789abcdef"));
	else if (c == 'x')
		return (_prt_ptrx(va_arg(*vaddress, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (_prt_ptrx(va_arg(*vaddress, unsigned int), "0123456789ABCDEF"));
	else if (c == 'u')
		return (_nsx_prtluint(va_arg(*vaddress, unsigned int)));
	else if (c == 'd' || c == 'i')
		return (_nsx_prtlint(va_arg(*vaddress, int)));
	else if (c == '%')
		return (_prt_char('%'));
	return (0);
}

int	ft_printf(const char	*s, ...)
{
	size_t	length;
	va_list	list;

	length = 0;
	va_start(list, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			length += _handle_this(*s, &list);
			s++;
		}
		else
			length += _prt_char(*(s++));
	}
	va_end(list);
	return (length);
}
