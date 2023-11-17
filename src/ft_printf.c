/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:19:52 by mait-elk          #+#    #+#             */
/*   Updated: 2023/11/17 13:29:09 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	_prt_char(char c)
{
	return (write(1, &c, 1));
}

static int	_prt_str(char *s)
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

static int _nsx_ptrlen(unsigned long ptr)
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

static int	_nsx_intlen(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	_nsx_uintlen(unsigned int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	_prt_int(int i)
{
	int		len;
	char	*res;

	len = _nsx_intlen(i);
	if (i == 0)
		return (_prt_char('0'));
	if (i == -2147483648)
		return (_prt_str("-2147483648"));
	res = malloc(len + 1);
	if (!res)
		return (-1);
	if (i < 0)
	{
		i *= -1;
		res[0] = '-';
	}
	res[len--] = '\0';
	while (i)
	{
		res[len--] = (i % 10) + 48;
		i /= 10;
	}
	len = _prt_str(res);
	if (len == -1)
	{
		free(res);
		return (-1);
	}
	free(res);
	return (len);
}

static int	_prt_uint(unsigned int i)
{
	int		len;
	char	*res;

	len = _nsx_uintlen(i);
	if (i == 0)
		return (_prt_char('0'));
	res = malloc(len + 1);
	if (!res)
		return (-1);
	if (i < 0)
	{
		i *= -1;
		res[0] = '-';
	}
	res[len--] = '\0';
	while (i)
	{
		res[len--] = (i % 10) + 48;
		i /= 10;
	}
	len = _prt_str(res);
	if (len == -1)
	{
		free(res);
		return (-1);
	}
	free(res);
	return (len);
}

static int	_prt_pointer(unsigned long ptr)
{
	int		len;
	char	*res;

	if (ptr == 0)
		return (_prt_str("0x0"));
	len = _nsx_ptrlen(ptr);
	res = malloc(len + 1);
	if (!res)
		return (-1);
	res[len--] = '\0';
	while (ptr)
	{
		res[len--] = "0123456789abcdef"[ptr % 16];
		ptr /= 16;
	}
	if (_prt_str("0x") == -1)
	{
		free (res);
		return (-1);
	}
	len = _prt_str(res);
	free(res);
	if (len == -1)
		return (-1);
	return (len + 2);
}

static int	_prt_xhex(unsigned long ptr,	char *base)
{
	int		len;
	char	*res;

	if (ptr == 0)
		return (_prt_str("0"));
	len = _nsx_ptrlen(ptr);
	res = malloc(len + 1);
	if (!res)
		return (-1);
	res[len--] = '\0';
	while (ptr)
	{
		res[len--] = base[ptr % 16];
		ptr /= 16;
	}
	len = _prt_str(res);
	free(res);
	if (len == -1)
		return (-1);
	return (len);
}

static int	_handle_this(char c, va_list *vaddress)
{
	if (c == 'c')
		return (_prt_char(va_arg(*vaddress, int)));
	else if (c == 's')
		return (_prt_str(va_arg(*vaddress, char *)));
	else if (c == 'd' || c == 'i')
		return (_prt_int(va_arg(*vaddress, int)));
	else if (c == 'u')
		return (_prt_uint(va_arg(*vaddress, unsigned int)));
	else if (c == 'x')
		return (_prt_xhex(va_arg(*vaddress, unsigned long), "0123456789abcdef"));
	else if (c == 'X')
		return (_prt_xhex(va_arg(*vaddress, unsigned long), "0123456789ABCDEF"));
	else if (c == 'p')
		return (_prt_pointer(va_arg(*vaddress, unsigned long)));
	else if (c == '%')
		return (_prt_char('%'));
	return ( -1);
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
