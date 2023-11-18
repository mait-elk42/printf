/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:19:52 by mait-elk          #+#    #+#             */
/*   Updated: 2023/11/18 12:14:14 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	_handle_this(char c, va_list vaddress)
{
	if (c == 'c')
		return (_prt_char(va_arg(vaddress, int)));
	else if (c == 's')
		return (_prt_str(va_arg(vaddress, char *)));
	else if (c == 'd' || c == 'i')
		return (_prt_int(va_arg(vaddress, int)));
	else if (c == 'u')
		return (_prt_uint(va_arg(vaddress, unsigned int)));
	else if (c == 'x')
		return (_prt_uinthex(va_arg(vaddress, unsigned int), 'x'));
	else if (c == 'X')
		return (_prt_uinthex(va_arg(vaddress, unsigned int), 'X'));
	else if (c == 'p')
		return (_prt_pointer(va_arg(vaddress, unsigned long)));
	else if (c == '%')
		return (_prt_char('%'));
	return (_prt_char(c));
}

int	ft_printf(const char	*s, ...)
{
	int		ret;
	int		length;
	va_list	list;

	length = 0;
	va_start(list, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			ret = _handle_this(*s, list);
		}
		else
			ret = _prt_char(*s);
		if (ret == -1)
		{
			va_end(list);
			return (-1);
		}
		length += ret;
		s++;
	}
	va_end(list);
	return (length);
}
