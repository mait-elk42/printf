/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:24:47 by mait-elk          #+#    #+#             */
/*   Updated: 2023/11/16 10:44:39 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	_prt_ptr(unsigned long ptr, char *base)
{
	size_t			i;
	size_t			baselen;
	size_t			max;
	char			*buffer;

	baselen = _nsx_strlen(base);
	max = _nsx_diglen(ptr, baselen);
	i = 0;
	if (ptr == 0)
		return (_prt_str("0x0"));
	buffer = malloc(max + 1);
	buffer[max--] = '\0';
	if (ptr < 0)
		ptr *= -1 * _prt_char('-');
	while (ptr)
	{
		buffer[max--] = base[(ptr % baselen)];
		ptr /= baselen;
		i++;
	}
	ft_printf("0x%s",buffer + max + 1);
	free(buffer);
	return (i + 2);
}
