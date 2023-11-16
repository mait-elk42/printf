/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _nsx_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 22:03:46 by mait-elk          #+#    #+#             */
/*   Updated: 2023/11/16 09:46:32 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	_nsx_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	_prt_char(char c)
{
	return (write (1, &c, 1));
}

size_t	_prt_str(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (s[i])
		_prt_char(s[i++]);
	return (i);
}
