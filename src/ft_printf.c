/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:19:52 by mait-elk          #+#    #+#             */
/*   Updated: 2023/11/16 10:47:05 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	_handle_thispls(char c, va_list *vaddress)
{
	size_t l;

	l = 0;
	if (c == 'c')
		l += _prt_char(va_arg(*vaddress, int));
	else if (c == 's')
		l += _prt_str(va_arg(*vaddress, char *));
	else if (c == 'p')
		l += _prt_ptr(va_arg(*vaddress, unsigned long), "0123456789abcdef");
	else
		l += _prt_char('%');
	return (l);
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
			length += _handle_thispls(*(s++), &list);
		}
		else
		{
			length++;
			_prt_char(*(s++));
		}
	}
	va_end(list);
	return (length);
}
