/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:19:52 by mait-elk          #+#    #+#             */
/*   Updated: 2023/11/16 22:53:12 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	_prt_char(char c)
{
	return (write(1, &c, 1));
}

int	_prt_str(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		if (_prt_char(s[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int _nsx_ullen(unsigned long ptr)
{
	int	i;

	i = 0;
	while (ptr)
	{
		i++;
		ptr /= 16;
	}
	return (i);
}
int	_prt_pointer(unsigned long ptr)
{
	int		i;
	int		len;
	char	*res;
	char	*base;

	if (ptr == 0)
		return (_prt_str("0x0"));
	base = "0123456789abcdef";
	len = _nsx_ullen(ptr);
	res = malloc(len + 1);
	if (!res)
		return (-1);
	res[len--] = '\0';
	while (ptr)
	{
		res[len] = base[ptr % 16];
		ptr /= 16;
		len--;
	}
	i = _prt_str("0x");
	if (i == -1)
	{
		free (res);
		return (-1);
	}
	len = _prt_str(res);
	if (len == -1)
	{
		free (res);
		return (-1);
	}
	free(res);
	return (len + 2);
}

static int	_handle_this(char c, va_list *vaddress)
{
	if (c == 'c')
		return (_prt_char(va_arg(*vaddress, int)));
	else if (c == 's')
		return (_prt_str(va_arg(*vaddress, char *)));
	else if (c == 'p')
		return (_prt_pointer(va_arg(*vaddress, unsigned long)));
	else if (c == '%')
		return (_prt_char('%'));
	return (0);
}

int	ft_printf(const char	*s, ...)
{
	int ret = 0;
	size_t	length;
	va_list	list;

	length = 0;
	va_start(list, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			ret = _handle_this(*s, &list);
		}
		else
			ret = _prt_char(*s);
		if (ret == -1)
			return (ret);
		length += ret;
		s++;
	}
	va_end(list);
	return (length);
}
