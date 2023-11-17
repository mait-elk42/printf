/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:49:20 by mait-elk          #+#    #+#             */
/*   Updated: 2023/11/17 18:01:30 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	_prt_uint(unsigned int i)
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
	free(res);
	return (len);
}
